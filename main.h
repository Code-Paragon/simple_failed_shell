#ifndef MAIN_H
#define MAIN_H 

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int shell(char *, char *const [], size_t, ssize_t, char[], char *[], int, int, int, pid_t);
char *handle_path(char *command);

#endif /* MAIN_H */
