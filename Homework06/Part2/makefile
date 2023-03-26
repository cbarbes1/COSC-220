# this make file was created by cole barbes on 03/25/23
PROG = homework6
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o 

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp 
	$(CC) $(CPPFLAGS) -c main.cpp

clean: 
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make