#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(){

	pid_t pid;
	
	if ((pid = fork()) < 0){
		perror("fork error");
	}else if (pid == 0){
		printf("The child process PID id %d.\n",getpid());
		printf("The Groupe ID is %d.\n",getpgrp());
		printf("The Groupe ID is %d.\n",getpgid(0));
		printf("The Groupe ID is %d.\n",getpgid(getpid()));
		exit(0);
	}
	
	sleep(3);
	printf("The parent process PID id %d.\n",getpid());
	printf("The Groupe ID id %d.\n",getpgrp());
	return 0;
}
