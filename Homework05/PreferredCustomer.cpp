#include "PersonData.h"
#include "CustomerData.h"
#include "PreferredCustomer.h"

PreferredCustomer::PreferredCustomer() : CustomerData()
{
    purchasesAmount = 0;
    discountLevel = 0;
}
void PreferredCustomer::setPurchasesAmount(double p)
{
    purchasesAmount = p;
    discountAmount(p);
}
double PreferredCustomer::getDiscount()
{
    return discountLevel;
}
double PreferredCustomer::getPurchasesAmount()
{
    return purchasesAmount;
}
void PreferredCustomer::PrintRecord()
{
    CustomerData::PrintRecord;
    cout<<"Account: "<< purchasesAmount<<endl;
    cout<<"Discount: "<<discountLevel<<"%"<<endl;
}
string PreferredCustomer::getRecord()
{
    return CustomerData::getRecord() + " / " + "Account: " + to_string(purchasesAmount) +  " / " + "Discount: " + to_string(discountLevel)+ "%"+endl;
}
double discountAmount(double p)
{
    if(p >= 500){
        return 0.05;
    }
    else if(p>=1000){
        return 0.06;
    }
    else if(p>=1500){
        return 0.07;
    }
    else if(p>=2000){
        return 0.1;
    }
    else {
        return 0;
    }
}