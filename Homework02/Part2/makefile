# this  make file was made by Cole Barbes 02/03/23

PROG = stateProg
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = StateData.o main.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

StateData.o: StateData.h StateData.cpp
	$(CC) $(CPPFLAGS) -c StateData.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
