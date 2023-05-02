/*
Author: Cole Barbes
Creation Date: 04/13/23
Last Update: 04/13/23
*/
#include "NFLPlayer.h"

/*
Constructor: This constructor take all data items needed for an nfl player then calls the parent constructor
*/
NFLPlayer::NFLPlayer(string f, string l, FeetInches& h, double w, Date& d, int pN, string pC, string tC) : Person(f, l, h, w, d){
    playingNumber = pN;
    positionCode = pC;
    teamCode = tC;
}

/*
Constructor: Default
*/
NFLPlayer::NFLPlayer(): Person(){
    playingNumber = -1;
    positionCode = "";
    teamCode = "";
}

/*
return a string of the position
*/
string NFLPlayer::getPosition(){
    return positionCode;
}

/*
return a string of the playing number
*/
int NFLPlayer::getNumber(){
    return playingNumber;
}

/*
return a string of the team name
*/
string NFLPlayer::getTeam(){
    return teamCode;
}

/*
using the predefined person tostring, this to string will return a string for the added data
*/
string NFLPlayer::toString(){
    return (Person::toString() +" / "+positionCode+ " / " + to_string(playingNumber) +" / NFL");
}