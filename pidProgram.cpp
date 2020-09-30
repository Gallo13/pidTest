#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t pid, pid1;

	/* fork a child process */
	pid = fork();

	if (pid < 0)
	{
		/* Error Occurred */
		fprintf(stderr, "Fork Failed");
		return 1;
	}
	else if (pid == 0)
	{
		/* Child Process */
		pid1 = getpid();
		printf("child: pid = %d", pid); /*A*/
		printf("child: pid1 = %d", pid1); /*B*/
	}
	else
	{
		/* Parent Process */
		pid1 = getpid();
		printf("parent: pid = %d", pid); /*C*/
		printf("parent: pid1 = %d", pid1); /*D*/
		wait(NULL);
	}
	return 0;
}
