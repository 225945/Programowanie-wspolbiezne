// Producent / konsument  proces odbierajacy komunikaty z kolejki      
// Kompilacja gcc mq_rcv.c -o mq_rcv -lrt       
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
 prior = 10;
 if(argc < 2) {
    printf("Uzycie: mq_rcv numer\n"); 
    exit(0);
 }
 mq=mq_open(MQ_NAME , O_RDWR);
 if( mq == -1 ) {   perror("Producent "); exit(0); }
num = atoi(argv[1]);
 for(i=0; i < 10 ;i++) {
    mq_getattr(mq,&attr); //  Status kolejki
    msg.nr_prod = num;
    printf("W kolejce %ld komunikatow\n",attr.mq_curmsgs);
    res = mq_receive(mq,(char *)&msg,sizeof(msg),&prior);
    if (res == -1 )  perror("Blad odczytu z mq");
    else                 printf("Konsument: %d odebral: %s\n",num, msg.text);
    sleep(1);
  }
  mq_close(mq);
  mq_unlink(MQ_NAME);
}  
