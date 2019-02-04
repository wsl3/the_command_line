#include<stdio.h>
#include<stdlib.h>//use exit()
#include<utmp.h> //structure of login record
#include<fcntl.h> // open()
#include<unistd.h> // read() and close()

void show_info(struct utmp*);

int main(int argc, char * argv[])
{
	struct utmp current_utmp;
	int fp;
	int size = sizeof(current_utmp);
	//open the file and get the descripter
	if((fp = open(UTMP_FILE, O_RDONLY)) == -1)
	{
		perror(UTMP_FILE);
		exit(1);
	}
	
	//read if open is success
	while(read(fp, &current_utmp, size) == size)
	{
		show_info(&current_utmp);
	}
	close(fp);	
	return 0;
}

void show_info(struct utmp* ut)
{
	printf("username:%-10s", ut->ut_name);
	printf("device:%-10s", ut->ut_line);
	printf("host:%-10s\n", ut->ut_host);
}
