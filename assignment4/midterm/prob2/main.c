#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared_variable = 0;  // Biến chia sẻ giữa các thread
pthread_mutex_t lock;     // Mutex
FILE *file;

void* increment(void* arg) {
    for (int i = 0; i < 5; i++) {
        // Khóa mutex
        pthread_mutex_lock(&lock);
     // Cập nhật biến
        shared_variable++;
        fprintf(file, "Thread %ld tăng biến lên %d\n", (long)arg, shared_variable);
        // Mở khóa mutex
        pthread_mutex_unlock(&lock);
        usleep(100000);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Khởi tạo mutex
    if (pthread_mutex_init(&lock, NULL) != 0) {
        perror("Khong the khoi tao mutex");
        return 1;
    }
    // Mở tệp
    file = fopen("output.txt", "w");
    if (file == NULL) {
        perror("KKhong the mở hoặc tạo tệp output.txt");
        pthread_mutex_destroy(&lock);
        return 1;
    }
    // Tạo hai thread
    if (pthread_create(&thread1, NULL, increment, (void*)1) != 0) {
        perror("Khong the tạo thread 1");
        fclose(file);
        pthread_mutex_destroy(&lock);
        return 1;
    }

    if (pthread_create(&thread2, NULL, increment, (void*)2) != 0) {
        perror("Khong the tạo thread 2");
        fclose(file);
        pthread_mutex_destroy(&lock);
        return 1;
    }
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    //  hủy mutex
    fclose(file);
    pthread_mutex_destroy(&lock);
    printf("Kết quả đã được ghi vào output.txt\n");
    return 0;
}
