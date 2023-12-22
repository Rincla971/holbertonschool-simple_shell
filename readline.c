#include "main.h"

/**
* read_command - reads a command from standard input
* and removes the newline character at the end
*
* @command: pointer to a char pointer that will contain the command read
* @len: pointer to a size_t variable that contains the length of the command
*/

void read_command(char **command, size_t *len)
{
	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
	}
	if (getline(command, len, stdin) ==  -1)
	{
		if (command)
			free(*command);
		exit(0);
	}
	(*command)[strlen(*command) - 1] = '\0';
}
