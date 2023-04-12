#include "Person.h"

using namespace std;

Person::Person(string f, string l, FeetInches& h, double w, Date& birthday)
{
    first = f;
    last = l;
    height = h;
    weight = w;
    DOB = birthday;
}
Person::Person()
{
    first = "";
    last = "";
    weight = 0.0;
}

Person::~Person()
{
}

string Person::formal()
{
    return (last + ", "+ first);
}
string Person::informal()
{
    return (first + " "+ last);
}
FeetInches Person::getHeight()
{
    return height;
}
double Person::getWeight()
{
    return weight;
}
Date Person::getDOB()
{
    return DOB;
}
string Person::toString()
{
    return formal() + " / " + height.toString() + " / " + to_string(weight) + " / "+ DOB.toString();
}