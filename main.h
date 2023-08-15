#ifndef MAIN_H
#define MAIN_H 

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int shell(char *, char *const [], size_t, ssize_t, char[], char *[], int, int, int, pid_t);

#endif /* MAIN_H */
