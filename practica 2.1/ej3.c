#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

const int MAXNUM = 255;

int main(){
    int i = 0;
for(i; i < MAXNUM;++i){
    char *s;
    printf("Error(%d):%s\n",i,strerror(i));
}
return 1;
}
