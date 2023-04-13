/*
Author: Cole Barbes
Creation Date: 04/13/23
Last Update: 04/13/23
Description: This is a derived class of person, Person --> NBAPlayer
*/
#ifndef NBAPLAYER_H
#define NBAPLAYER_H

#include "Person.h" // include parent class

using namespace std;

class NBAPlayer: public Person{ // define derived class of Person class
    private:
        int playingNumber; // data member for playing number
        string positionCode; // data member for position
    public:
        // constructor 
        NBAPlayer(string, string, FeetInches&, double, Date&, int, string);
        // default constructor
        NBAPlayer();
        
        string getPosition(); // return a string of the players position
        int getNumber(); // return the player number
        virtual string toString(); // virtual to string to use the parent to string 
};

#endif