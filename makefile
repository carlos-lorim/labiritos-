CC=gcc
CFLAGS=-c -Wall
LFLAGS=

all: labirinto

labirinto: trabalho.o
	$(CC) $(LFLAGS) -o labirinto .o

main.o: trabalho.c
	$(CC) $(CFLAGS) trabalho.c

clean:
	rm -f *.o labirinto
