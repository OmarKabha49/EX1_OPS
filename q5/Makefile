CC = gcc
CFLAGS = -pg

all: max_subarray

max_subarray: max_subarray.c
	$(CC) $(CFLAGS) -o max_subarray max_subarray.c

clean:
	rm -f max_subarray gmon.out analysis*.txt
