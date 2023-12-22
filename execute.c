#include "shell.h"

/**
 * execute - execute the command
 * @args: array of arguments -> command and arguments
 * Description: compares the command with the built-in commands and executes
 * Return: 0 in success or EXIT_FAILURE
 */

int execute(char **command_arguments) {
    pid_t child_pid;
    int status;

    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        return -1; /* Indicates an error */
    }

    if (child_pid == 0) {
        /* Code for the child process */
        execvp(command_arguments[0], command_arguments);
        perror(command_arguments[0]); /* execvp failed */
        exit(2); /* Exit with status 2 if execvp fails */
    } else {
        /* Code for the parent process */
        waitpid(child_pid, &status, 0);

        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);

            if (exit_status == 2) {
                return -1; /* Indicates command not found */
            }
        } else {
            perror("waitpid");
            return -1; /* Indicates an error */
        }
    }

    return 0; /* Indicates success */
}
