/*
 *            Author : Shannu
 *            Topic: IPC Reader
 *            Date   : 14  - March - 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024  // Size of shared memory

int main() {
    key_t key = ftok("shmfile", 65);  // Generate unique key
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);  // Create shared memory

    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }

    char *shm_ptr = (char *) shmat(shmid, NULL, 0);  // Attach to shared memory

    if (shm_ptr == (char *)-1) {
        perror("shmat failed");
        exit(1);
    }

    printf("Enter message to write to shared memory: ");
    fgets(shm_ptr, SHM_SIZE, stdin);  // Write input to shared memory

    printf("Data written to shared memory: %s\n", shm_ptr);

    shmdt(shm_ptr);  // Detach from shared memory

    return 0;
}
