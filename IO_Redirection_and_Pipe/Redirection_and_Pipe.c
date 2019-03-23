//
// Created by wsl on 19-3-23.
// 输入: 'a.out who sort'

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc, char *argv[]) {
    int pipefd[2];
    int pid;

    //检查参数
    if(argc != 3){
        perror("参数错误!");
        exit(1);
    }

    // 建立pipe
    if (pipe(pipefd) == -1) {
        perror("pipe建立通道失败!");
        exit(1);
    }

    //创建子进程
    if ((pid = fork()) == -1) {
        perror("创建子进程失败!");
        exit(1);
    }

    //父进程执行代码
    if (pid > 0) {
        close(pipefd[1]);
        //改变父进程的标准输入
        close(0);
        int newpidP = dup(pipefd[0]);
        close(pipefd[0]);
        execlp(argv[2], argv[2], NULL);

    } else   //子进程执行代码
    {
        close(pipefd[0]);
        close(1);
        int newpidC = dup(pipefd[1]);
        close(pipefd[1]);
        execlp(argv[1], argv[1], NULL);
    }


    return 0;
}