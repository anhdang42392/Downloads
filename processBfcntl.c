#include <stdio.h>
#include <sys/stat.h> 
#include <sys/file.h> 
#include <unistd.h> 
#include <fcntl.h> 


int main(void) 
{ 
    int fd; 
    int numWrite;
    int numFnctl;

    char text[16] = {0};  
    struct flock fl; 


    sprintf(text, "thonv12\n"); //ghi du lieu vao mang text
    // mo file fnctlText.txt
 fd =open("fnctlText.txt", O_RDWR);
    if( fd == -1) { 
        printf("Open file failed \n"); 
        return 0; 
    } else { 
        printf("Open file sucessful \n"); 
    } 


// set khu vuc de locking file
    fl.l_start = 1;         /* Offset where the lock begins */
    fl.l_len = 5;           /* Number of bytes to lock; 0 means "until EOF" */
    fl.l_type = F_WRLCK;    /* Lock type: F_RDLCK, F_WRLCK, F_UNLCK */
    fl.l_whence = SEEK_SET; /* How to interpret 'l_start': SEEK_SET, SEEK_CUR, SEEK_END */


// lock khong thanh cong vi o processAfcntl.c da lock tu 0 den 5
numFnctl = fcntl(fd, F_SETLK, &fl);
    if(numFnctl == -1) { 
        printf("can not set write lock byte 0-5\n"); 
    } 

// set khu vuc de locking file tu vi tri 6 den 8
    fl.l_start = 6; 
    fl.l_len = 8; 
    fl.l_type = F_WRLCK; 
    fl.l_whence = SEEK_SET; 

numFnctl = fcntl(fd, F_SETLK, &fl);
    if(numFnctl == -1) { 
        printf("can not set write lock byte 6-11\n"); 
    } else { 
        printf("set write lock byte 6-11\n"); 
        lseek(fd, 6, SEEK_SET);

            numWrite = write(fd, text, sizeof(text)-1);
        if(numWrite == -1) { 
            printf("can not write file \n"); 
            return 0; 
        } else {
            printf("write file \n");
        } 
    } 


    close(fd); 
    return 0; } 