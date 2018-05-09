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
 // Utworzenie kolejki komunikatow ----------------
 attr.mq_msgsize = sizeof(msg);
 attr.mq_maxmsg = 4;
 attr.mq_flags = 0;
 mq=mq_open(MQ_NAME , O_RDWR | O_CREAT , 0660, &attr );
 if( mq == -1 ) {   perror("Producent "); exit(0); }
 printf("Kolejka utworzona: %d \n",mq);
  mq_close(mq);
return 0;
}  
