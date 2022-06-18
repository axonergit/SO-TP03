#ifndef LEVELS_H
#define LEVELS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define ERROR -1

#define STDOUT 1
#define STDERR 2

int level1(char *ans, size_t ansLen, FILE *input);
int level2(char *ans, size_t ansLen, FILE *input);
int level3(char *ans, size_t ansLen, FILE *input);
int level4(char *ans, size_t ansLen, FILE *input);
int level5(char *ans, size_t ansLen, FILE *input);
int level6(char *ans, size_t ansLen, FILE *input);
int level7(char *ans, size_t ansLen, FILE *input);
int level8(char *ans, size_t ansLen, FILE *input);
int level9(char *ans, size_t ansLen, FILE *input);
int level10(char *ans, size_t ansLen, FILE *input);
int level11(char *ans, size_t ansLen, FILE *input);
int level12(char *ans, size_t ansLen, FILE *input);


#endif