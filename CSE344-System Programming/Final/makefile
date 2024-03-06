CC = gcc
CFLAGS = -Wall -Wextra

all: BibakBOXServer BibakBOXClient

BibakBOXServer: BibakBOXServer.c
	$(CC) $(CFLAGS) BibakBOXServer.c -o BibakBOXServer

BibakBOXClient: BibakBOXClient.c
	$(CC) $(CFLAGS) BibakBOXClient.c -o BibakBOXClient

clean:
	rm -f BibakBOXServer BibakBOXClient

.PHONY: all clean
