#include "client.h"

int main(int argc, char * argv[]) {

    struct sockaddr_in address;
    int fdServer = openSocket(&address);
    connectClient(&address, sizeof(address), fdServer);

    // TODO wait for answers -> use fdServer

    return SUCCESS;
}