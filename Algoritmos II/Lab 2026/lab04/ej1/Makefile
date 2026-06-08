# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: tests ejemplo

# Build targets
tests: tests.c moto.c moto.h
	$(CC) $(CFLAGS) -o tests tests.c moto.c

ejemplo: ejemplo.c moto.c moto.h
	$(CC) $(CFLAGS) -o ejemplo ejemplo.c moto.c

# Run target
run: tests
	./tests

# Clean target
clean:
	rm -f tests ejemplo
