#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void handar(int);
int main()
{
	int i;
	signal(SIGINT, handar);
	
	for(i=0; i<5; i++)
	{
		printf("main(): %d\n", i);
		sleep(1);
	}
	return 0;
}

void handar(int signum)
{
	printf("handar(): ctrl+c\n");

	for(int i=0; i<5; i++)
	{
		printf("handar(): %d\n", i);
		sleep(2);
	}
}
