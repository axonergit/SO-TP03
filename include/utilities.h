#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

#define ERROR_CODE -1
#define ERROR_MESSAGE_SIZE 50

#define SUCCESS 0

void errorHandler(const char * src, const char * msg);

#endif