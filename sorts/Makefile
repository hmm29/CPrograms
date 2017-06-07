
#       Makefile

# Specify compiler
CC=gcc

# Specify compile flags
CFLAGS=-std=c99 -g3 -Wall -pedantic

all:	is ps ss

# Rule to build insertion sort executable from object file
is: insertion_sort.o
	${CC} ${CFLAGS} -o $@ $<

# Rule to build pancake sort executable from object file
ps: pancake_sort.o
	${CC} ${CFLAGS} -o $@ $<

# Rule to build selection sort executable from object file
ss: selection_sort.o
	${CC} ${CFLAGS} -o $@ $<

# Rule to generate object files
%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

# Rule to clean up directory
clean:
	rm -f *.o is ps ss
