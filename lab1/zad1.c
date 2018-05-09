#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

void main(int argc, char* argv[]){ 
  int pid,status,i,j;
  for(i=0;i<argc-2 ;i++){ 
    if((pid = fork()) == 0) { /* Proces potomny pot ---*/ 
        printf("potomny = %d \n",getpid()); 
	for(j=0;j<atoi(argv[i+2]);j++){
	   printf("potomny: %d krok %d \n",i, j);
	    sleep(1);        
 	}
        exit(1);
    }   

  }
  /* Proces macierzysty */ 
  for(j=0;j<atoi(argv[1]);j++){
  printf("Macierzysty = %d \n",getpid()); 
	sleep(1);
  }  
  for(i=0;i<argc-2 ;i++){
	pid = wait(&status);
	printf("Proces %d zakończony status: %d\n",pid,WEXITSTATUS(status)); 
  }
 
 
} 
