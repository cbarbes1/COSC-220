# this make file was created by Cole Barbes on 05/03/23
PROG = program2
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp BinaryTree.h
	$(CC) $(CPPFLAGS) -c main.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make