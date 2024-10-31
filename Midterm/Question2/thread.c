#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <fcntl.h>

int fd;
int numb_read, numb_write;
char buf1[20] = "Data write\n";

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

pthread_mutex_t file_mutex;  // Declare mutex
int counter = 2;
int check_to_write = 0;
char data1[50] = {0};
char data2[50] = {0};


#define FILE_NAME "output.txt"
// Thread 1
void* write_to_file(void* arg) {
    FILE *file;
    char* thread_name = (char*)arg;

    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(&file_mutex);  // Lock mutex before writing to the file

        file = fopen(FILE_NAME, "a");
        if (file == NULL) {
            perror("Error opening file");
            pthread_mutex_unlock(&file_mutex);  // Unlock mutex if there is an error
            return NULL;
        }

        fprintf(file, "%s is writing line %d\n", thread_name, i + 1);
        printf("%s wrote line %d to file\n", thread_name, i + 1);
        fclose(file);

        pthread_mutex_unlock(&file_mutex);  // Unlock mutex after writing
        sleep(1);  // Sleep for 1 second to simulate writing
    }

    return NULL;
}

// Thread 2

int main(int argc, char const *argv[])
{
    /* code */
    int ret;

    pthread_mutex_init(&file_mutex, NULL);

    pthread_t thread_id1, thread_id2;

    if (ret = pthread_create(&thread_id1, NULL, &write_to_file, NULL))
    {
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }

    if (ret = pthread_create(&thread_id2, NULL, &write_to_file, NULL))
    {
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }

    pthread_mutex_destroy(&file_mutex);
    pthread_join(thread_id1, NULL); // nhan gia tri tra ve khi thread ket thuc tuong tu nhu waitpid
    pthread_join(thread_id2, NULL);

    return 0;
}
