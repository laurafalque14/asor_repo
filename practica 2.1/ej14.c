#include<stdio.h>
#include<string.h>
#include<time.h>
#include<errno.h>
#include<sys/time.h>
#define N 1000000
int main(int argv, char **argc){
	time_t tiempo = time(NULL); 
	struct tm *local = localtime(&tiempo);
	int anho = local->tm_year;
	printf("El año es: %i\n",1900+anho);
	return 1;
}
