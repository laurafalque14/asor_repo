include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include<stdlib.h>
int main(int argc, char **argv){
    pid_t pid = fork();
    pid_t se;
    switch(pid)
    {
        case -1:
            perror("Error");
            return -1;
        break;
        //HIJO
        case 0:
            se = setsid();
            chdir("/tmp");
            printf("Hijo,ppid:%i,pid:%i\n", getppid(),getpid());
                    printf("Atributos del hijo:\n");
            printf("PPID:%i\n",getppid());
            printf("PID:%i\n",getpid());
            printf("SESPPID:%i\n",getsid(getpid()));
            printf("GPPID:%i\n",getgid());
            printf("GPID:%i\n",getgid());
        break;
        //PADRE
        default:
            printf("Padre,ppid:%i,pid:%i\n",getppid(),getpid());
            printf("PPID:%i\n",getppid());
            printf("PID:%i\n",getpid());
            printf("Atributos del padre:\n");
            printf("SESPPID:%i\n",getsid(getpid()));
            printf("GPPID:%i\n",getgid());
            printf("GPID:%i\n",getgid());
        break;
    }
    
    return 0;
}


