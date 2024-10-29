#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    char name[100];
    char dob[20];    
    char address[100]; 
} Student;

Student student;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;  
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;  
int ready_to_write = 0;
int ready_to_print = 0;


void* input_student(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);

        printf("Nhập họ tên: ");
        fgets(student.name, sizeof(student.name), stdin);
        student.name[strcspn(student.name, "\n")] = '\0'; 

        printf("Nhập ngày sinh (dd/mm/yyyy): ");
        fgets(student.dob, sizeof(student.dob), stdin);
        student.dob[strcspn(student.dob, "\n")] = '\0';  

        printf("Nhập quê quán: ");
        fgets(student.address, sizeof(student.address), stdin);
        student.address[strcspn(student.address, "\n")] = '\0';  

        ready_to_write = 1;  
        pthread_cond_signal(&cond2); 
        pthread_cond_wait(&cond1, &mutex);  

        pthread_mutex_unlock(&mutex);
    }
    return NULL; // pthread_exit(NULL);
}



void* write_to_file(void* arg) {
    FILE* file;
    while (1) {
        pthread_mutex_lock(&mutex);

        while (!ready_to_write) {
            pthread_cond_wait(&cond2, &mutex);
        }

        file = fopen("thongtinsinhvien.txt", "a");
        if (file == NULL) {
            perror("Failed to open file");
            pthread_mutex_unlock(&mutex);
            continue;
        }
        fprintf(file, "%s\n%s\n%s\n", student.name, student.dob, student.address);
        fclose(file);

        ready_to_print = 1;  
        ready_to_write = 0;
        pthread_cond_signal(&cond2);  

        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}



void* print_student(void* arg) {
    char line[256];
    FILE* file;
    while (1) {
        pthread_mutex_lock(&mutex);

        while (!ready_to_print) {
            pthread_cond_wait(&cond2, &mutex);
        }

        file = fopen("thongtinsinhvien.txt", "r");
        if (file == NULL) {
            perror("Failed to open file");
            pthread_mutex_unlock(&mutex);
            continue;
        }
        printf("\n===== Dữ liệu sinh viên =====\n");
        while (fgets(line, sizeof(line), file) != NULL) {
            printf("%s", line);
        }
        fclose(file);

        printf("\n=============================\n");

        ready_to_print = 0;
        pthread_cond_signal(&cond1);  
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}



int main() {
    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, input_student, NULL);
    pthread_create(&t2, NULL, write_to_file, NULL);
    pthread_create(&t3, NULL, print_student, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}
