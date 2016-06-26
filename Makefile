#!/usr/bin/make -f

CC=gcc
CFLAGS=-Wall -ansi -pedantic -g
LDFLAGS=
EXEC=sokoban
BIN=bin/sokoban.o bin/main.o
SRC=sokoban.c main.c
HEAD=sokoban.h

BINS=$(sort $(BIN))

all: $(EXEC)

sokoban: $(BIN)
	$(CC) -o bin/$@ $(BIN) $(LDFLAGS)

$(BINS): bin/%.o: src/%.c
	$(CC) -c $< $(CFLAGS) -o $@


clean:
	rm -f *.o *~ 2> /dev/null

clear: clean
	rm -f $(EXEC) $(USER)_sokoban.tgz 2> /dev/null

zip: clear
	mkdir -p $(USER)_sokoban
	cp Makefile *.c *.h *.sok $(USER)_sokoban
	tar czf $(USER)_sokoban.tgz $(USER)_sokoban
	rm -rf $(USER)_sokoban
