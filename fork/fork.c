#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

void func(int signum)
{
    printf("Im in th func()\n");
    wait(NULL);
}

int main(int argc, char const *argv[])
{

    int i;
    printf("Number of argument: %d\n", argc);

    for (i = 0; i < argc; i++)
    {
        printf("argc[%d]: %s\n", i + 1, argv[i]);
    }

    // tao file forx.txt de gi du lieu vao
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

    // bat dau tach PID ra 2 process cha va con
    __pid_t child_pid; // khai bao gia tri cho fork
    int rv, status;
    int counter = 2;
    printf("Counter: %d\n", counter);
    child_pid = fork();
    // neu gia tri cua fork < 0 thi tach qua trinh tao ra process moi bi loi
    if (child_pid >= 0) // gia tri cua fork > 0 thi qua trinh tao ra process thanh cong
    {
        char countchar[50] = {0};
        if (child_pid == 0) // neu fork = 0 thi day la process con ( process child)
        {

            // getpid la PID cua process nay (process con)
            // getppid la PID cua process cha cua process nay
            char child[10] = {0};
            sprintf(child, "%d\n", getpid());
            sprintf(countchar, "Counter in process child: %d\n", ++counter);

            write(fd, countchar, strlen(countchar));
            write(fd, "child PID: ", strlen("child PID: "));
            write(fd, child, strlen(child));

            printf("Counter in process child: %d\n", counter);
            printf("My PID is: %d, my parent PID is: %d\n", getpid(), getppid());
            printf("I am child\n");

            while (1);
            //exit(10);
            // kill(getpid(),SIGKILL);
        }
        else // neu fork > 0 thi day la process cha (process parent)
        {

            // Solution 1
            signal(SIGCHLD, func);            //  khi kill thg con ban lenh kill -9 PID trong command line thi thg con se gui tin hieu den ham func
            printf("Im in parent process\n"); // trong ham func se thuc hien wait de loai bo tien trinh zombie con vua bi kill va vao process parent

            // Solution 2
            pid_t pid = waitpid(child_pid,&status,0); // kiem tra trang thai ket thuc cua process con bang pid cu the cua process con
            if(WIFEXITED(status)){
                printf("Child Process %d terminated with value %d\n", pid, WEXITSTATUS(status));
            }else if(WIFSIGNALED(status)){
                printf("Child Process %d terminated with value of kill signal: %d\n", pid, WTERMSIG(status));
            }

            // Solution 3
            // khong the su dung wait va waitpid cung luc
            //rv = wait(&status);               // kiem tra trang thai ket thuc cua process con ngau nhien bang wait
            if (rv == -1)
            { // neu rv la -1 thi process con ket thuc that bai
                printf("wait() unsuccessful\n");
            }
            else
            {                                                           // neu rv khac -1 thi process con ket thuc thanh cong va  gia tri cua rv la PID cua process con
                printf("In process parent, PID of child is: %d\n", rv); // in ra PID cua process con vua ket thuc

                if (WIFEXITED(status)) // ket thuc bang exit 
                {
                    printf("Normal termination, status: %d\n", WEXITSTATUS(status)); // in ra gia tri trong n trong exit(n)
                }
                else if (WIFSIGNALED(status)) // ket thuc bat thuong bang kill
                {
                    printf("Kill by signal, value: %d\n", WTERMSIG(status)); // in ra gia tri n cua kill trong kill -l (kill -n PID)
                }

                char parent[10] = {0};
                sprintf(parent, "%d\n", getpid());
                sprintf(countchar, "Counter in process parent: %d\n", ++counter);

                write(fd, countchar, strlen(countchar));
                write(fd, "parent PID: ", strlen("parent PID: "));
                write(fd, parent, strlen(parent));

                printf("Counter in process parent: %d\n", counter);
                printf("My PID is: %d, my parent PID is: %d\n", getpid(), getppid());
                printf("I am parent\n");
                while (1)
                    ;
            }
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