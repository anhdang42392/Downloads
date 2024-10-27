#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

// khai bao tinh tao ra 2 mutex lock cho 2 thread
pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER; 
// pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  cond = PTHREAD_COND_INITIALIZER;
int counter = 2; // shared variable/shared resources/global variable

typedef struct {
    char name[30];
    char msg[30];
} thread_args_t;

//Thread 1
static void *handle_th1(void *args) // ham cho thread ID so 1
{   

    thread_args_t *thr = (thread_args_t *)args;
    //sleep(1);

    pthread_mutex_lock(&lock1); // tien hanh lock thread so 1 de thread so 2 khong truy  cap dc vao bien counter
    // critical section 
    printf("hello %s !\n", thr->name);
    printf("thread1 handler, counter: %d\n", ++counter);
    // sleep(5);


    pthread_mutex_unlock(&lock1); // tien hanh unlock thread so 1 de tra mutex lock  cho thread so 2 co the truy cap duoc vao bien counter

    pthread_exit(NULL); // exit

}
// Thread 2
static void *handle_th2(void *args) // ham cho thread ID so 2
{
    pthread_mutex_lock(&lock1); // thread so 2 dung mutex lock de ko cho thread so 1 truy cap vao counter
    
    // while(1){
    printf("thread2 handler, counter: %d\n", ++counter);

    // }
    pthread_mutex_unlock(&lock1); //  thread so 2 tra lai mutex lock

    pthread_exit(NULL); // exit
}

int main(int argc, char const *argv[])
{
    /* code */
    int ret;
    thread_args_t thr;
    pthread_t thread_id1, thread_id2;

    memset(&thr, 0x0, sizeof(thread_args_t)); //khoi tao gia tri ban dau cho bien thr
    strncpy(thr.name, "phonglt9", sizeof(thr.name));

    if (ret = pthread_create(&thread_id1, NULL, &handle_th1, &thr)) { //tao thread so 1
        printf("pthread_create() error number=%d\n", ret); 
        return -1;
    }

    if (ret = pthread_create(&thread_id2, NULL, &handle_th2, NULL)) { // tao thread so 2
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }
    sleep(5);
    // used to block for the end of a thread and release
    pthread_join(thread_id1,NULL);  //nhan gia tri tra ve khi thread ket thuc tuong tu nhu waitpid
    pthread_join(thread_id2,NULL);

    return 0;
}
