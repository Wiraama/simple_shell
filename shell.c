#include "shell.h"


int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char **args;
	char cwd[1024];

	printf("$ ");
	fflush(stdout); /** keeps accepting the command without exiting **/

	while(1)
	{
		/** geting end of file **/
		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}

		/** removing white space **/
		command[strcspn(command, "\n")] = '\0';
	
		/** parsing command to argyument **/
		args = token_command(command);

		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				printf("Exitting...\n");
				sleep(2);
				break;
			}
			else if (strcmp(args[0], "cd") == 0)
			{
				if (args[1] == NULL)
				{
					printf("Error: no directory provided\n");
				}

				else
				{
					if (chdir(args[1]) == 0)
					{
						/** directory changed **/
						if (getcwd(cwd, sizeof(cwd)) != NULL)
						{
							printf("/%s ", cwd);
							fflush(stdout);
						}
						else {
							perror("getcwd");
						}
					}
					else
					{
						perror("chdir");
					}
				}
			}
			else
			{
				command_execute(args);
			}
		}
		/** display prompt again **/
		printf("$ ");
		fflush(stdout);
	}

	return (0);
}
