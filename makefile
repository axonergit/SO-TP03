GCC = gcc
GCC_FLAGS = -Wall -std=c99 -pedantic -fsanitize=address -lm

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

test:
	make all
	cppcheck --quiet --enable=all --force --inconclusive --check-config -I./include/ $(SRC_SERVER) $(SRC_LEVELS) $(SRC_SOCKET_LIB) $(SRC_UTILITIES) $(SRC_CLIENT) .  2> cpptest.txt
	valgrind --leak-check=full -v --show-leak-kinds=all ./server ./client 2> app.valgrind
	make clean
	pvs-studio-analyzer trace -- make
	pvs-studio-analyzer analyze
	plog-converter -a '64:1,2,3;GA:1,2,3;OP:1,2,3' -t tasklist -o report.tasks PVS-Studio.log
	rm -f PVS-Studio.log
	make clean

clean:
	rm -f $(EXEC_SERVER)
	rm -f $(EXEC_CLIENT)

clean_test:
	rm -f app.valgrind
	rm -f cpptest.txt
	rm -f report.tasks
	rm -f strace_out
	rm -f PVS-Studio.log

.PHONY:  all clean server client;