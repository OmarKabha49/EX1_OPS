CC = gcc
CFLAGS =-g -Wall -lm

all: main

libpoisson.so: poisson.c poisson.h
	$(CC) -fPIC -c poisson.c
	$(CC) -shared -o libpoisson.so poisson.o $(CFLAGS)

main: main.c libpoisson.so
	$(CC) -o main main.c ./libpoisson.so $(CFLAGS)

clean:
	rm -f *.o *.so main

