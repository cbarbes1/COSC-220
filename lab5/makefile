#created by: cole Barbes on 03/09/23

PROG = lab5
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o PersonData.o CustomerData.o 

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

PersonData.o : PersonData.h PersonData.cpp
	$(CC) $(CPPFLAGS) -c PersonData.cpp

CustomerData.o : CustomerData.h CustomerData.cpp 
	$(CC) $(CPPFLAGS) -c CustomerData.cpp

clean: 
	rm -f core $(PROG) $(OBJS)

rebuild: 
	make clean
	make