#ifndef SHELL_H
#define SHELL_H
/* include guard -> prevent double inclusion */

/* ----------Libraries---------- */
#include <stdio.h> /* printf, fprintf, stderr */
#include <stdlib.h> /* malloc, free, exit */
#include <stdbool.h> /* boolean data type */
#include <unistd.h> /* fork, execve, access, isatty, chdir */
#include <string.h> /* strcmp, strtok, strdup */
#include <sys/wait.h> /* wait */
#include <sys/stat.h> /* stat */

/* ----------Macros---------- */
extern char **environ; /* Extern -> array of strings of env variable */
#define BUFSIZE 1024 /* Buffer size */
#define SPACE ' ' /* Shorthand -> Space */
#define TAB '\t' /* Shorthand -> Tab */

/* ----------Prototypes---------- */
/* shell.c */
void printPrompt(void);
/* ReadLine.c */
char *readLine(void);
/* parseLine.c */
char **parseLine(char *line);
/* handle_input.c */
int emptyLine(char *line);
/* execute.c */
int execute(char **args);
/* get_env.c */
char *getEnv(char *name);
/* getPath.c */
char *getPath(char *file);
/* free2.c */
void freeDP(char **args);
/* free2.c */
void freeMemory(char **tokens, size_t count);

#endif
