#include "shell.h"


char** token_command(char *command)
{
	char *token;
	int i;
	char **args = (char **)malloc((MAX_ARGS + 1) * sizeof(char*));

	if (args == NULL)
	{
		exit(EXIT_FAILURE);
	}

	token = strtok(command, " "); /** slicing command **/

	i = 0;
	/** loop to take tokenize token to array **/
	while (token != NULL && i < MAX_ARGS)
	{
		args[i] = strdup(token); /** copying token to array **/
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL; /** to terminate the argument **/

	return (args);
}
