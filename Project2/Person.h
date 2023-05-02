/*
Author: Cole Barbes
Creation Date: 04/13/23
Last Update: 04/13/23
Description: This is a parent class of type person which holds data for a person 
*/
#ifndef PERSON_H
#define PERSON_H

#include "FeetInches.h" // include needed classes
#include "Date.h"

#include <iostream>
#include <string>

using namespace std;

class Person{
    protected:
        string first; // first name
        string last; // last name
        FeetInches height; // height as a FeetInches data type
        double weight; // weight as a double
        Date DOB; // Date of birth as a date class variable
    public:
        Person(string, string, FeetInches&, double, Date&); // constructor 
        Person(); // default constructor

        virtual ~Person(); // virtual destructor for person class 

        string formal(); // return a string of the formal name
        string informal(); // return a string of the informal name
        FeetInches getHeight(); // return height
        double getWeight(); // return the weight
        Date getDOB(); // return the date of birth as a date class
        virtual string toString(); // virtual to string to use in derived classes

};

#endif