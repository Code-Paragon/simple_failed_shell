#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

extern char **environ;

int shell(char *const envp[], char *inputstr, char **args, char **front);
char *handle_path(char *command);
int execute(char *fraginputstr[], char *const envp[]);
char **_getenv(char *name);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
char *_strdup(char *str);
ssize_t _getline(char **inputstr, size_t *m, FILE *stream);
int com_cd(char **args, char __attribute__((__unused__)) **front);
int com_env(char **args, char __attribute__((__unused__)) **front);
int com_setenv(char **args, char __attribute__((__unused__)) **front);
int com_unsetenv(char **args, char __attribute__((__unused__)) **front);
char *_strtok(char *str, const char *delim);
int _atoi(char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
int shell_exit(char **args);
/**
 * struct Plugin_s - A new struct type defining builtin commands.
 * @comName: The name of the builtin command.
 * @comFunc: A function pointer to the builtin command's function.
 */
typedef struct Plugin_s
{
	char *comName;
	int (*comFunc)(char **argv, char **front);
} Plugin_t;
/**
 * struct dirList_s - A new struct type defining a linked list.
 * @direc: A directory path.
 * @dirNext: A pointer to another struct list_s.
 */
typedef struct dirList_s
{
	char *direc;
	struct dirList_s *dirNext;
} dirList_t;

int (*get_Plugin(char *command))(char **args, char **front);

#endif /* MAIN_H */
