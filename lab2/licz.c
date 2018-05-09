#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

void main(int argc, char* argv[]){
  int pid, status, i, j, proces, total;
  time_t time_pocz, time_kon, time_total;
  char str[20];
  char str2[20];
  int pocz, kon, N;
  pocz = atoi(argv[1]);				//poczatek przedzialu liczb
  kon = atoi(argv[2]);				//koniec przedzialu liczb
  proces = atoi(argv[3]);			//ilosc procesow
  N = (int)((kon - pocz)/proces);               //podzielenie przedzialu liczb na procesy
  time_pocz = time(NULL);

  for(i=0; i<proces; i++){
     if((pid = fork()) == 0) { 			//proces potomny pot  
	sprintf(str, "%d", pocz+(i*N));
	if(i == proces){
	   sprintf(str2, "%d", kon);
	}
	else{
	   sprintf(str2, "%d", pocz+(i*N)+N);
	}
	 execl("./pot","pot", str, str2,NULL);
  	}
  }

  total = 0;
  for(i=0; i<proces; i++){
      pid = wait(&status);
      printf("Proces %d zakończony status: %d\n",pid,status);
      total += WEXITSTATUS(status);
  }
  time_kon = time(NULL);
  time_total = time_kon - time_pocz;		//wyliczenie calkowitego czasu wykonania
  printf("Liczb pierwszych w zadanym przedziale: %d\nCzas[sek]: %d\n", total, time_total);
}
