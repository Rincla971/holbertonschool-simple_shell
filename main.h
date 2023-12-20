#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
void afficher_prompt(void);
char *lire_ligne(void);
void executer_commande(char *line);
void perror_exit(char *msg);

#endif /* MAIN_H */
