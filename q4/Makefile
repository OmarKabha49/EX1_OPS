CC = gcc
CFLAGS = -Wall -fprofile-arcs -ftest-coverage -lm

all: dijkstra

dijkstra: dijkstra.c
	$(CC) $(CFLAGS) -o dijkstra dijkstra.c

clean:
	rm -f dijkstra dijkstra.gcda dijkstra.gcno dijkstra.c.gcov

coverage: dijkstra
	./dijkstra
	gcov dijkstra.c

.PHONY: all clean coverage

