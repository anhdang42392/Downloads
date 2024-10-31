#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include "shared_memory.h"

int main() {
    int shm_id;
    SharedMemory *shm_ptr;

    shm_id = shmget(SHM_KEY, SHM_SIZE, 0666);
    if (shm_id < 0) {
        perror("Không thể kết nối bộ nhớ chia sẻ");
        exit(1);
    }

    shm_ptr = (SharedMemory *)shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *)-1) {
        perror("Không thể gắn bộ nhớ chia sẻ");
        exit(1);
    }

    while (1) {
        printf("tin nhắn gửi tới server: ");
        fgets(shm_ptr->client_message, sizeof(shm_ptr->client_message), stdin);
        shm_ptr->client_message[strcspn(shm_ptr->client_message, "\n")] = '\0';
        shm_ptr->client_status = 1;

        while (shm_ptr->server_status != 1) {
            usleep(100000);
        }

        printf("Server: %s\n", shm_ptr->server_message);
        shm_ptr->server_status = 0;
    }

    shmdt(shm_ptr);

    return 0;
}
