#include "server.h"

int main(int argc, char * argv[]) {

    struct sockaddr_in address;
    int fdServer = buildServer(&address);
    int fdClient = connectSocket(&address, sizeof(address), fdServer);
    closeSocket(fdServer);

    // TODO let the games begin -> uses fdClient

    return SUCCESS;
}