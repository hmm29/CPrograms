#       Makefile

# Specify compiler
CC=gcc

# Specify flags and other macros
CFLAGS=-std=c99 -g3 -Wall -pedantic

# Rule to build executable from object files
polynomial: polynomial.o
	${CC} ${CFLAGS} -o polynomial polynomial.o

# Rule to generate object files
polynomial.o: polynomial.c
	${CC} ${CFLAGS} -c -o polynomial.o polynomial.c

polynomial.o: polynomial.h

# Rule to clean up directory
clean:
	rm -f *.o polynomial
