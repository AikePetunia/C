# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: tests ejemplo

# Build targets
tests: tests.c robot.c robot.h
	$(CC) $(CFLAGS) -o tests tests.c robot.c

ejemplo: ejemplo.c robot.c robot.h
	$(CC) $(CFLAGS) -o ejemplo ejemplo.c robot.c

# Run target
run: tests
	./tests

# Clean target
clean:
	rm -f tests ejemplo
