#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h> 

int main() {
   printf("hi\n");

   int i = fork();

   return 0;
}