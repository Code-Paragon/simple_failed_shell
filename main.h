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
int _getline(char *buffer);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
char *_strdup(char *str);
int printenv(void);

#endif /* MAIN_H */
