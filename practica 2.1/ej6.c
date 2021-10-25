#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(){
    printf("MaxArg:%li\n",sysconf(_SC_ARG_MAX));
    printf("NumChild:%li\n",sysconf(_SC_CHILD_MAX));
    printf("NumFile:%li\n",sysconf(_SC_OPEN_MAX));
    return 1;
}
