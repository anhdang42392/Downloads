CC=gcc
CFLAGS=-I.
DEPS = server.c client.c

all: server client

server: server.c
	$(CC) -o server server.c

client: client.c
	$(CC) -o client client.c

clean:
	rm -f server client
