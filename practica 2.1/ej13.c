#include<stdio.h>
#include<string.h>
#include<time.h>
#include<errno.h>
#include<sys/time.h>
#define N 1000000
int main(int argv, char **argc){
	struct timeval tv;
	int rc = gettimeofday(&tv,NULL); 
	int ini = tv.tv_usec;
	int act=0, i = 0;
	for(i; i < N;i++){
		int rc2 = gettimeofday(&tv,NULL); 
		act = tv.tv_usec;	
	}	
	printf("La duracion el bucle fue de:%i\n", act-ini);
	return 1;
}
