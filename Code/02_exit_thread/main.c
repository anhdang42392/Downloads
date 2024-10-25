#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_t thread_id1, thread_id2, thread_id3; // khai  bao thread ID cho 3 thread

typedef struct {
    char name[30];
    char msg[30];
} thr_data_t;

static void *thr_handle1(void *args)  // ham cho thread ID so 1
{
    thr_data_t *thr = (thr_data_t *)args;
    sleep(1);
    printf("hello %s !\n", thr->name);
    printf("thread1 handler\n");
    pthread_exit(NULL); // Thread nay ket thuc khi goi ham pthread_exit 
    // gia tri tra ve cua  pthread_exit la 0 thi ket thuc thanh cong , khac 0 la ket thuc bi loi~
}

static void *thr_handle2(void *args) // ham cho thread ID so 2
{
    sleep(5);
    pthread_exit(NULL); // exit khoi thread ID
    //exit(1); // khi goi exit o bat ky ham nao ke ca main thread(ham main) thi tat ca thread con lai se ket thuc
    while (1) {
        printf("thread2 handler\n"); 
        sleep(1);
    };
}


static void *thr_handle3(void *args) // ham cho thread ID so 3
{
    pthread_detach(pthread_self());
    //sleep(2);
    //  pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    /* code */
    int ret, counter = 0;
    int retval;
    thr_data_t data = {0};

    strncpy(data.name, "ThoNV12", sizeof(data.name));                 
    strncpy(data.msg, "Posix thread programming\n", sizeof(data.msg));

    // tien hanh tao thread 
    if (ret = pthread_create(&thread_id1, NULL, &thr_handle1, &data)) { // tao thread ID 1
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }

    if (ret = pthread_create(&thread_id2, NULL, &thr_handle2, NULL)) { // tao thread ID 2
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }

    sleep(5);
    //pthread_cancel(thread_id2); // gui yeu cau ket thuc toi mot thread cu the (0 la thanh cong, khac 0 la that bai)
    //pthread_join(thread_id2, NULL); //  doi cho den khi thread ID 2 ket thuc thi tra ve gia tri ket thuc tu pthread_exit trong thread ID 2 tuong tu nhu waitpid
    //printf("thread_id2 termination\n"); 
    //while(1){}
    while (1) {
        if (ret = pthread_create(&thread_id3, NULL, &thr_handle3, NULL)) { // tao thread ID 3
            printf("pthread_create() error number=%d\n", ret); 
            break;
        }
        counter++;
        // pthread_join(thread_id3, NULL);

        if (counter%1000 == 0) {
            printf("Thread created: %d\n", counter);
        }
    }   


    return 0;
}
