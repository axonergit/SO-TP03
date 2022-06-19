// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "utilities.h"

void errorHandler(const char * src, const char * msg) {
    char final[ERROR_MESSAGE_SIZE] = {0};
    strcat(final,"ERROR at ");

    if(src == NULL) {
        strcat(final,"UNKNOWN");
    } else {
        strcat(final,src);
    }

    strcat(final," - ");
    strcat(final,msg);
    strcat(final,".\n");

    perror(final);
    exit(EXIT_FAILURE);
}