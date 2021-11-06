#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<time.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include<sys/sysmacros.h>
int main(int argv, char **argc){
    struct stat st;
    int statint = stat(argc[1],&st);
    if(statint == 0){
	if(st.st_mode & S_IFDIR) printf("Es un directorio");
        else if(st.st_mode & S_IFREG){
         int ln = link("fichero.txt","fichero.hard");
         int s =  symlink("fichero.txt","fichero.sym");
        }
     }else{
	printf("Error");
     }
}