#ifndef SOCKET_LIB_H
#define SOCKET_LIB_H

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include "utilities.h"

#define LOCALHOST "127.0.0.1"
#define MY_PORT 8080
#define SOURCE_ERROR_NAME "Socket Api"
#define BACKLOG 5

int openSocket(struct sockaddr_in * address);
int closeSocket(int fdSocket);
int connectSocket(struct sockaddr_in * address, socklen_t length, int fdServer);
int buildServer(struct sockaddr_in * address);
int connectClient(struct sockaddr_in * address, socklen_t length, int fdSocket);

#endif