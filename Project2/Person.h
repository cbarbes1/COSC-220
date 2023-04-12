#ifndef PERSON_H
#define PERSON_H

#include "FeetInches.h"
#include "Date.h"

#include <iostream>
#include <string>

using namespace std;

class Person{
    protected:
        string first;
        string last;
        FeetInches height;
        double weight;
        Date DOB;
    public:
        Person(string, string, FeetInches&, double, Date&);
        Person();
        virtual ~Person();
        string formal();
        string informal();
        FeetInches getHeight();
        double getWeight();
        Date getDOB();
        virtual string toString();

};

#endif