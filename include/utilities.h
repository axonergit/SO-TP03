#ifndef UTILITIES_H
#define UTILITIES_H

#define  _GNU_SOURCE
#define  _POSIX_C_SOURCE 200809L

#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 100

#define ERROR_CODE -1
#define ERROR_MESSAGE_SIZE 50

#define SUCCESS 0

#define WAIT_SECONDS 3

void errorHandler(const char * src, const char * msg);

#endif