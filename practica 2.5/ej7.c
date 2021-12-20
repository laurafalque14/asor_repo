#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 80
int main(int argc, char **argv){

	struct addrinfo hints;
	struct addrinfo *rp;
	
	ssize_t nread;
	char buf[BUF_SIZE];
	int s, sfd;
	
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_flags = AI_PASSIVE;
	hints.ai_protocol = 0;

	s = getaddrinfo(argv[1], argv[2], &hints, &rp);
	if (s == -1) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
		return -1;
	}

	sfd = socket(rp->ai_family, rp->ai_socktype,rp->ai_protocol);
	if (sfd ==-1) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(sfd));
		return -1;
	}
	int c = connect(sfd, rp->ai_addr, rp->ai_addrlen);
	if (c ==-1) {
	       fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(c ));
		return -1;
	 }
	freeaddrinfo(rp);        

	while(1){
		nread = read(0,buf,BUF_SIZE);
		buf[nread] = '\0';

		if(buf[0] == 'Q'){
			printf("Saliendo\n");
			close(sfd);
		}
		send(sfd,buf,nread,0);
		recv(sfd, buf,nread, 0);
		printf("Datos: %s\n",buf);
	}

	return 0;
	
 }
