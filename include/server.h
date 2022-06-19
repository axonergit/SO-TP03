#ifndef SERVER_H
#define SERVER_H

#include "levels.h"
#include "socketLib.h"
#include "utilities.h"

#define SRC_ERROR_SERVER "Server"
#define TOTAL_LEVELS 12

typedef int (* level)(char * ans, size_t ansLen, FILE *input);

#endif