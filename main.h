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

#endif /* MAIN_H */
