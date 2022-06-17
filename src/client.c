#include "client.h"

static int getInput(int fdServer);

int main(int argc, char * argv[]) {

    struct sockaddr_in address;
    int fdServer = openSocket(&address);
    connectClient(&address, sizeof(address), fdServer);

    getInput(fdServer);

    return SUCCESS;
}

static int getInput(int fdServer) {

    char clientInput[BUFFER_SIZE] = {0};

    while(fgets(clientInput, BUFFER_SIZE - 1, stdin) != NULL) {

        printf("Mi respuesta: ");

        if(send(fdServer, clientInput, BUFFER_SIZE, 0) == ERROR_CODE) {
            errorHandler(SRC_ERROR_CLIENT, "Send message to server failed");
        }

        memset(clientInput, 0, BUFFER_SIZE);
    }

    printf("Se cierra cliente.\n");
    closeSocket(fdServer);
    return SUCCESS;
}