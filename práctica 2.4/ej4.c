#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
//creo la tuberia en el terminal con mkfifo tub
int main(int argc, char **argv){
	if(argc!=2){
		printf("Error\n");
		return -1;	
	}
	int fd = open(argv[1],O_WRONLY);
	close(fd);
	write(fd, argv[1], strlen(argv[1]));
	close(fd);
	return 0;	
}
