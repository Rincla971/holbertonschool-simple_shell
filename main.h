#ifndef __SHELL__MAIN__
#define __SHELL__MAIN__
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stddef.h>
#include <string.h>

typedef struct node
{
	pid_t pid;
	char command[256];
	int status;
	struct node *next;
} process_node;

extern char **environ;
void add_process(pid_t pid, char *command);
void remove_process(pid_t pid);
void execute_command(char **args);
void read_command(char **command, size_t *len);

#endif
