#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) {
	if (argc < 2) {
		 printf("Error\n");
		 return -1;
	}
  int fd = open(argv[1], O_CREAT | O_RDWR, 00777);
  if (fd == -1) {
    printf("Error de fichero\n");
    return -1;
  }
  int fd2 = dup2(fd, 1);
  printf("Esto se ha reedirigido a d\n", argv[1]);
  dup2(fd2, fd);
  return 0;
}