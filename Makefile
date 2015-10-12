CC = gcc
FLAGS = -Wall -std=c99 -ggdb

all: main

main: main.c lagerio.o

list.o: list.c list.h
	$(CC) $(FLAGS) $^ -c

binarytree.o: binarytree.c binarytree.h
	$(CC) $(FLAGS) $^ -c

lagerio.o: lagerio.c lagerio.h
	$(CC) $(FLAGS) $^ -c

%.o: %.c %.h
	$(CC) %(FLAGS) $^ -c

run: main
	./main

clean:
	rm -f main
	rm -f *.o
	rm -rf *.dSYM
	rm -f *~
	rm -f *#
	rm -f .#*
