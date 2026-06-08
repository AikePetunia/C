# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: tests ejemplo

# Build targets
tests: tests.c equipo.c equipo.h
	$(CC) $(CFLAGS) -o tests tests.c equipo.c

ejemplo: ejemplo.c equipo.c equipo.h
	$(CC) $(CFLAGS) -o ejemplo ejemplo.c equipo.c

# Run target
run: tests
	./tests

# Clean target
clean:
	rm -f tests ejemplo
