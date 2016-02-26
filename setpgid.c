//父进程改变自身和子进程的组id

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(){
	pid_t pid;
	
	if( (pid = fork()) < 0){
		printf("fork error!");
	}else if(pid == 0){
		printf("The child process PID is %d.\n",getpid());
		printf("The Group ID of child is %d.\n",getpgrp());
		sleep(5);
		printf("The Group ID of child id changed to %d.\n",getpgid(0));
		exit(0);
	}
	sleep(1);
	printf("The parent process PID is %d.\n",getpid());
	printf("The parent of parent process PID is %d.\n",getppid());
	printf("The Group ID of parent is %d.\n",getpgrp());
	setpgid(getpid(),getppid());//改变父进程的组ID为父进程的父进程
	printf("The Group ID of parent is changed to %d.\n",getpgid(0));

	return 0;


}

