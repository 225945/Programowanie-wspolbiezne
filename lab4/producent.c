//---------------------------------------------------------------------------------
// Producent / konsument  proces wysylajacy komunikaty do kolejki     
// Odbiera program mq_rcv
// Kompilacja:   gcc mq_snd.c -o mq_snd -lrt   
// Uruchomienie: ./mq_snd numer
// Gdy zamontujemy koleki komunikatow w kat /dev/mqueue to mozna nimi manipulować
// uzywając poleceń ls,...
// mkdir /dev/mqueue
// mount -t mqueue none /dev/mqueue
// ----------------------------------------------------------------------------------
#include <stdio.h>
#include <mqueue.h>
#include <stdlib.h>
#include <string.h>
#define  SIZE     80
#define  MQ_NAME "/Kolejka"
 struct {
      int  nr_prod;        // Nr producenta
      char text[SIZE];  // Tekst komunikatu
  } msg;

 int main(int argc, char *argv[]) {
   int i, res, num=0;
   unsigned int prior;
   mqd_t  mq;
   struct mq_attr attr;
   char kname[40];
   prior = 10;
   if(argc < 2) { printf("Uzycie: mq_send numer\n"); exit(0); }
   num = atoi(argv[1]);
   if(argc >= 3) strcpy(kname, argv[2]); else strcpy(kname,MQ_NAME);
   printf("Kolejka: %s\n",kname);
   mq=mq_open(kname , O_RDWR );
   if( mq == -1 ) {  perror("Kolejka "); exit(0);  }
   printf("Kolejka: %s otwarta, mq: %d\n", kname,mq);
   for(i=0; i < 10 ;i++) {
     mq_getattr(mq,&attr);   
     printf("W kolejce %ld komunikatow\n",attr.mq_curmsgs);
     sprintf(msg.text,"Proces %d komunikat %d",num,i);
     msg.nr_prod = num;
     res = mq_send(mq,(char *)&msg,sizeof(msg),prior);
     if (res == -1 ) { perror("Blad zapisu do mq"); continue; }
     printf("Producent %d Komunikat %d wyslany\n",num,i);
    sleep(1);
  }
  mq_close(mq);
return 0;
}  
 
