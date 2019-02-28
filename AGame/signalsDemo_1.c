#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

#define MAXSIZE 200

void int_handar(int);
void quit_handar(int);

int main()
{
	char input[MAXSIZE];
	int num;
	signal(SIGINT, int_handar);
	signal(SIGQUIT, quit_handar);

	do{
		
		num = read(0, input, MAXSIZE-1);
		if(num == -1)
		{
			perror("read()");
		}
		else
		{
			input[num] = '\0';
			printf("your input: %s\n", input);
		}

	}while(strncmp(input, "exit", 4)!=0);
}

void int_handar(int signum)
{
	printf("\nget the signal: %d int\n", signum);
	for(int i=1; i<5; i++)
	{
		printf("int_handar sleep:\t%d\n", i);
		sleep(1);
	}
	printf("int_handar() Done\n");
}

void quit_handar(int signum)
{
	printf("\nget the signal: %d qiut\n", signum);
	for(int i=1; i<10; i++)
	{
		printf("quit_handar sleep:\t%d\n", i);
		sleep(1);
	}
	printf("\nquit_handar() Done\n");
}
