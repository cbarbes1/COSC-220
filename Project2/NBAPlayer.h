#ifndef NBAPLAYER_H
#define NBAPLAYER_H

#include "Person.h"

using namespace std;

class NBAPlayer: public Person{
    private:
        int playingNumber;
        string positionCode;
    public:
        NBAPlayer(string, string, FeetInches&, double, Date&, int, string);
        NBAPlayer();
        
        string getPosition();
        int getNumber();
        virtual string toString();
};

#endif