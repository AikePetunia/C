# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: tests

# Build targets
tests: tests.c weather.c weather_table.c queries.c
	$(CC) $(CFLAGS) -o tests tests.c weather.c weather_table.c queries.c

# Run target
run: tests
	./tests

# Clean target
clean:
	rm -f tests *.o
