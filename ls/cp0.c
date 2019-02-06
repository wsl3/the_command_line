#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>

void ls(char*);
int main(int argc, char *argv[])
{
//	struct dirent* p;
//	DIR* dir
	
	if(argc == 1)
	{
		ls(".");
	}
	else
	{
		int i = 1;
		char* dir = argv[1];
		while(i <= argc-1)
		{
			printf("%s:\n", dir);
			ls(dir);
			i++;
			dir = argv[i];
		}
	}
	
	return 0;
}

void ls(char* direct)
{
	DIR* dir;
	struct dirent* p;
	if((dir = opendir(direct)) == NULL)
	{
		fprintf(stderr, "opendir error!");
		exit(1);
	}
	while((p = readdir(dir)) != NULL)
	{
		printf("%s\n", p->d_name);
	}
	closedir(dir);
}
