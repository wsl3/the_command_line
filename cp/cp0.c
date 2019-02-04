#include<stdio.h>
#include<stdlib.h> // exit()
#include<fcntl.h> // open() and creat()
#include<unistd.h> // write() read() and close()

#define MODEL_CREAT 0644
#define READ_BYTES 4096

void print_error(char*, char*);

int main(int argc, char *argv[])
{	
	char bytes[READ_BYTES];	
	int fp_source;
	int fp_target;
	int chars;
	if(argc != 3)
	{
		fprintf(stderr, "Eooro:argc is not 3!\n");
		exit(1);
	}
	if((fp_source = open(argv[1], O_RDONLY)) == -1)
	{
		print_error("cant't open the source file!", argv[1]);
	}
	if((fp_target = creat(argv[2], MODEL_CREAT)) == -1)
	{
		print_error("can't creat the target file!", argv[2]);
	}

	//open() and creat() are sucessful
	while((chars = read(fp_source, bytes, READ_BYTES)) > 0)
	{
		if(write(fp_target, bytes, READ_BYTES) == -1)
		{
			print_error("can't write to the target file!", argv[2]);
		}
	}
	//it's wrong if read() return -1
	if(chars == -1)
	{
		print_error("can't read the source file!", argv[1]);
	}
	
	close(fp_source);
	close(fp_target);
	return 0;
}

void print_error(char *p1, char *p2)
{
	fprintf(stderr, "Error:%s\n", p1);
	perror(p2);
	exit(1);
}
