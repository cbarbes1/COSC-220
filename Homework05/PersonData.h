/*
Author: Cole Barbes
Creation Date: 03/10/23
Last Update: 03/14/23
Description: This file defines the Base class Person Data
*/
#ifndef PERSONDATA_H
#define PERSONDATA_H

#include <iostream> 

using namespace std;

class PersonData{
    protected:
        string lastName, firstName, address, city, state, zip, phone; // create the strings to hold the data
    public:
        //constructor
        PersonData();
        virtual ~PersonData();
        //accessors and mutators
        void setName(string, string);
        void setAddress(string, string, string, string);
        void setPhone(string);
        string getName();
        string getAddress();
        string getPhone();

        //dynamic binding functions
        virtual string getRecord();
        virtual void PrintRecord();
};
#endif