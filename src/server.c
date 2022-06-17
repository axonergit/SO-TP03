#include "server.h"

static int letTheGamesBegin(int fdClient);
static int levelsHandler(FILE * serverInput);

int main(int argc, char * argv[]) {

    struct sockaddr_in address;
    int fdServer = buildServer(&address);
    int fdClient = connectSocket(&address, sizeof(address), fdServer);
    closeSocket(fdServer);

    letTheGamesBegin(fdClient);

    return SUCCESS;
}

static int letTheGamesBegin(int fdClient) {

    FILE * serverInput = fdopen(fdClient, "r");
    if(serverInput == NULL) {
        errorHandler(SRC_ERROR_SERVER, "Open stream failed");
    }
    
    levelsHandler(serverInput);
    printf("Felicitaciones, finalizaron el juego. Ahora deberán implementar el servidor que se comporte como el servidor provisto\n");

    if(fclose(serverInput) == ERROR_CODE) {
        errorHandler(SRC_ERROR_SERVER, "Close stream failed");
    }

    return SUCCESS;
}

static int levelsHandler(FILE * serverInput) {

    char serverBuffer[BUFFER_SIZE] = {0};
    int currentLevel = 0;

    while(currentLevel < TOTAL_LEVELS) {

        printf("------------- DESAFIO -------------\n");

        // TODO solve challenge with input

        memset(serverBuffer, 0, BUFFER_SIZE);
        // TODO clean screen
    }

    return SUCCESS;
}