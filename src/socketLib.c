// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "socketLib.h"

int openSocket(struct sockaddr_in * address) {

    int fdServer = socket(AF_INET, SOCK_STREAM, 0);

    if(fdServer == ERROR_CODE) {
        errorHandler(SOURCE_ERROR_NAME, "Open socket failed");
    }

    memset(address, 0, sizeof(struct sockaddr_in));
    address->sin_family = AF_INET;
    address->sin_addr.s_addr = INADDR_ANY;
    address->sin_port = htons(MY_PORT);

    return fdServer;
}

int connectSocket(struct sockaddr_in * address, socklen_t length, int fdServer) {

    if(bind(fdServer, (struct sockaddr *) address, length) == ERROR_CODE) {
        errorHandler(SOURCE_ERROR_NAME, "Bind socket failed");
    }

    if(listen(fdServer, BACKLOG) == ERROR_CODE) {
        errorHandler(SOURCE_ERROR_NAME, "Listen socket failed");
    }

    int fdClient = accept(fdServer, (struct sockaddr *) address, &length);
    if(fdClient == ERROR_CODE) {
        errorHandler(SOURCE_ERROR_NAME, "Accept socket failed");
    }

    return fdClient;
}

int closeSocket(int fdSocket) {
    
    if(close(fdSocket) == ERROR_CODE) {
        errorHandler(SOURCE_ERROR_NAME, "Close socket failed");
    }

    return SUCCESS;
}

int buildServer(struct sockaddr_in * address) {
    
    int fdServer = openSocket(address);
    int opt = 1;

    if(setsockopt(fdServer, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == ERROR_CODE) {
        errorHandler(SOURCE_ERROR_NAME, "Set options on sockets failed");
    }

    return fdServer;
}

int connectClient(struct sockaddr_in * address, socklen_t length, int fdSocket) {

    if(inet_pton(AF_INET, LOCALHOST, &address->sin_addr) <= 0) {
        errorHandler(SOURCE_ERROR_NAME, "Invalid address");
    }

    if(connect(fdSocket, (struct sockaddr *) address, length) == ERROR_CODE) {
        errorHandler(SOURCE_ERROR_NAME, "Connection failed");
    }

    printf("Se conectó al cliente exitosamente\n");
    return SUCCESS;
}