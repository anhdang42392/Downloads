#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define THRESHOLD   10

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; // cai dat khoa mutex cho thread
int counter; // critical section <=> global resource

typedef struct {
    char name[30];
    char msg[30];
} thread_args_t;

static void *handle_th1(void *args)  // ham cho thread so 1
{
    thread_args_t *thr = (thread_args_t *)args;
    //khoa mutex thread 
    pthread_mutex_lock(&lock);
    printf("hello %s !\n", thr->name);

    while (counter < THRESHOLD) {
        counter += 1;
	    printf("Counter: %d\n", counter);
        sleep(1);
    }

    printf("thread1 handler, counter = %d\n", counter);
    pthread_mutex_unlock(&lock);
// mo khoa mutex thread
    pthread_exit(NULL); // exit

}

int main(int argc, char const *argv[])
{
    /* code */
    int ret;
    thread_args_t thr;
    pthread_t thread_id1, thread_id2;

    memset(&thr, 0x0, sizeof(thread_args_t));
    strncpy(thr.name, "thonv12", sizeof(thr.name));

    if (ret = pthread_create(&thread_id1, NULL, &handle_th1, &thr)) {
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }

    printf("Checking: \n");
    // su dung phuong phap pooling de kiem tra counter bang threshold chua
    while (1) {
        if(counter == THRESHOLD) {
           printf("Global variable counter = %d.\n", counter);
           break;
        }
    }
    
    // used to block for the end of a thread and release
    pthread_join(thread_id1,NULL);  

    return 0;
}
