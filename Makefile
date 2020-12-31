# -*- MakeFile -*-

CC = gcc
AR = ar
CFLAGS = -Wall

all: isort txtfind

txtfind: txtfind.c
	$(CC) $(CFLAGS) txtfind.c -o txtfind
isort: isort.c
	$(CC) $(CFLAGS)  isort.c -o isort

.PHONY: clean all

clean:
	rm -f *.o
