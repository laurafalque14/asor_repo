#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argv, char**argc){
    long int linkMax = pathconf("./Nuevo", _PC_LINK_MAX);
    long int nameMax = pathconf("./Nuevo", _PC_NAME_MAX);
    long int pathMax = pathconf("./Nuevo", _PC_PATH_MAX);
    printf("linkMax:%li\n", linkMax);
    printf("nameMax:%li\n", nameMax);
    printf("pathMax:%li\n", pathMax);
    return 1;
}
