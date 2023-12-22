#include "main.h"

/**
  * add_process -  add a new new process to the process list
  * @pid: the id of the new process
  * @command: the command of the new process
  */

void add_process(pid_t pid, char *command)
{
	process_node *new_node = malloc(sizeof(process_node));
	process_node *process_list = NULL;

	if (new_node == NULL)
	{
		exit(-1);
	}
	new_node->pid = pid;
	strcpy(new_node->command, command);
	new_node->status = 0;
	new_node->next = NULL;

	if (process_list == NULL)
	{
		process_list = new_node;
	}
	else
	{
		new_node->next = process_list;
		process_list = new_node;
	}
	free(new_node);
}
