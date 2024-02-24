#include "shell.h"

int main(int argc, char *argv[])
{
	(void)argv;

	if (argc > 1)
	{
		/** not interactive **/
		char command[MAX_COMMAND_LENGTH];

		/** loop to get command and execute **/
		while (fgets(command, MAX_COMMAND_LENGTH, stdin) != NULL)
		{
			command[strcspn(command, "\n")] = '\0';

			/** executing command **/
			unix_interpreter(command);
		}
	}
	else
	{
		char command[MAX_COMMAND_LENGTH]; /** interactive**/
		while (1)
		{
			printf("$ ");
			fflush(stdout);

			/** getting command fron user **/
			if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
			{
				printf("\n");
				printf("Exiting...\n");
				return (0);
		}
			/** removing new line **/
			command[strcspn(command, "\n")] = '\0';

			/** checking exit command **/
			if (strcmp(command, "exit") == 0)
			{
				printf("\n");
				printf("Exiting...\n");

				sleep(2);

				return (0);
			}
			unix_interpreter(command);
		}
	}
	return (0);
}
