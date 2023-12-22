#include "shell.h"

/**
 * readLine - read a line from stdin
 * Description:
 * Use getline function to get the input user from stdin
 * Getline will dynamically allocate memory and update input_line
 * Getline return the number of characters read and store it in nb_char_line
 * Return: the line on success or NULL on failure (char *)
 */
char *readLine(void)
{
	/* Variables */
	char *input_line = NULL; /* Stores the user input */
	size_t size_line = 0; /* Stores the size of the input line */
	ssize_t read; /* Stores the number of characters read by getline()*/

	/* Use getline to read the line from stdin and store it in input_line */
	/* getline will dynamically allocate memory and update size_line */
	read = getline(&input_line, &size_line, stdin);

	/* Error handling : check if getline failed */
	if (read == -1) /* -1 means EOF or error */
	{
		if (feof(stdin)) /* it's EOF */
		{
			printf("Exiting the shell.\n"); /* Print a error message */
			free(input_line); /* Free the memory of input_line variable */
			exit(EXIT_SUCCESS); /* Exit with status 0 */
		}
		else
		{
			perror("Failed to read the command\n"); /* Print a error message */
			free(input_line); /* Free the memory of input_line variable */
			return (NULL); /* Return NULL on failure */
		}
	}
	return (input_line); /* Return the line on success */
}
