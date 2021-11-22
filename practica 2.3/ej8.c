#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include<stdlib.h>

int main(int argc, char **argv){
    pid_t pid = fork();
    pid_t se ;
    switch(pid){
   	 case -1:
   		 perror("Error");
   		 return -1;
   	 break;
   	 //HIJO
   	 case 0:
   		 se=setsid();
   		 printf("Hijo,ppid:%i,pid:%i\n", getppid(),getpid());
   		 int fdOut=open("/tmp/daemon.out",O_CREAT|O_RDWR|O_TRUNC,0777);
   		 int fdErr=open("/tmp/daemon.err",O_CREAT|O_RDWR|O_TRUNC,0777);
   		 int fdIn=open("/ /dev/null",O_CREAT|O_RDWR|O_TRUNC,0777);
   		 dup2(fdOut,1);
   		 dup2(fdIn,0);
   		 execvp(argv[1],argv+1);
   	 break;
   	 //PADRE
   	 default:
   		 printf("Padre,ppid:%i,pid:%i\n",getppid(),getpid());
   	 break;
    }
    return 0;
}