#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
	int a[10] = {18, 5, 36, 12, 56, 7, 2, 9, 11, 12};
	pid_t forkStatus;
	forkStatus = fork();

	if (forkStatus == 0) {
		int len = sizeof(a)/sizeof(int);
		int partial[len];

		for (int i=0; i<len; ++i) {
			partial[i] = 0;
			for (int j=i; j>=0; --j) {
				partial[i] += a[j];
			}
		}

		printf("Total is equal to %d\n", partial[len-1]);
	} else {
		printf("Waiting for child process to finish\n");

		wait(NULL);

		int len = sizeof(a)/sizeof(int);
		int partial[len];

		for (int i=0; i<len; ++i) {
			partial[i] = 1;
			for (int j=i; j>=0; --j) {
				partial[i] *= a[j];
			}
		}
		printf("Total product is equal to %d\n", partial[len-1]);
	}
}
