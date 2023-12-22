#include "main.h"

/**
 * remove_process - removes a process node from the process list
 * based on its PID
 *
 * @pid: the PID of the process to be removed
 */

void remove_process(pid_t pid)
{
	process_node *process_list = NULL;
	process_node *prev_process = NULL;
	process_node *current_process = process_list;

	while (current_process)
	{
		if (current_process->pid == pid)
		{
			if (prev_process == NULL)
			{
				process_list = current_process->next;
			}
			else
			{
				prev_process->next = current_process->next;
			}
			free(current_process);
			return;
		}
		prev_process = current_process;
		current_process = current_process->next;
	}
}
