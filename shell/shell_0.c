#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define MAXARGLIST 20
#define MAXLEN 100

char* make_string(char buffer[]);
void execte(char* arglist[]);

int main(int argc, char* argv[])
{
	int argsNum = 0; //arglist[]的下标
	char buffer[MAXLEN]; //这里不是char* buffer; 否则会发生段错误
	char* arglist[MAXARGLIST+1];

	while( argsNum < MAXARGLIST )
	{
		printf("Args[%d]$:", argsNum);
		//arg 不是"\n" 并且读取成功
		if( fgets(buffer, MAXLEN, stdin) && buffer[0] != '\n')
		{
		    arglist[argsNum++] = make_string(buffer);
		}
		else
		{
			if(argsNum>0){
				arglist[argsNum] = NULL;
				execte(arglist);
				argsNum = 0; //下标重置
			}
		}	
	}
	return 0;
}

char* make_string(char buffer[])
{
    //不太明白为什么 buffer和cp的值一样, 但是返回buffer不行
    buffer[strlen(buffer)-1] = '\0'; //去掉fgets读入的换行符
    char* cp;
    cp = malloc(strlen(buffer)+1);
    if(cp == NULL){
	    perror("Error: no memory!");
	    exit(1);
    }
    strcpy(cp, buffer);
/*    char* t =cp;
    char* p = buffer;
    for(;*buffer!='\0' && *t!='\0'; buffer++, t++)
    {
	    printf("buffer:\t%c\tcp:\t%c\n", *buffer, *t);
    }*/
    return cp;
}

void execte(char* arglist[])
{
    if(execvp(arglist[0], arglist) == -1){
	    perror("Error: execvp error!");
	    exit(1);
    }
}
