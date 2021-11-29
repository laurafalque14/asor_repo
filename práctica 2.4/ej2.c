#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>

#define WR 1
#define RD 0
int main(int argc, char **argv){
    int p_h[2];
    int h_p[2];
    pipe(p_h);
    pipe(h_p);
    char msg[2048],msgP[2048];
    char letra;
    pid_t pid= fork();
    if(pid==0){//hijo
        close(p_h[1]);
        close(h_p[0]);
        //Leer de la tubería padre
 	int i = 0;
        while(i < 10){
             int rc = read(p_h[0],msgP,2047);
             msgP[rc]='\0';
             printf("Hijo : %s\n",msgP);
             letra = 'l';
             printf("Hijo : %s\n",msgP);
             sleep(3);
             if(i==9) letra = 'q';
               write(h_p[1],&letra,1);
             i++;
        }
    close(p_h[0]);
    close(h_p[1]);
    }
    else{ //padre
      close(p_h[0]);
      close(h_p[1]);
      while(letra!='q'){
         printf("Padre: %s\n",msg);
         int rc = read(0, msg, 2047);
         msg[2048] = '\0';
         printf("Padre: %s\n", msg);
         write(p_h[1],msg,2048);
         read(h_p[0],&letra,1);
         sleep(3);
      }
    close(h_p[0]);
    close(p_h[1]);
    printf("msgs enviados");
    return 0;
   }
   return 0;
}
