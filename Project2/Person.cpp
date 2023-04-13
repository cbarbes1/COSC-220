/*
Author: Cole Barbes
Creation Date: 04/13/23
Last Update: 04/13/23
*/
#include "Person.h"

using namespace std;

/*
Constructor: Given the name, height, weight and DOB a Person is constructed
*/
Person::Person(string f, string l, FeetInches& h, double w, Date& birthday)
{
    first = f;
    last = l;
    height = h;
    weight = w;
    DOB = birthday;
}

/*
Constructor: A person is created but with no data
*/
Person::Person()
{
    first = "";
    last = "";
    weight = 0.0;
}

/*
Destructor for dynamic functionality
*/
Person::~Person()
{
}

/*
This function returns a name as a string in formal format
*/
string Person::formal()
{
    return (last + ", "+ first);
}

/*
This function returns a name as a string in informal format
*/
string Person::informal()
{
    return (first + " "+ last);
}

/*
This function simply returns the height as a Feet Inches type
*/
FeetInches Person::getHeight()
{
    return height;
}

/*
Return weight as a double
*/
double Person::getWeight()
{
    return weight;
}

/*
Return the date of birth as a date object
*/
Date Person::getDOB()
{
    return DOB;
}

/*
return a string with all needed data
*/
string Person::toString()
{
    return formal() + " / " + height.toString() + " / " + to_string(weight) + " / "+ DOB.toString();
}