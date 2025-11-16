#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

int main() {
    int shmid = shmget((key_t)1234, 1024, 0666 | IPC_CREAT);
    char *shm = shmat(shmid, NULL, 0);

    if (fork() == 0) {
        strcpy(shm, "Hello from child process!");
        shmdt(shm);
    } else {
        sleep(1);
        printf("Parent reads: %s\n", shm);
        shmdt(shm);
        shmctl(shmid, IPC_RMID, 0);
    }
    return 0;
}
