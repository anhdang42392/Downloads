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
pthread_cond_t cond3 = PTHREAD_COND_INITIALIZER;
int counter; // critical section <=> global resource

int fd;
    int numb_read, numb_write;
    char buf1[20] = "helloworld \n";
char data[100] = {0};
typedef struct {
    char name[30];
    char msg[30];
    char birthday[10];
    char quequan[30];
} thread_args_t;




// ham cua thread so 1
static void *handle_th1(void *args) 
{
    thread_args_t *thr = (thread_args_t *)args;

    pthread_mutex_lock(&lock); //khoa mutex thread dang thuc hien

    // pthread_cond_wait(&cond3, &lock);
    printf("Enter full name: ");//
    // scanf("%s",thr->name);
    fgets(thr->name,30,stdin);
    printf("Enter Birtday: ");
    // scanf("%s", thr->birthday);
    fgets(thr->birthday,10,stdin);
    printf("Enter hometown: "); 
    // scanf("%s", thr->quequan);
    fgets(thr->quequan,30,stdin);
    
    sprintf(data,"%s  %s  %s \n", thr->name, thr->birthday, thr->quequan);
    pthread_cond_signal(&cond); // gui tin hieu cho thread khac biet duoc qua trinh ket thuc

    pthread_mutex_unlock(&lock); // mo khoa mutex thread de thread khac su dung khoa mutex nay

    pthread_exit(NULL); // exit or return;

}



// ham cua thread so 2
static void *handle_th2(void *args) // ham cho thread ID so 2
{
    thread_args_t *thr = (thread_args_t *)args;
    pthread_mutex_lock(&lock); // thread so 2 dung mutex lock de ko cho thread so 1 truy cap vao counter
    
        // ready in advance when pthread_cond_signal() is called
    pthread_cond_wait(&cond, &lock);

    write(fd,data,strlen(data));

    // pthread_cond_signal(&cond2);

    pthread_mutex_unlock(&lock); //  thread so 2 tra lai mutex lock

    pthread_exit(NULL); // exit
}




int main(int argc, char const *argv[])
{
    /* code */
    int ret;
    thread_args_t thr;
    pthread_t thread_id1, thread_id2;


    fd = open("thongtinsinhvien.txt", O_RDWR | O_CREAT, 0667);
    if (-1 == fd)
    {
        printf("open() thongtinsinhvien.txt failed\n");
    }
    numb_write = write(fd, buf1, strlen(buf1));

    memset(&thr, 0x0, sizeof(thread_args_t)); // khoi tao gia tri ban dau cho bien struct thr
    // strncpy(thr.name, "thonv12", sizeof(thr.name));

    if (ret = pthread_create(&thread_id1, NULL, &handle_th1, &thr)) {
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }

    if (ret = pthread_create(&thread_id2, NULL, &handle_th2, &thr)) { // tao thread so 2
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }

    
    


    pthread_mutex_lock(&lock);
        // ready in advance when pthread_cond_signal() is called
        pthread_cond_wait(&cond, &lock);
        printf("%s\n",data);

        // pthread_cond_signal(&cond3);
    pthread_mutex_unlock(&lock);
    
    // used to block for the end of a thread and release
    pthread_join(thread_id1,NULL); 
    pthread_join(thread_id2,NULL);
    return 0;
}