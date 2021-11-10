#include<stdio.h>
#include<string.h>
#include<time.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>

//Esto es una idea aproximada
//No funciona y esta incompleto

int main(int argc,char **argv)
{
   
   DIR *directorio=opendir(argv[1]);
   struct dirent *dif;
   struct stat buff;
   if(argc!=2){
       printf("Error\n");
       return -1;
   }
   if(directorio==NULL){
       perror("Error en el directorio\n");
       return -1;
   }
  
   char *linkname;
   ssize_t r;
   unsigned long int tam=0;
   while(dif=readdir(directorio)!=NULL){
        char *origen = malloc(sizeof(char)*(strlen(argv[1]) + strlen(dif->d_name) + 3));
        if(stat(origen,&buff)!=-1){
            strcpy(origen,argv[1]);
            if(S_ISDIR(buff.st_mode)){
                strcat(origen,"/");
                strcat(origen,dif->d_name);
                printf("%s\n",origen);
            }
            else if(S_ISREG(buff.st_mode)){
                strcpy(origen,dif->d_name);
                printf("%s\n",origen);
                tam+=((buff.st_blksize/8)*buff.st_blocks);
            }
            else if(S_ISLINK(buff.st_mode)){
                linkname=malloc(buff.st_size + 1);
                if(r = readlink(origen, linkname, buff.st_size + 1)!=NULL){
                  strcat(origen,dif->d_name);
                  strcat(origen,"->");
                  strcat(origen,linkname);
                  printf("%s\n",origen);
                }
                linkname[buff.st_size]='\0';
            }
        }
    }
    return 0;
}