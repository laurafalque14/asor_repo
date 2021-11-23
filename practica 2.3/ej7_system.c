#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    if (argc < 2) {
   	   printf("Error\n");
   	   return -1;
      }
    int cmdLen = 1;
    int i;
    for (i = 1; i < argc; i++)
    cmdLen += strlen(argv[i]) + 1;
    char *cmd = malloc(sizeof(char)*cmdLen);
    strcpy(cmd, "");
      for (i = 1; i < argc; i++) {
   	 strcat(cmd, argv[i]);
   	 strcat(cmd, " ");
  }
      if (system(cmd) == -1) {
   	 	printf("Error al ejecutar el comando\n");
      }
      printf("El comando se ha ejecutado correctamente\n");
      return 0;
}