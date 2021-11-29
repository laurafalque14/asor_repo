#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<sys/select.h>
#include<sys/time.h>
int maximo(int a, int b) {
	return a<b ? b : a; 
}
int main(int argc, char **argv){
	char *tubR ="tubR";//tuberia de lectura
	mkfifo(tubR,0777);
	char *tubW="tubW";//tuberia de escritura
	mkfifo(tubW,0777);
	char buf[256];
   	int fd_tubR = open(tubR,O_RDONLY|O_NONBLOCK);//abrimos tuberia de lectura
	int fd_tubW = open(tubW,O_RDONLY|O_NONBLOCK);//abrimos tuberia de escritura
	if(fd_tubR ==-1 || fd_tubW==1){
		printf("Error\n");
		return -1;
	}
	while(1){
	fd_set set; //creamos conjunto vacio
	FD_ZERO(&set);//lo limpiamos
	FD_SET(fd_tubR,&set);//añadimos descriptor de lectura
	FD_SET(fd_tubW,&set);//añadimos descriptor de escritura
	int fd_max=maximo(fd_tubR,fd_tubW);
	int sel=select(fd_max+1,&set,NULL,NULL,NULL);//seleccionamos descriptores
	int * tub_act;//tuberia actual
	char *num_tub;
        if(sel==-1){
		printf("Error %s\n",strerror(errno));
		return -1;
	}
	else if(sel ==0){
		printf("TimeOut %s\n",strerror(errno));
		return -1;
	}
	else{	
		if(FD_ISSET(fd_tubR,&set)){//vemos si la tuberia de lectura pertenece al conjunto
			tub_act=&fd_tubR;
			num_tub ="tubR";
		}
		if(FD_ISSET(fd_tubW,&set)){//vemos si la tuberia de escritura pertenece al conjunto
			tub_act=&fd_tubW;
			num_tub = "tubW";
		}
		int rc=read(*tub_act,buf,255);//leemos la tuberia actual
		if(rc==-1){
			printf("Error al leer el fichero de la tubería actual\n");
			return -1;
		}
		else if ( rc == 0 ){//para el final del fichero
			close(*tub_act);
			*tub_act = open(num_tub,O_RDONLY|O_NONBLOCK);
		}
		else{
			buf[rc]='\0';
			printf("Tuberia: %s Datos: %s\n",num_tub,buf);
		}
	}
	}
	close(fd_tubR);
	close(fd_tubW);
	return 0;
}
