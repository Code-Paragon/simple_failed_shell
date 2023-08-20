#ifndef MAIN_H
#define MAIN_H 

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int shell(char *const envp[], char *inputstr);
char *handle_path(char *command);
int execute (char *fraginputstr[], char *const envp[]);
char *_getenv(const char *name);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
char *_strdup(char *str);
ssize_t _getline(char **inputstr, size_t *m, FILE *stream);
int printenv(void);
char *_strtok(char *str, const char *delim);

#endif /* MAIN_H */
