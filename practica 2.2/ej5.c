#include <sys/types.h>
#include <sys/stat.h>
#include<unistd.h>
#include <fcntl.h>
int main(int argv, char **argvc){
	char buf [10] = "Hola Mundo";
	int fd= open("fichero.txt",O_CREAT|O_RDWR|O_TRUNC, 0645);
	if(fd==-1){
		perror("Error");
		return -1;
	}
	read(fd,&buf,SEEK_SET);
	write(fd,&buf,sizeof(char)*10);
	close(fd);
	return 0;
}
