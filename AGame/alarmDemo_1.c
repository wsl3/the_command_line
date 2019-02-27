#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void wakeUp(int signum);

int main()
{
	signal(SIGALRM, wakeUp);
	printf("sleep 5 seconds!!!!\n");

	alarm(5);
	pause();
	printf("i'm waking!!!\n");
}

void wakeUp(int signum)
{
	printf("i'm signal hander function!!!!\n");
}
