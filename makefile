GCC = gcc
GCC_FLAGS = -Wall -std=gnu99 -pedantic -fsanitize=address -lm

SRC_SERVER= src/server.c
SRC_CLIENT= src/client.c
SRC_LEVELS= src/levels.c
SRC_SOCKET_LIB= src/socketLib.c
SRC_UTILITIES= src/utilities.c

EXEC_SERVER= server
EXEC_CLIENT= client

all: server client

server: $(SRC_SERVER) $(SRC_LEVELS) $(SRC_SOCKET_LIB) $(SRC_UTILITIES)
	$(GCC) -o $(EXEC_SERVER) -I./include $(SRC_SERVER) $(SRC_LEVELS) $(SRC_SOCKET_LIB) $(SRC_UTILITIES) $(GCC_FLAGS)

client: $(SRC_CLIENT) $(SRC_SOCKET_LIB) $(SRC_UTILITIES)
	$(GCC) -o $(EXEC_CLIENT) -I./include $(SRC_CLIENT) $(SRC_SOCKET_LIB) $(SRC_UTILITIES) $(GCC_FLAGS)

clean:
	rm -f EXEC_SERVER
	rm -f EXEC_CLIENT

.PHONY:  all clean server client;