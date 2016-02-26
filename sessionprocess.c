//会话进程
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(){
	pid_t pid;

	if((pid = fork()) < 0){
		perror("fork error!");
		exit(1);
	}
	else if(pid == 0){
		printf("The child process PID is %d.\n",getpid());
		printf("The Group ID of child id %d.\n",getpgrp());
		printf("the session id of child is %d.\n",getsid(0));
		sleep(10);
		setsid();//子进程非组长进程，故其成为新会话首进程，且成为组长进程，该进程id即为会话进程
		//该进程不再控制终端
		printf("Changed:\n");
		printf("The child process PID id %d.\n",getpid());
		printf("The Group Id of child id %d.\n",getpgid(0));
		printf("the session id of child is %d.\n",getsid(0));
		sleep(10);
		exit(0);	
	}
	return 0;
}
