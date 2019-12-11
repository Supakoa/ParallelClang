#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "stdio.h"
using namespace std;

int main(int argc, char *argv[])
{
    // ftok to generate unique key
    key_t key = ftok("shmfile", 12);

    cout << "key :" << key << "\n";

    // shmget returns an identifier in shmid
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    cout << "shmid :" << shmid << "\n";

    // shmat to attach to shared memory
    // char strd[5];
    char *str = (char *)shmat(shmid, (void *)0, 0);

    // cout << "str before :" << *str << "\n";

    cout << "Write Data : ";
    cin >> str;

    printf("Data written in memory: %s\n", str);

    //detach from shared memory
    shmdt(str);

    return 0;
}