#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/file.h>
#include<sys/time.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char **argv){
	char buf[200];
	time_t t=time(NULL);
	struct tm *l=localtime(&t);
	struct flock fl;
	fl.l_type=F_RDLCK;
	fl.l_whence=SEEK_SET;
	fl.l_start=0;
	fl.l_len=0;
	fl.l_pid=getpid();
	
	if(argc<2){
		printf("Error\n");
		return -1;
	}
	int fd=open(argv[1],O_CREAT|O_RDWR,0777);
	fcntl(fd,F_GETLK,&fl);

	if (fd== -1){	
		printf("Error de fichero\n");
		return -1;	
	}

if(fl.l_type==F_UNLCK){

		fl.l_type=F_WRLCK;
		fl.l_whence=SEEK_SET;
		fl.l_start=0;
		fl.l_len=0;
		fl.l_pid=getpid();

		if(fcntl(fd,F_GETLK,&fl)==-1){
			printf("Error al intentar cerrar el cerrojo\n");
			close(fd);
			return -1;
			}
		} 

	else{
		strftime(buf,200,"%d/%m/%y %H:%M:%S",l);
		write(fd,&buf,strlen(buf));
		sleep(3);
		return 1;
	}
	printf("Se ha activado el cerrojo de escritura\n");
	printf("En el buffer hay: %s\n",buf);
	close(fd);
	return 0;
}