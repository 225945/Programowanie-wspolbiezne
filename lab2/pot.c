#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int pierwsza(int);

void main(int argc, char* argv[]) {
int wynik = 0;
int i;
int p;
  for(i = atoi(argv[1]); i<atoi(argv[2]); ++i){
	p = pierwsza(i);
	if(p){
	  ++wynik;
	}
  }
  exit(wynik);
}

int pierwsza(int n)
{ int i,j=0;
  for(i=2; i*i<=n; i++) {
    if(n%i == 0) return(0);
}
return(1);
}
