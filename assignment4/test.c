#include <stdio.h>
#include <pthread.h>
#include <string.h>

#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    char birthdate[11]; // dd/mm/yyyy
    char hometown[MAX_NAME];
} Student;


pthread_mutex_t mutex;
pthread_cond_t cond;
FILE *fp;
Student student;


void *input_data(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        printf("Nhap thong tin sinh vien:\n");
        scanf("%s %s %s", student.name, student.birthdate, student.hometown);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
}

void *write_file(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond, &mutex);
        fprintf(fp, "%s %s %s\n", student.name, student.birthdate, student.hometown);
        pthread_mutex_unlock(&mutex);
    }
}

void *read_file(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond, &mutex);
        printf("Thong tin sinh vien vua ghi:\n");
        printf("%s %s %s\n", student.name, student.birthdate, student.hometown);
        pthread_mutex_unlock(&mutex);
    }
}


int main() {
    pthread_t tid1, tid2, tid3;
    fp = fopen("thongtinsinhvien.txt", "w");

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&tid1, NULL, input_data, NULL);
    pthread_create(&tid2, NULL, write_file, NULL);
    pthread_create(&tid3, NULL, read_file, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);

    fclose(fp);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}