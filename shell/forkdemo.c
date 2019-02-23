#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int current_pid, child_process;
	current_pid = getpid();
	printf("before fork:\t%d\n", current_pid);

	child_process = fork();
	printf("after fork:\n\tcurrent_pid: %d\n\tchild_process: %d\n", getpid(), child_process);

	return 0;
}
