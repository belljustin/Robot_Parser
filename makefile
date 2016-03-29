CC=gcc
CFLAGS=-c -std=c99 -Wall
LFLAGS=-Wall
LIBS=-lcheck

main : main.o syntax.o parse.o
	$(CC) $(LFLAGS) bin/main.o bin/syntax.o bin/parse.o -o build/a.out

main.o : src/main.c
	$(CC) $(CFLAGS) $< -o bin/$@ -g

test : test.o
	$(CC) $(LFLAGS) bin/test.o -o build/test $(LIBS) -g
	build/test

test.o : test/test.c
	$(CC) $(CFLAGS) $< -o bin/$@

%.o : src/%.c include/%.h
	$(CC) $(CFLAGS) $< -o bin/$@

config :
	mkdir -p include bin build 

clean :
	rm -f bin/*
