#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc, char* argv[])
{
	struct stat sb;
	if(stat("/home/wsl/projects", &sb) == -1)
	{
		perror("/home/wsl/projects error!");
		exit(1);
	}
	//success
	printf("sb.st_size: %lld bytes!", (long long)sb.st_size);
	return 0;
}
