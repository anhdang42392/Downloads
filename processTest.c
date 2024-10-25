#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
int  main(int argc, char *argv[]){
    int i ;
    printf("Number of argument: %d\n", argc);

    for (i = 0 ; i < argc ; i++){
        printf("argc[%d]: %s\n", i+1, argv[i]);
    }

char pathfile[100] = "/home/anhdang/Downloads/fork/fork/";

    printf("Before excel \n"); // ban dau chay process cua processTest.c
    printf("My PID is: %d, my parent PID is: %d\n", getpid(), getppid());
    //kill(getpid(),SIGKILL); // thoat khoi tienn trinh bat thuong bang kill   
    //exit(0); // thoat khoi tien trinh dang chay 1 cach binh thuong 
    execl("main","make", NULL); // chuyen sang chay process main cua main.c va khong quay lai

    printf("After execl\n");
    return 0;

}