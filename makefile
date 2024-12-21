CC = gcc
CFLAGS = -Wall -Wextra -std=c99


build: main.o unique_name.o
	$(CC) $(CFLAGS) -o app.exe main.o unique_name.o

main.o: main.c 
	$(CC) $(CFLAGS) -c main.c

unique_name.o: unique_name.c unique_name.h
	$(CC) $(CFLAGS) -c unique_name.c

run: build
	./app.exe

clean:
	rm -f *.o app.exe 
