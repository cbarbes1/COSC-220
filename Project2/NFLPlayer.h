/*
Author: Cole Barbes
Creation Date: 04/13/23
Last Update: 04/13/23
Description: This class is a derived class of Person, Person --> NFLPlayer
*/
#ifndef NFLPLAYER_H
#define NFLPLAYER_H

#include "Person.h" // include needed parent class

using namespace std;

class NFLPlayer : public Person{ // derived class Nfl player of type Person
    private:
        int playingNumber; // data member for the players number
        string positionCode; // data member for the position code
        string teamCode; // data member holding the team name
    public:
        NFLPlayer(string, string, FeetInches&, double, Date&, int, string, string);// constructor
        NFLPlayer();// default constructor
        string getPosition(); // return the position as a string
        int getNumber(); // return the number as an integer
        string getTeam(); // return the team name as a string
        virtual string toString(); // virtual to string to implement the parent to string
};
#endif