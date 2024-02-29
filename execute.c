#include "shell.h"



int command_execute(char **args)
{
	pid_t pid = fork(); /** duplicating program **/
	int status, status_exited;

	/** cheking duplicate is successful **/
	if (pid == -1)
	{
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		/** allow copied program or child nprocess **/
	{
		if (execvp(args[0], args) == -1) /** checking if command is executed **/
		{
			exit(EXIT_FAILURE);
		}
	}
	else
		/** to original program or parent process **/
	{
		waitpid(pid, &status, 0); /** wait for child to finish **/
		if (WIFEXITED(status))
		{
			status_exited = WEXITSTATUS(status); /**check exit status to child process **/
			if (status_exited != 0)
			{
				printf("Error: command %s not found\n", args[0]);
			}
			else if (status_exited == -1)
			{
				printf("Error: command '%s' misbehaved\n", args[0]);
			}
		}
	}
	return (status_exited);
}
