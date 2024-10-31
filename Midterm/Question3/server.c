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

    shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("Không thể tạo bộ nhớ chia sẻ");
        exit(1);
    }

    shm_ptr = (SharedMemory *)shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *)-1) {
        perror("Không thể gắn bộ nhớ chia sẻ");
        exit(1);
    }

    shm_ptr->client_status = 0;
    shm_ptr->server_status = 0;

    printf("Server đã sẵn sàng giao tiếp với client...\n");

    while (1) {
        if (shm_ptr->client_status == 1) {
            printf("Client: %s\n", shm_ptr->client_message);

            shm_ptr->client_status = 0;

            printf("tin nhắn gửi tới client: ");
            fgets(shm_ptr->server_message, sizeof(shm_ptr->server_message), stdin);
            shm_ptr->server_message[strcspn(shm_ptr->server_message, "\n")] = '\0';
            shm_ptr->server_status = 1;
        }
        usleep(100000);
    }

    shmdt(shm_ptr);
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}
