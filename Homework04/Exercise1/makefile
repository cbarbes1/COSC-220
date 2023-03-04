# created by Cole Barbes on 03/04/23

PROG = PointProg
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = Point.o main.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp 
	$(CC) $(CPPFLAGS) -c main.cpp

Point.o : Point.h Point.cpp
	$(CC) $(CPPFLAGS) -c Point.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make