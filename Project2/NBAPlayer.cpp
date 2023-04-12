#include "NBAPlayer.h"

NBAPlayer::NBAPlayer(string f, string l, FeetInches& h, double w, Date& d, int pN, string pC) : Person(f, l, h, w, d){
    playingNumber = pN;
    positionCode = pC;
}

NBAPlayer::NBAPlayer(): Person(){
    playingNumber = -1;
    positionCode = "";
}

string NBAPlayer::getPosition(){
    return positionCode;
}

int NBAPlayer::getNumber(){
    return playingNumber;
}

string NBAPlayer::toString(){
    return (Person::toString() +" / "+positionCode+ " / " + to_string(playingNumber) +" / NBA");
}