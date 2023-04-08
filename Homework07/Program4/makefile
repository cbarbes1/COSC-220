#Created by Don Spickler  1/26/2022

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Rectangle.o Shape.o Triangle.o Square.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp LinkedList.h
	$(CC) $(CPPFLAGS) -c main.cpp

Square.o : Square.h Square.cpp
	$(CC) $(CPPFLAGS) -c Square.cpp

Rectangle.o : Rectangle.h Rectangle.cpp
	$(CC) $(CPPFLAGS) -c Rectangle.cpp

Shape.o : Shape.h Shape.cpp
	$(CC) $(CPPFLAGS) -c Shape.cpp
	
Triangle.o : Triangle.h Triangle.cpp
	$(CC) $(CPPFLAGS) -c Triangle.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
