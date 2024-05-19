CC = gcc
CFLAGS = -Wall -g -pg
TARGETS = DivisionByZero StackOverflow UndefinedMemory

all: $(TARGETS)

DivisionByZero: DivisionByZero.c
	$(CC) $(CFLAGS) -o DivisionByZero DivisionByZero.c

StackOverflow: StackOverflow.c
	$(CC) $(CFLAGS) -o StackOverflow StackOverflow.c

UndefinedMemory: UndefinedMemory.c
	$(CC) $(CFLAGS) -o UndefinedMemory UndefinedMemory.c

clean:
	rm -f $(TARGETS) *.o *.gcda *.gcno *.gcov gmon.out

