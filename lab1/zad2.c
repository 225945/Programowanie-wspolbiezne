#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

void main(int argc, char* argv[]){ 
int pid,status,i,j;
char kroki[10];
if((pid = fork()) == 0) { /* Proces potomny pot ---*/ 
	execl("./pot", "pot",argv[2], NULL);
} else { //Proces macierzysty ---------
	for(j=1;j<atoi(argv[1]);j++) {
	printf("Macierzysty krok %d \n",j);
	sleep(1); 
  }  
pid = wait(&status);
printf("Proces %d zakończony status: %d\n",pid, WEXITSTATUS(status)); 
 }
} 
