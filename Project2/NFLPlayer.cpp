#include "NFLPlayer.h"

NFLPlayer::NFLPlayer(string f, string l, FeetInches& h, double w, Date& d, int pN, string pC, string tC) : Person(f, l, h, w, d){
    playingNumber = pN;
    positionCode = pC;
    teamCode = tC;
}

NFLPlayer::NFLPlayer(): Person(){
    playingNumber = -1;
    positionCode = "";
    teamCode = "";
}

string NFLPlayer::getPosition(){
    return positionCode;
}

int NFLPlayer::getNumber(){
    return playingNumber;
}

string NFLPlayer::getTeam(){
    return teamCode;
}

string NFLPlayer::toString(){
    return (Person::toString() +" / "+positionCode+ " / " + to_string(playingNumber) +" / NFL");
}