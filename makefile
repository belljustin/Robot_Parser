CC=gcc
CFLAGS=-c -std=c99 -Wall
LFLAGS=-Wall
LIBS=-lcheck

test : test.o
	$(CC) $(LFLAGS) bin/test.o -o build/test $(LIBS) -g
	build/test

test.o : test/test.c
	$(CC) $(CFLAGS) $< -o bin/$@

%.o : src/%.c include/%.h
	$(CC) $(CFLAGS) $< -o bin/$@

clean :
	rm -f bin/*
