// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "server.h"

static int letTheGamesBegin(int fdClient);
static int levelsHandler(FILE * serverInput);

int main(int argc, char * argv[]) {

    struct sockaddr_in address;
    int fdServer = buildServer(&address);
    int fdClient = connectSocket(&address, sizeof(address), fdServer);

    letTheGamesBegin(fdClient);
    closeSocket(fdServer);

    return SUCCESS;
}

static int letTheGamesBegin(int fdClient) {

    FILE * serverInput = fdopen(fdClient, "r");
    if(serverInput == NULL) {
        errorHandler(SRC_ERROR_SERVER, "Open stream failed");
    }
    
    levelsHandler(serverInput);
    printf("Felicitaciones, finalizaron el juego!\n\n");

    if(fclose(serverInput) == ERROR_CODE) {
        errorHandler(SRC_ERROR_SERVER, "Close stream failed");
    }

    return SUCCESS;
}

static int levelsHandler(FILE * serverInput) {

    char * serverBuffer = (char *) malloc(BUFFER_SIZE * sizeof(char));
    size_t sBufferLength = BUFFER_SIZE;

    if(serverBuffer == NULL) {
        errorHandler(SRC_ERROR_SERVER, "Allocate memory failed");
    }

    srand((int) time(NULL));
    int currentLevel = 0;
    level levels[TOTAL_LEVELS] = {level1, level2, level3, level4, level5,
                level6, level7, level8, level9, level10, level11, level12};

    while(currentLevel < TOTAL_LEVELS) {

        memset(serverBuffer, 0, sBufferLength);
        int goToNextLevel = levels[currentLevel](serverBuffer, sBufferLength, serverInput);

        if (goToNextLevel) {
            currentLevel++;
        } else {
            printf("\nLa  respuesta es incorrecta. Pruebe de nuevo en 3.. 2.. 1..\n");
            sleep(WAIT_SECONDS);
        }

        system("clear");
    }

    free(serverBuffer);

    return SUCCESS;
}