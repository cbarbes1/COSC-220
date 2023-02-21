#created by Cole Barbes 02/11/23

PROG = homework
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = IntArrayList.o main.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

IntArrayList.o : IntArrayList.h IntArrayList.cpp
	$(CC) $(CPPFLAGS) -c IntArrayList.cpp

clean: 
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean 
	make 