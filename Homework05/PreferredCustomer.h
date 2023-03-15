/*
Author: Cole Barbes
Creation Date: 03/10/23
Last Update: 03/14/23
Description: This file defines the derived class of customer data called Preferred Customer
*/
#ifndef PREFERREDCUSTOMER_H
#define PREFERREDCUSTOMER_H

#include "CustomerData.h" // include the header

class PreferredCustomer : public CustomerData{
    private:
        double purchasesAmount; // hold the total purchase amount for the customer
        double discountLevel; // hold the discount level
    public:

        PreferredCustomer();
        virtual ~PreferredCustomer();
        //accessors and mutators
        void setPurchasesAmount(double p);
        void setPreferredDiscount(double);
        double getDiscount();
        double getPurchasesAmount();

        // create the dynamic binding functions
        virtual void PrintRecord();
        virtual string getRecord();
        // create the discount finder function
        double discountAmount(double);
};
#endif