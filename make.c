# include <stdio.h>
# include <string.h>
# include <unistd.h>
#include <fcntl.h>

int main(void){
    int fd;
    int fileFlock;
    int  numb_write;
    ssize_t numb_read;
    char buf1[15] = "hello world\n";
    char buf2[15] = {0};
    fd = open("hello.txt", O_RDWR | O_CREAT , 0667);
    if(-1 == fd){
        printf("open() hello.txt failed\n");

    }

    numb_write = write(fd, buf1, strlen(buf1));
    while((numb_read = read(fd, buf2, strlen(buf2))) > 0){
        write(STDOUT_FILENO,buf2,numb_read);
    }
    printf("Write %d bytes to hello.txt\n", numb_write);
    printf("Read %d bytes from hello.txt\n",strlen(buf2));
    printf("String in buf2: %.*s\n",(int)sizeof(buf2),buf2);    
    printf("Value of file descriptor: %d\n",fd);
    lseek(fd,2,SEEK_SET);
    write(fd, "AAAAAAAAAAAA", strlen("AAAAAAAAAAAA"));
    close(fd);
    return 0;
}