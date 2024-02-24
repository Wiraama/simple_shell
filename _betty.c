#include "shell.h"

/**
 * betty_check - main entry point
 * @word: aargument1
 *
 * Return: to main
 */
void betty_check(char *word)
{
	word = "my name is wiriama";

	while (*word)
	{
		printf("%c", *word);
		word++;
	}
	printf("\n");

	return;
}
