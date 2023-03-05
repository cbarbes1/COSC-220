#created by Cole Barbes 03/05/23

PROG = MatrixProg
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Matrix.o 

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp 
	$(CC) $(CPPFLAGS) -c main.cpp

Matrix.o : Matrix.h Matrix.cpp 
	$(CC) $(CPPFLAGS) -c Matrix.cpp

clean: 
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make