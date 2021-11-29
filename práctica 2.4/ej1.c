#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

#define WR 1
#define RD 0

int main(int argc, char **argv){
    int fds[2];
    pipe(fds);
    pid_t pid= fork();
 if(pid==0){
        close(fds[WR]); 
        dup2(fds[RD],0); 
        close(fds[RD]);
        //no se puede usar el vector porque se come las otras cosas
        //el argumento 0 siempre coincide con el ejecutable
        execlp(argv[3],argv[3],argv[4],NULL);
    }
  else{
        close(fds[RD]); 
        dup2(fds[WR],1);
        close(fds[WR]); 
        execlp(argv[1],argv[1],argv[2],NULL);

    }
 return 0;
}
