#include <sys/types.h>
#include<errno.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<stdio.h>

int main(int argv, char **argc){
    uid_t real = getuid();
    uid_t afectivo = geteuid();
    printf("uidReal:%i\n", real);
    printf("uidAfectivo:%i\n", afectivo);
    return 1;
}
