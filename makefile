CC = gcc
CFLAGS = -Wall -Wextra

all: queue.exe

queue.exe: main.o t_queue.o
	$(CC) $(CFLAGS) -o queue.exe main.o t_queue.o

main.o: main.c t_queue.h
	$(CC) $(CFLAGS) -c -o main.o main.c

t_queue.o: t_queue.c t_queue.h
	$(CC) $(CFLAGS) -c -o t_queue.o t_queue.c

clean:
	rm -f queue.exe main.o t_queue.o
