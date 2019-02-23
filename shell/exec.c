#include<stdio.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
	char* arglist[3];
	arglist[0] = "ls";
	arglist[1] = "-l";
	arglist[2] = NULL;
	
	printf("**** ls -l ****\n");
	execvp(arglist[0], arglist);
	printf("...Done\n");
	return 0;
}
