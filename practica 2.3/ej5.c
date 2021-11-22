#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
int main(int argc, char **argv){
	printf("PPID:%i\n",getppid());
	printf("PID:%i\n",getpid());
	printf("SESPPID:%i\n",getsid(getpid()));
	printf("GPPID:%i\n",getgid());
	printf("GPID:%i\n",getgid());
	char *path = malloc(sizeof(char)*(4096 + 1));
  char *rpath = getcwd(path, 4096 + 1);
	if(rpath==NULL) perror("Error en getcwd()");
	else printf("El directorio actual es%s\n",path);
	struct rlimit l;
	printf("El limite actual es%i\n",l.rlim_cur);
	printf("El limite maximo es%i\n",l.rlim_max);
	return 0;
}
