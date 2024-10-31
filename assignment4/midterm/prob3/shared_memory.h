#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#define SHM_KEY 1234
#define SHM_SIZE 1024

typedef struct {
    int client_status;
    int server_status;
    char client_message[100];
    char server_message[100];
} SharedMemory;
