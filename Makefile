CC=gcc
CFLAGS=-I.

pfans: main.o
	$(CC) -o pfans main.o

main.o: src/main.c src/config.h
	$(CC) -c src/main.c -o main.o

clean:
	rm *.o pfans
