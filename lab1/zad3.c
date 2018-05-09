// Ilustracja działania funkcji execl – uruchomienie programu potomny 
#include <stdio.h> 
//#include <process.h> 
#include <unistd.h> 
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

void main(int argc, char* argv[]){ 
  int pid,status,i,j;
  char kroki[10];
  for(i=0; i<argc-1; ++i){
     if((pid = fork()) == 0) { /* Proces potomny pot ---*/ 
     execl("./pot","pot",kroki,argv[i+1],NULL); 
     }
  }   
   for(j=0; j<=atoi(argv[1]); j++){
   printf("Macierzysty = %d, krok = %d \n",getpid(),j);
   sleep(1);   
   }
   for(i=0; i<argc-2;i++){
    pid = wait(&status); 
    printf("Proces %d zakończony status: %d\n",pid,WEXITSTATUS(status)); 
   }
} 
