#include<stdio.h>
#include<string.h>
#include<errno.h>
#include <sched.h>
int main(int argc, char **argv){
	if(argc!=2){
		printf("Error\n");
		return -1;
	}
	int pid = atoi(argv[1]);
	int sched = sched_getscheduler(pid);
	struct sched_param p;
	switch(sched){
		case SCHED_OTHER:
			printf("the standard round-robin time-sharing policy\n");
		break;
		case SCHED_FIFO:
			printf("a first-in, first-out policy\n");
		break;
		case SCHED_RR:
			printf("a round-robin policy \n");
		break;
		default:
			printf("error\n");
		break;
	}
	int max=sched_get_priority_max(sched);
	int min=sched_get_priority_min(sched);
	sched_getparam(pid,&p);
	printf("prio :%i\n",p.sched_priority);
	printf("the maximum priority value: %i\n",max);
	printf("the minimum priority value: %i\n",min);
	return 0;
}
