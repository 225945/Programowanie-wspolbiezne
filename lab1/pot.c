#include <stdio.h> 
//#include <process.h> 
#include <unistd.h> 
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
void main(int argc, char* argv[]) { 
  int id, i ; 
  for(i=0;i <= atoi(argv[2]);i++) { 
       printf("Potomny: %d krok: %d \n",atoi(argv[2]),i); 
       sleep(1); 
  } 
  exit(i); 
} 
