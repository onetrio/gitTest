#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void my_exit1(void),my_exit2(void);//终止处理程序

int main(void){
	if (atexit(my_exit2) != 0)
		perror("can't register my_exit2");
	if (atexit(my_exit1) != 0)
		perror("can't register my_exit1");
	if (atexit(my_exit1) != 0)
		perror("can't register my_exit1");

	printf("main is done\n");
	return 0;
}

static void my_exit1(void)
{
	printf("first exit handler\n");
}

static void my_exit2(void)
{
	printf("second exit handler\n");
}
