# created by Cole Barbes on 02/27/23

PROG = homework
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = Array2D.o main.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Array2D.o : Array2D.h Array2D.cpp
	$(CC) $(CPPFLAGS) -c Array2D.cpp

clean: 
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean 
	make 