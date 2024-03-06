CC = gcc
CFLAGS = -Wall -Wextra

all: biboServer biboClient

biboServer: biboServer.c
	$(CC) $(CFLAGS) biboServer.c -o biboServer

biboClient: biboClient.c
	$(CC) $(CFLAGS) biboClient.c -o biboClient

clean:
	rm -f biboServer biboClient

.PHONY: all clean
