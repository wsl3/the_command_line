#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<wait.h>
#include<unistd.h>

#define TIME 6

void child_process(int);
void parent_process(int);

int main()
{
	int child;
	printf("parrent pid:\t%d\n", getpid());
    
	if( (child=fork()) == -1)
	{
		perror("fork error!");
		exit(1);
	}
	else if( child == 0)
	{
		child_process(TIME);
	}
	else
	{
		parent_process(child);
	}
	return 0;
}

void child_process(int t)
{
	printf("pid:\t%d\ti'am child,i will wait %d seconds\n", getpid(), t);
	sleep(t);
	exit(17);
}

void parent_process(int child)
{
	int returned;
	int child_status;

	returned = wait(&child_status);
	printf("pid:\t%d\ti'am parent,i'am waiting for %d, returned:%d\n", getpid(), child, returned);
	
	int exit_value = child_status & 0xFF00;
	int signal_number = child_status & 0x7F;
	int core_dump_flag = child_status & 0x80;

	printf("exit_value: %d\tcore_dump_flag: %d\tsignal_number: %d\n", exit_value, core_dump_flag, signal_number);
}
