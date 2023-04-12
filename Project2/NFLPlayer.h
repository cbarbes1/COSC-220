#ifndef NFLPLAYER_H
#define NFLPLAYER_H

#include "Person.h"

using namespace std;

class NFLPlayer : public Person{
    private:
        int playingNumber;
        string positionCode;
        string teamCode;
    public:
        NFLPlayer(string, string, FeetInches&, double, Date&, int, string, string);
        NFLPlayer();
        string getPosition();
        int getNumber();
        string getTeam();
        virtual string toString();
};
#endif