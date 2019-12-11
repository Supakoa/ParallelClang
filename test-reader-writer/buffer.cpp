#include <iostream> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 

using namespace std; 
  
int main() 
{ 

    key_t key = ftok("shmfile",65); 

    int shmid = shmget(key,1024,0666|IPC_CREAT);

    char *str = (char*) shmat(shmid,(void*)0,0); 

    char sushi(char*)[20] = (char*) shmat(shmid, 0, 0);

    shmdt(str);  
     
    return 0; 
} 