#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/stat.h>

void ls(struct stat*);
int main(int argc, char* argv[])
{
	struct stat sb;
	
	if(argc == 1)
	{
		perror("Error: argc is 1!");
		exit(1);	
	}
	
	int i = 1;
	char* p = argv[i];
	for(; i<argc; i++, p=argv[i])
	{
		stat(p, &sb);
		printf("%s\n", argv[i]);
		ls(&sb);
	}
	return 0;
}

void ls(struct stat* sb)
{
	printf("mode:\t%lo\n", (unsigned long)sb->st_mode);
	printf("links:\t%ld\n", (long)sb->st_nlink);
	printf("user:\t%ld\n", (long)sb->st_uid);
	printf("group:\t%ld\n", (long)sb->st_gid);
	printf("size:\t%lld\n", (long long)sb->st_size);
	printf("last change time:\t%s\n", ctime(&(sb->st_ctime)));
}
