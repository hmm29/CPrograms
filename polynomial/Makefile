#       Makefile

# Specify compiler
CC=gcc

# Specify flags and other macros
CFLAGS=-std=c99 -g3 -Wall -pedantic

all:	polynomial

# Rule to build executable from object files
polynomial: main.o polynomial.o hashmap.o
	${CC} ${CFLAGS} -o polynomial main.o polynomial.o hashmap.o

# Rule to generate object files
%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

# Rule to clean up directory
clean:
	rm -f *.o polynomial
