#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

#define BUF_SIZE 100

int main()
{
	int t = 0;
	char buf[BUF_SIZE];

	printf("Enter number of terms\n");
	scanf("%d", &t);

	pid_t forkStatus;
	forkStatus = fork();

	if (forkStatus == 0) {
		int a = 0; int b = 1;
		if (t <= 0){
			sprintf(buf, "No terms to print.\n");
			write(1, buf, strlen(buf));
		} else if (t == 1) {
			sprintf(buf, "%d \n", a);
			write(1, buf, strlen(buf));
		} else if (t == 2) {
			sprintf(buf, "%d %d \n", a, b);
			write(1, buf, strlen(buf));
		} else {
			sprintf(buf, "%d %d ", a, b);
			write(1, buf, strlen(buf));
			for (int i=0; i<t-2; ++i) {
				sprintf(buf, "%d ", a+b);
				write(1, buf, strlen(buf));
				b = b + a;
				a = b - a;
			}
			printf("\n");
		}
	} else {
		printf("Waiting for child process\n");
		wait(NULL);
		printf("Child process completed\n");
	}

	return 0;
}
