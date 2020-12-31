# -*- MakeFile -*-

CC = gcc
AR = ar
CFLAGS = -Wall

all: isort txtfind

txtfind: txtfind.c
	$(CC) $(CFLAGS) txtfind.c -o txtfind.o
isort: isort.c
	$(CC) $(CFLAGS)  isort.c -o isort.o

.PHONY: clean all

clean:
	rm -f *.o
