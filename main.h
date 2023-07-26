#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

char *_strcpy(char *dest, const char *src);
int _strlen( const char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char **split_tok(char *line, int nbytes);
int exec(char **av);
char *get_path(char *cmd);
void exit_sshell(void);
char *_getenv(char *name);
void print_env(void);
extern char **environ;
#endif
