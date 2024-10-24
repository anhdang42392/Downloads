#include <stdio.h>
#include <sys/stat.h> 
#include <sys/file.h> 
#include <unistd.h> 
#include <fcntl.h> 


int main(void) 
{ 
    int fd; 
    char text[16] = {0}; 
    int numWrite ;
    int numFnctl ;
    struct flock fl; 
 
    sprintf(text, "hello word 2\n"); // ghi du lieu vao mang text

// tao file fnctlText.txt
    fd=open("fnctlText.txt", O_RDWR | O_CREAT, 0777);
    if( fd== -1) { 
        printf("create file falied\n"); 
        return 0; 
    } else { 
        printf("create file successful\n"); 
    } 

// ghi du lieu vao file fcntlText.txt
    numWrite = write(fd, text, sizeof(text)-1);
    if(numWrite == -1) { 
        printf("Write file failed \n"); 
        return 0; 
    } else { 
        printf("write file Sucessful\n");  
    } 

// set khu vuc de lock write (tu phan tu thu 1 den phan tu thu 5)
    fl.l_start = 1;         /* Offset where the lock begins */
    fl.l_len = 5;           /* Number of bytes to lock; 0 means "until EOF" */
    fl.l_type = F_WRLCK;    /* Lock type: F_RDLCK, F_WRLCK, F_UNLCK */
    fl.l_whence = SEEK_SET; /* How to interpret 'l_start': SEEK_SET, SEEK_CUR, SEEK_END */

// tien hanh locking file trong khu vuc vua set 
    numFnctl = fcntl(fd, F_SETLK, &fl);
    if(numFnctl == -1) { 
        printf("can not set write lock byte 1-5\n"); 
    } else { 
        printf("set write lock byte 1-5 \n"); 
    } 


    while (1) { 
        sleep(1); 
    } 


    close(fd); 
    return 0; 
}