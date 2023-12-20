#include "main.h"

void executer_commande(char *line)

{
    pid_t pid_enfant;
    int status;
    pid_enfant = fork();
    if (pid_enfant == -1)
    {
        perror_exit("Erreur création processus enfant");
        exit(EXIT_FAILURE);
    }
    if (pid_enfant == 0)  /*Processus enfant*/
    {
        if (execve(line, NULL, environ) == -1)
        {
            perror_exit("Commande introuvable");
            exit(EXIT_FAILURE);
        }
    }
    else  /*Processus parent*/
    {
        waitpid(pid_enfant, &status, 0);
    }
}
