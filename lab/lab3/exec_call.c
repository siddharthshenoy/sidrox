#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t forkStatus;

	char *args[argc];
	for (int i=0; i<argc; ++i) {
		args[i] = argv[i+1];
	}
	args[argc-1] = NULL;

	forkStatus = fork();

	if(forkStatus == 0) {
		execvp(args[0], args);
	} else {
		printf("Child process is running\n");
		wait(NULL);
		printf("Child process is DONE \n");
	}

	return 0;
}
