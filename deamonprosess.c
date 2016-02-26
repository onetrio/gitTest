#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <iostream>

int main(){
	pid_t pid;
	int i,fd;
	const char *buf = "This is a daemon program.\n";
	
	if((pid = fork()) < 0) {
		perror("fork error!");
		exit(1);
	}else if(pid > 0 ){
		exit(0);	
	}
	
	setsid();	//在子进程中建立新会话
	chdir("/");	//设置工作目录为根
	umask(0);	//设置权限掩码
	for( i = 0;i < getdtablesize();i++)//getdtablesize返回子进程文件描述符表的项数
		close(i);	//关闭这些不将用到的文件描述符
	while(1){
		if((fd = open("/tmp/daemon22.log",O_CREAT|O_WRONLY|O_APPEND,0600)) < 0 ){
			perror("open file error!\n");
		}
		
		//将buf写到fd中
		write(fd,buf,strlen(buf)+1);
		close(fd);
		sleep(10);
		printf("Never output!\n");
	}
}


