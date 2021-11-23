#include <stdlib.h>
#include <signal.h>
#include<stdio.h>
#include<errno.h>
volatile contINT = 0,contTSTP=0;
//SigINT se produce al hacer ctrl+C y sigTSTP al hacer ctrl+Z
void handle_cont(int s){
    if(s == SIGINT) contINT ++;
    if(s == SIGTSTP) contTSTP ++;
}
int main(int argc,char **argv) {
    struct sigaction sa;
    sa.sa_flags = SA_RESTART;
    sa.sa_handler=handle_cont;
    sigaction(SIGINT,&sa,NULL);
    sigaction(SIGTSTP,&sa,NULL);
    printf("Sigo\n");
    sigset_t set;
    sigemptyset(&set);
    while (contINT + contTSTP < 10)
   	 sigsuspend(&set);
    printf("La señal INT ha sido contada :%i\n",contINT);
    printf("La señal STP ha sido contada :%i\n",contTSTP);
   	 return 0;
}