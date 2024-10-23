#include <sys/stat.h>
#include <stdio.h>
#include <sys/file.h>
#include <unistd.h>
#include <fcntl.h>
int main(void){
    int fd;
    char text[16] = {0};
    int numbWrite;
    int numFlock;
    sprintf(text,"hello world\n");
    fd = open("text.txt", O_RDWR|O_CREAT, 0777);
    if(fd == -1){
        printf("create file failed\n");
        return 0;   
    }else{
        printf("Create file successful\n");
    }


    numbWrite = write(fd, text, sizeof(text)-1);
    if(numbWrite ==-1){
        printf("Write failed\n");
        return 0;
    }else{
        printf("Write successful\n");
    }


// set lock_sh o processA thi processB co the set lock_sh
    numFlock = flock(fd, LOCK_SH); // set lock_ex o processA thi processB ko the set lock_ex hay lock_sh
    if(numFlock == -1) {
        printf("set lock failed\n");
        return 0;
    }else{
        printf("set lock successful\n");
    }
     while(1){
        sleep(1);
    }
    close(fd);
    return 0;



}