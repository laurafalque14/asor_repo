#include<stdio.h>
#include<string.h>
#include<time.h>
#include<errno.h>

int main(int argv, char **argc){
    time_t tiempo = time(NULL);
    if(tiempo == -1){
       perror("Error");
       return -1;
    }
    printf("Hora:%li\n", tiempo);
    return 1;
}
