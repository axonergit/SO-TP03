// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "client.h"
#include <stdio.h>


static int getInput(int fdServer);

int main(int argc, char * argv[]) {

    struct sockaddr_in address;
    int fdServer = openSocket(&address);
    connectClient(&address, sizeof(address), fdServer);

    getInput(fdServer);

    return SUCCESS;
}

static int getInput(int fdServer) {

    char * clientInput = (char *) malloc((BUFFER_SIZE+1) * sizeof(char));
    size_t cInputLength = BUFFER_SIZE;

    if(clientInput == NULL) {
        errorHandler(SRC_ERROR_CLIENT, "Allocate memory failed");
    }
    memset(clientInput, 0, cInputLength);

    printf("Mi respuesta: ");

    int leave = 0;
    while (!leave) {
        printf("Ingrese su respuesta: ");

        memset(clientInput, 0, cInputLength);

        int previousErrno = errno;
        if (getline(&clientInput, &cInputLength, stdin) == ERROR_CODE) {
            if (previousErrno == errno) {
                leave = 1;
            } else {
                errorHandler(SRC_ERROR_CLIENT, "Getline failed");
            }
        }

        if (!leave) {
            int readChars = strlen(clientInput);
            if (readChars > 0) {
                int sentChars = write(fdServer, clientInput, readChars);
                if (sentChars == ERROR_CODE) {
                    errorHandler(SRC_ERROR_CLIENT, "Write failed");
                }
                if (sentChars == 0) {
                    leave = 1;
                }
            }
        }
    }

    printf("Se cierra cliente.\n");
    closeSocket(fdServer);
    free(clientInput);

    return SUCCESS;
}