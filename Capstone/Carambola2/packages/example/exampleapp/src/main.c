
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv)
{
	printf("Hello World! Forking to background now and exit in one minute.\n");

	pid_t result = fork();

	if (result == -1)
	{
		fprintf(stderr, "Failed to fork: %s.", strerror(errno));
		return 1;
	}
	else if (result == 0)
	{
		//Create a session and set the process group id.
		setsid();

		//Just sleep a minute and exit the daemon.
		sleep(60);
	}
	else
	{
		//parent
		return 0;
	}
}
