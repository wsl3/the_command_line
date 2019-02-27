#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sign_func(int signum);

int main(int argc, char* argv[])
{
	int i;
	for(i=0; i<4; i++)
	{
		printf("before the signal!\n");
		sleep(1);
	}
	/*
	   如果没有发生 ctrl+c 则信号函数会直接被忽略
	   如果在 signal() 函数定义之前按下 ctrl+C 会直接终止程序
	   在 siganl() 函数定义之后按下 ctrl+C 会触发相应的信号处理机制
	*/
	//signal(SIGINT, SIG_DFL);
	//signal(SIGINT, SIG_IGN);
	signal(SIGINT, sign_func);

	for(i=0; i<4; i++)
	{
		printf("after the signal!\n");
		sleep(1);
	}
	return 0;
}

void sign_func(int signum)
{
	printf("signal function is runing!\n");
}
