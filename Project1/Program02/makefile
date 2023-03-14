# created by cole barbes on 03/12/23

PROG = stockReport
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Date.o StockDay.o StockList.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp 
	$(CC) $(CPPFLAGS) -c main.cpp

Date.o : Date.cpp 
	$(CC) $(CPPFLAGS) -c Date.cpp

StockDay.o : StockDay.cpp 
	$(CC) $(CPPFLAGS) -c StockDay.cpp

StockList.o : StockList.cpp 
	$(CC) $(CPPFLAGS) -c StockList.cpp

clean: 
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make