#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include "PersonData.h"
#include <iostream>

using namespace std;

class CustomerData : public PersonData{
    protected:
        int customerNumber;
        bool mailingList;
    public:
        CustomerData();
        void setCustomerNumber(int);
        void setMailingList(bool);
        int getCustomerNumber();
        bool getMailingList();
        string getRecord();
        void PrintRecord();
};
#endif