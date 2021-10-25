#include <sys/types.h>
#include<errno.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<stdio.h>
#include<pwd.h>
int main(int argv, char **argc){
    uid_t real = getuid();
    uid_t afectivo = geteuid();
    printf("uidReal:%i\n", real);
    printf("uidAfectivo:%i\n", afectivo);
    struct passwd *p = getpwuid(real);
    if(p == 0){
       perror("Error");
       return -1;
    }
    printf("Name:%s\n", p->pw_name);
    printf("Home;%s\n", p->pw_dir);
    printf("Shell:%s\n", p->pw_shell);
    return 1;
}
