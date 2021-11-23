#include <stdlib.h>
#include <signal.h>
#include<stdio.h>
#include<errno.h>
int main(int argc,char **argv) {
    if(argc!=2){
   	 printf("Error\n");
   	 return -1;
    }
    //1º en el terminal hay que poner export SLEEP_SECS = "60"
    //Probarlo en la terminal ./ej SLEEP_SECS
    //Saco la variable de entorno
    char *sl_secs= getenv("SLEEP_SECS");
    //paso el string a integer
    int s = atoi(sl_secs);
    sleep(s);
    sigset_t blk_set;

    sigprocmask(SIG_BLOCK, &blk_set,NULL);
    sigemptyset(&blk_set);
    sigaddset(&blk_set, SIGINT);
    sigaddset(&blk_set, SIGTSTP);
    if(sigismember(&blk_set,SIGINT)==0){
   	 printf("La señal INT  no ha sido capturada%s\n",strerror(errno));
   	 return 0;
    }
    else if(sigismember(&blk_set,SIGINT)==-1){
   	 printf("Error",strerror(errno));
   	 return -1;
    }
    if(sigismember(&blk_set,SIGTSTP)==0){
   	 printf("La señal STP  no ha sido capturada%s\n",strerror(errno));
   	 return 0;
    }
    else if(sigismember(&blk_set,SIGTSTP)==-1){
   	 printf("Error",strerror(errno));
   	 return -1;
    }
    sigprocmask(SIG_UNBLOCK, &blk_set, NULL);
    printf("La señal INT ha sido capturada%i\n",SIGINT);
    printf("La señal TSTP ha sido capturada%i\n",SIGTSTP);
    return 0;
}