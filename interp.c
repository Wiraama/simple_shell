#include "shell.h"

void unix_interpreter(char *command)
{
	pid_t pid = fork();
	pid_t wpid;
	int status;
	char *argv[2];

	if (pid < 0) /** if fork fails **/
	{
		perror("fork");
	}
	else if (pid == 0) /**child process **/
	{
		argv[0] = command;
		argv[1] = NULL;
		if (execvp(command, argv) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/** parent process **/
		wpid = waitpid(pid, &status, 0);
		if (wpid == -1)
		{
			perror("waitpid");
		}
	}
}
