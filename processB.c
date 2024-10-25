#include <sys/stat.h>
#include <stdio.h>
#include <sys/file.h>
#include <unistd.h>
#include <fcntl.h>
int main(void){
    int fd;
    char text[16] = {0};
    int numbWrite;
    int numFlock1;
    int numFlock2;
    ssize_t numbRead;

    fd = open("text.txt", O_RDWR);
    if(fd == -1){
        printf("create file failed\n");
        return 0;
    }else{
        printf("Create file successful\n");
    }

    numFlock1 = flock(fd,LOCK_EX|LOCK_NB);
    if(numFlock1 == -1){
        printf("get write lock failed\n");
    }

    numFlock2 = flock(fd,LOCK_SH|LOCK_NB);
    if(numFlock2 == -1 ){
        printf("get read lock failed\n" );
    }else {
        printf("set read lock successful\n");
        numbRead = read(fd, text, sizeof(text)-1);
        if(numbRead == -1){
            printf("read file failed\n");
            return 0;
        }else{
            printf("%s\n",text);
        }
    }

    
    close(fd);
    return 0;



}