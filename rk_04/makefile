CC = gcc
CFLAGS = -Wall -Wextra -std=c99


build: main.o list.o
	$(CC) $(CFLAGS) -o app.exe main.o list.o

main.o: main.c 
	$(CC) $(CFLAGS) -c main.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

run: build
	./app.exe

clean:
	rm -f *.o app.exe 
