#ifndef PERSONDATA_H
#define PERSONDATA_H

#include <iostream>

using namespace std;

class PersonData{
    protected:
        string lastName, firstName, address, city, state, zip, phone;
    public:
        PersonData();
        void setName(string, string);
        void setAddress(string, string, string, string);
        void setPhone(string);
        string getName();
        string getAddress();
        string getPhone();
        virtual string getRecord();
        virtual void PrintRecord();
};
#endif