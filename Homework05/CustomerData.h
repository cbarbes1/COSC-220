/*
Author: Cole Barbes
Creation Date: 03/10/23
Last Update: 03/14/23
Description: This file defines the derived class of Person Data called customer data
*/
#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include "PersonData.h" // include the base class header
#include <iostream>

using namespace std;

class CustomerData : public PersonData{
    protected:
        int customerNumber;// customer number 
        bool mailingList; // mailing list boolean 
    public:
        CustomerData(); // constructor
        virtual ~CustomerData();
        //accessors and mutators
        void setCustomerNumber(int);
        void setMailingList(bool);
        int getCustomerNumber();
        bool getMailingList();
        // dynamic binding functions
        virtual string getRecord();
        virtual void PrintRecord();
};
#endif