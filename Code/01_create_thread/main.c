#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_t thread_id1, thread_id2; // tao thread ID cho moi thread 

typedef struct {
    char name[30];
    char msg[30];
} thr_data_t;

static void *thr_handle(void *args) 
{
    pthread_t tid = pthread_self(); // xac dinh thread ID hien tai dang thuc hien
    thr_data_t *data = (thr_data_t *)args;

    if (pthread_equal(tid, thread_id1)) { // so sanh thread ID de check thread ID dang chay 
        // Thread 1
        printf("I'm thread_id1\n\n");
        while(1);

    } else {
        // Thread 2
        printf("I'm thread_id2\n");
        printf("Hello %s, welcome to join %s\n", data->name, data->msg);
        while(1);
    }
}


int main(int argc, char const *argv[])
{
    /* code */
    int ret;
    thr_data_t data = {0};

    strncpy(data.name, "ThoNV12", sizeof(data.name));                 
    strncpy(data.msg, "thread programming\n", sizeof(data.msg));
    // tien hanh tao thread

    // Thread 1
    if (ret = pthread_create(&thread_id1, NULL, &thr_handle, NULL)) { //neu ham pthread_create = 0 thi tao thanh cong con khac 0 thi bi loi~
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }

    sleep(2);

    //Thread 2
    if (ret = pthread_create(&thread_id2, NULL, &thr_handle, &data)) { // cung tuong tu tao mot thread khac voi thread ID khac
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }
    sleep(5);

    return 0;
}
