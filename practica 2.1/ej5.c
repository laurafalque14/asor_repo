#include <sys/utsname.h>
#include<errno.h>
#include<string.h>
#include<stdio.h>
#include <sys/utsname.h>
#include <sys/types.h>

int main(int argc, char** argv){
    struct utsname buf;
    int rc = uname(&buf);
    if(rc == -1){
	perror("uname");
	return -1;
    }
    printf("Sys:%s/n",buf.sysname);
    printf("Node:%s/n", buf.nodename);
    printf("Release:%s/n", buf.release);
    printf("Version:%s/n", buf.version);
    printf("Machine:%s/n", buf.machine);
   // printf("Domain:%s/n", buf.domainname);
   //domainname comentado porque no me funciona 
   return 1;
}
