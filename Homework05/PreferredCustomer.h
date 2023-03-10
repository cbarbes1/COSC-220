#ifndef PREFERREDCUSTOMER_H
#define PREFERREDCUSTOMER_H

#include "CustomerData.h"

class PreferredCustomer : public CustomerData{
    private:
        double purchasesAmount;
        double discountLevel;
    public:
        PreferredCustomer();
        void setPurchasesAmount(double p);
        void setPreferredDiscount(double);
        double getDiscount();
        double getPurchasesAmount();
        void PrintRecord();
        string getRecord();
        double discountAmount(double);
};
#endif