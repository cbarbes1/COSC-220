#this make file was create on 04/14/23

PROG = program1
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = StackQueueTest.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

StackQueueTest.o : StackQueueTest.cpp
	$(CC) $(CPPFLAGS) -c StackQueueTest.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make