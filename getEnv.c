#include "shell.h"

/**
 * getEnv - gets an environ variable
 * @name: name of the environ variable to get
 * Description: the function loops through the environ variable
 * Return: Environ variable value or NULL if not found
 */
char *getEnv(char *name)
{

	int i; /* index for loop */
	int len = strlen(name); /* length of the environnement name in param */

	/* Loop through the environ variable */
	for (i = 0; environ[i] != NULL; i++)
	{
		/* Compare the environ variable with the name in param */
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (environ[i] + len + 1); /* return the value environ variable */
	}
	return (NULL); /* return NULL if not found */
}
