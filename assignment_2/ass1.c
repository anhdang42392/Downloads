# include <stdio.h>
# include <string.h>
# include <unistd.h>
#include <fcntl.h>

int main(void){
    int fd;    
    int fileFlock;
    int  numb_write;
    ssize_t numb_read;

    char buf2[15] = {0};
    char buf1[15] = "hello world\n";
    
    // create file assign1.txt
    fd = open("assign1.txt", O_RDWR | O_CREAT , 0667);
    if(-1 == fd){
        printf("open() hello.txt failed\n");
    }else{
        printf("Create successful\n");
    }
    // write data buf1 to assign1.txt
    numb_write = write(fd, buf1, strlen(buf1));
    
    printf("Write %d bytes to hello.txt\n", numb_write);
    printf("Value of file descriptor: %d\n",fd);
    
    // open file assign1.txt to only read
    fd = open("assign1.txt", O_RDONLY);
    numb_read = read(fd, &buf2, sizeof(buf2)-1);
    if(numb_read == -1){
        printf("read failed\n");
    }else{
        printf("The content read is: %s\n",buf2);
    }
    close(fd);
    return 0;
}