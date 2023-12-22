#include "main.h"

/**
  * execute_command - executes a command
  * and adds the process to the process list
  *
  * @args: an array of arguments for the command to be executed
  */

void execute_command(char **args)
{
	pid_t pid;
	int status;
	char *path = "/bin/", *full_path;

	if (args[0] == NULL)
		return;
	if (args[0][0] == '/' || args[0][0] == '.')
		full_path = args[0];
	else
	{
		full_path = malloc(strlen(path) + strlen(args[0]) + 1);
		if (full_path == NULL)
		{
			perror("malloc failed");
			exit(2);
		}
		strcpy(full_path, path);
		strcat(full_path, args[0]);
	}
	pid = fork();
	if (pid == -1)
	{
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(full_path, args, NULL) == -1)
		{
			perror("execute failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		add_process(pid, args[0]);
		waitpid(pid, &status, 0);
		remove_process(pid);
	}
	if (args[0][0] != '/' || args[0][0] != '.')
		free(full_path);
}
