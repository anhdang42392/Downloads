#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <fcntl.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER; // bien dieu kien de bao cho thread khac biet doi den khi thread nay ket thuc
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;
// pthread_cond_t cond3 = PTHREAD_COND_INITIALIZER;
int counter; // critical section <=> global resource

int fd;
int numb_read, numb_write;
char buf1[20] = "Data of pupils \n";
char buff2[200];

typedef struct
{
    char name[30];
    char msg[30];
    char birthday[10];
    char quequan[30];
} thread_args_t;

int check_to_write = 0;
int check_to_print = 0;

// ham cua thread so 1
static void *handle_th1(void *args)
{
    thread_args_t *thr = (thread_args_t *)args;
    while (1)
    {

        pthread_mutex_lock(&lock); // khoa mutex thread dang thuc hien

        printf("Enter full name: "); //
        fgets(thr->name, 30, stdin);
        int index1 = strcspn(thr->name, "\n");
        thr->name[index1] = '\0';
        fflush(stdin);

        printf("Enter Birtday (dd/mm): ");
        fgets(thr->birthday, 10, stdin);
        int index = strcspn(thr->birthday, "\n");
        thr->birthday[index] = '\0';
        fflush(stdin);

        printf("Enter hometown: ");
        fgets(thr->quequan, 30, stdin);
        index = strcspn(thr->quequan, "\n");
        thr->quequan[index] = '\0';
        fflush(stdin);

        check_to_write = 1;
        pthread_cond_signal(&cond2);
        pthread_cond_wait(&cond, &lock);
        
        pthread_mutex_unlock(&lock); // mo khoa mutex thread de thread khac su dung khoa mutex nay
    }
    pthread_exit(NULL); // exit or return;
}

// ham cua thread so 2
static void *handle_th2(void *args) // ham cho thread ID so 2
{
    thread_args_t *thr = (thread_args_t *)args;
    while (1)
    {

        pthread_mutex_lock(&lock); // thread so 2 dung mutex lock de ko cho thread so 1 truy cap vao counter

        while (check_to_write == 0)
        {
            pthread_cond_wait(&cond2, &lock);
        }

        fd = open("thongtinsinhvien.txt", O_APPEND, 0667);
        if (-1 == fd)
        {
            printf("open() thongtinsinhvien.txt failed\n");
        }
        // ready in advance when pthread_cond_signal() is called
        write(fd, thr->name, strlen(thr->name));
        write(fd, "\t\t", strlen("\t\t"));
        write(fd, thr->birthday, strlen(thr->birthday));
        write(fd, "\t\t", strlen("\t\t"));
        write(fd, thr->quequan, strlen(thr->quequan));
        write(fd, "\n", strlen("\n"));
        // close(fd);

        check_to_write = 0;
        check_to_print = 1;
        pthread_cond_signal(&cond2);

        pthread_mutex_unlock(&lock); //  thread so 2 tra lai mutex lock
    }
    pthread_exit(NULL); // exit
}

static void *handle_th3(void *args) // ham cho thread ID so 2
{
    thread_args_t *thr = (thread_args_t *)args;
    while (1)
    {
        pthread_mutex_lock(&lock);

        while (check_to_print == 0)
        {
            pthread_cond_wait(&cond2, &lock);
        }

        fd = open("thongtinsinhvien.txt", O_APPEND);
        numb_read = read(fd, &buff2, sizeof(buff2) - 1);
        if (numb_read == -1)
        {
            printf("read failed\n");
        }

        printf("New student: \n");
        // ready in advance when pthread_cond_signal() is called
        printf("%s\t\t", thr->name);
        printf("%s\t\t", thr->birthday);
        printf("%s\n", thr->quequan);
        printf("Next student\n");
        // printf("Data of pupils\n");
        // printf("%s",buff2);
        check_to_print = 0;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL); // exit
}

int main(int argc, char const *argv[])
{
    /* code */
    int ret;
    thread_args_t thr;
    pthread_t thread_id1, thread_id2, thread_id3;

    memset(&thr, 0x0, sizeof(thread_args_t)); // khoi tao gia tri ban dau cho bien struct thr

    if (ret = pthread_create(&thread_id1, NULL, &handle_th1, &thr))
    {
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }

    if (ret = pthread_create(&thread_id2, NULL, &handle_th2, &thr))
    { // tao thread so 2
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }

    if (ret = pthread_create(&thread_id3, NULL, &handle_th3, &thr))
    { // tao thread so 2
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }

    // used to block for the end of a thread and release
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    pthread_join(thread_id3, NULL);
    return 0;
}