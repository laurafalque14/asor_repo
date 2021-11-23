#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

volatile int parar = 0;
void hler(int senhal){
  if (senhal == SIGUSR1) parar = 1;
}
int main(int argc, char **argv) {
    if (argc != 2) {
   	   printf("Error\n");
   	   return -1;
      }
    sigset_t mask;
      sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
      sigprocmask(SIG_UNBLOCK, &mask, NULL);

      struct sigaction action;
      sigaction(SIGUSR1, NULL, &action);
      action.sa_handler = hler;
      sigaction(SIGUSR1, &action, NULL);

      int segs= atoi(argv[1]);

      int i = 0;
    while (i < segs && parar == 0) {
   		 i++;
   		 sleep(1);
      }
    if (parar == 0) {
   		 printf("Se borra");
   		 unlink(argv[0]);
      } else {
   		 printf("No se borra");
      }
      return 0;
}