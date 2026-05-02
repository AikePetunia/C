# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: tests

# Build targets
tests: tests.c intercalated_sort.c intercalated_sort.h
	$(CC) $(CFLAGS) -o tests tests.c intercalated_sort.c

# Run target
run: tests
	./tests

# Clean target
clean:
	rm -f tests intercalated_sort.o
