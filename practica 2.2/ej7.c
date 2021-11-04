#include <sys/types.h>
#include <sys/stat.h>
#include<unistd.h>
#include <fcntl.h>
int main(int argv, char **argvc){
	mode_t um = umask(027);
	char buf [10] = "Hola Mundo";
	int fd= open("fichero.txt",O_CREAT|O_RDWR|O_TRUNC,644);
	if(fd==-1){
		perror("Error");
		return -1;
	}
	read(fd, &buf,SEEK_SET);
	write(fd,&buf,sizeof(char)*10);
	close(fd);
	return 0;
}