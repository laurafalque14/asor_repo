#include<stdio.h>
#include<string.h>
#include<time.h>
#include<errno.h>
#include<sys/time.h>
#define N 1000000
int main(int argv, char **argc){
	time_t tiempo = time(NULL);
	struct tm *local = localtime(&tiempo);
	char buff[100];
 	strftime(buff,100,"%A,%d %B %Y,%H:%M",local);
	printf("Hoy es: %s\n",buff);
	return 1;
}
