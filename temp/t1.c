#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void main(void)
{
    key_t key = 15;
    int shmid_1, shmid_2;

    if ((shmid_1 = shmget(IPC_PRIVATE, 1000, 0644 | IPC_CREAT)) == -1)
    {
        perror("shmget shmid_1");
        exit(1);
    }
    printf("First shared memory identifier is %d \n", shmid_1);

    if ((shmid_2 = shmget(IPC_PRIVATE, 20, 0644 | IPC_CREAT)) == -1)
    {
        perror("shmget shmid_2");
        exit(2);
    }
    printf("Second shared memory identifier is %d \n", shmid_2);

    int iget = shmget(IPC_PRIVATE, 20, 0644);
    printf("share mem get : %d", iget);
    exit(0);
}