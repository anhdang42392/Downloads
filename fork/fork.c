#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{

    int fd;
    int numb_read, numb_write;
    char buf1[20] = "helloworld \n";
    fd = open("fork.txt", O_RDWR | O_CREAT, 0667);
    if (-1 == fd)
    {
        printf("open() fork.txt failed\n");
    }
    numb_write = write(fd, buf1, strlen(buf1));
    printf("Write %d bytes to hello.txt\n", numb_write);

    __pid_t child_pid;
    int counter = 2;
    printf("Counter: %d\n", counter);
    child_pid = fork();

    if (child_pid >= 0)
    {
       
        if (child_pid == 0)
        {
            char child[10] = {0};
            sprintf(child,"%d\n",getpid()); 
            write(fd, "\nchild PID", strlen("child PID"));
            write(fd, child, strlen(child));
            printf("My PID is: %d\n", getpid());
            printf("I am child\n");
        }
        else
        {
            char parent[10] = {0};
            sprintf(parent,"%d\n", getppid());
            write(fd, "parent PID: ", strlen("parent PID"));
            write(fd, parent, strlen(parent));
            printf("My PID is: %d\n", getppid());
            printf("I am parent\n");
            while (1)
                ;
        }
        close(fd);
    }
    else
    {
        printf("fork() unsuccessfully\n");
    }
    while (1)
        ;

    return 0;
}