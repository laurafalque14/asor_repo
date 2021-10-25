#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main(){
char *s;
if(setuid(0) == -1)
   printf("Error:(%d):%s\n", errno, strerror(errno));
return 1;
}
