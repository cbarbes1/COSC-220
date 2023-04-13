/*
Author: Cole Barbes
Creation Date: 04/13/23
Last Update: 04/13/23
*/
#include "NBAPlayer.h"

/*
Constructor: This constructor take all data items needed for an nba player then calls the parent constructor
*/
NBAPlayer::NBAPlayer(string f, string l, FeetInches& h, double w, Date& d, int pN, string pC) : Person(f, l, h, w, d){
    playingNumber = pN;
    positionCode = pC;
}

/*
Constructor: default
*/
NBAPlayer::NBAPlayer(): Person(){
    playingNumber = -1;
    positionCode = "";
}

/*
return a string of the position
*/
string NBAPlayer::getPosition(){
    return positionCode;
}

/*
return a string of the playing number
*/
int NBAPlayer::getNumber(){
    return playingNumber;
}


/*
using the predefined person tostring, this to string will return a string for the added data
*/
string NBAPlayer::toString(){
    return (Person::toString() +" / "+positionCode+ " / " + to_string(playingNumber) +" / NBA");
}