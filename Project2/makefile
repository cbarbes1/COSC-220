#this make file was created on 04/08/23
PROG = project2
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Date.o FeetInches.o Person.o NFLPlayer.o NBAPlayer.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Date.o : Date.h Date.cpp
	$(CC) $(CPPFLAGS) -c Date.cpp

FeetInches.o : FeetInches.h FeetInches.cpp
	$(CC) $(CPPFLAGS) -c FeetInches.cpp

Person.o : Person.h Person.cpp
	$(CC) $(CPPFLAGS) -c Person.cpp

NFLPlayer.o : NFLPlayer.h NFLPlayer.cpp
	$(CC) $(CPPFLAGS) -c NFLPlayer.cpp

NBAPlayer.o : NBAPlayer.h NBAPlayer.cpp
	$(CC) $(CPPFLAGS) -c NBAPlayer.cpp

clean:
	rm -f core $(PROG) $(OBJS)
	rm PlayerList.txt

rebuild:
	make clean
	make