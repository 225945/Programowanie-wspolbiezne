#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

struct  
{
		int begin;
		int end;
		int result;
} zapis;


int pierwsza(int n);

int main(int argc,char ** args)
{
        char c;
 	int file = open("file.txt", O_RDWR | O_APPEND) ;

	int begin = atoi(args[1]), end = atoi(args[2]);
	int i, counter=0,wr;
	
	for(i=begin;i<end;i++)
	{
		if(pierwsza(i)==1)
			counter++;	
	}
    zapis.begin = begin;
    zapis.end   = end;
    zapis.result = counter;

	printf("Czekam\n");
	char status_tymczasowy[16];
	// sprintf(status_tymczasowy, "%d\n", counter);
	lockf(file,F_LOCK,0);
        printf("nacisnij cos\n");
        c = getchar();
	wr = write( file, &zapis, sizeof(zapis) );	
    	lockf(file,F_ULOCK,0);
	printf("Zapisalem: %d\n",wr);
	close(file);
	
}


int pierwsza(int n)
{
	int i,j=0;
	for(i=2;i*i<=n;i++)
	{
		if(n%i == 0) return(0) ;
	}
	return(1);
}
