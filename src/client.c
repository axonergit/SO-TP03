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

    char * clientInput = malloc(BUFFER_SIZE * sizeof(char));
    int cInputLength = BUFFER_SIZE;

    if(clientInput == NULL) {
        errorHandler(SRC_ERROR_CLIENT, "Allocate memory failed");
    }
    memset(clientInput, 0, cInputLength);

    printf("Mi respuesta: ");

    while(fgets(clientInput, cInputLength - 1, stdin) != NULL) {        

        if(send(fdServer, clientInput, cInputLength, 0) == ERROR_CODE) {
            errorHandler(SRC_ERROR_CLIENT, "Send message to server failed");
        }
        
        printf("Mi respuesta: ");
        memset(clientInput, 0, cInputLength);
    }

    printf("Se cierra cliente.\n");
    closeSocket(fdServer);
    free(clientInput);

    return SUCCESS;
}