#created by Cole Barbes 02/11/23

PROG = homework
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = Prog_Exercise01.o arrayFunc.o

$(PROG) : $(OBJS)
		$(CC) -o $(PROG) $(OBJS)

Prog_Exercise01.o : Prog_Exercise01.cpp
		$(CC) $(CPPFLAGS) -c Prog_Exercise01.cpp

arrayFunc.o : arrayFunc.h arrayFunc.cpp
		$(CC) $(CPPFLAGS) -c arrayFunc.cpp

clean: 
		rm -f core $(PROG) $(OBJS)

rebuild:
		make clean 
		make 