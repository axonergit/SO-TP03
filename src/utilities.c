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