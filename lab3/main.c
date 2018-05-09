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
}zapis;

int main(int argc,char ** args)
{	

	int file = open("file.txt", O_RDWR | O_CREAT | O_TRUNC,0666) ;
	if(file<0){
	perror("open error!");
	}

	int begin = atoi(args[1]),
		end = atoi(args[2]),
		N = atoi(args[3]);

	int zakres=(end-begin)/N, pid,status;

	char poczatek[16];
	char poczatekzakresu[16];

	

  	int i=0;
	for(i; i<N ; i++)
	{
		sprintf(poczatek, "%d", begin);
		sprintf(poczatekzakresu, "%d", begin + zakres);

		if( (pid=fork())==0 )
		{
			execl("./licz","licz",poczatek, poczatekzakresu, NULL);
			perror("Zla funckja exec");
		}
		begin+=zakres;
	}


	int count = 0,rd;
	

 	for(i=0; i<N ; i++)
 	{
	    pid = wait(&status);
	
	}
		

	for(i=0; i<N ; i++)
 	{
 		rd = read(file, &zapis, sizeof(zapis) );
 	    
 		count = count + zapis.result;
	}

	printf("%d\n",count );
	
	close(file);
	return 0;
}
