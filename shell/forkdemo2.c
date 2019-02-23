#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	printf("parent pid:\t%d\n", getpid());
	fork();
	fork();
	fork();
	fork();
	printf("pid:\t%d\n", getpid());
	return 0;
}
