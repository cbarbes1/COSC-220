/*
Author: Cole Barbes
Creation Date: 03/10/23
Last Update: 03/14/23
*/
#include "PersonData.h" // include the header for the base class
#include "CustomerData.h" // include header for the parent class 
#include "PreferredCustomer.h" // include the header of the header

/*
Description: The default constructor for the class
*/
PreferredCustomer::PreferredCustomer() : CustomerData()
{
    purchasesAmount = 0;
    discountLevel = 0;
}

PreferredCustomer::~PreferredCustomer(){
}
/*
Description: set the total purchase amount and check the disount amount
*/
void PreferredCustomer::setPurchasesAmount(double p)
{
    purchasesAmount = p;
    discountLevel = discountAmount(p);
}

/*
Description: get the discount amount
return: the discount amount
*/
double PreferredCustomer::getDiscount()
{
    return discountLevel;
}

/*
Description: get the purchase amount
Return: the total purchases amount
*/
double PreferredCustomer::getPurchasesAmount()
{
    return purchasesAmount;
}

/*
Description: print the long form directory
*/
void PreferredCustomer::PrintRecord()
{
    CustomerData::PrintRecord();
    cout<<"Account: "<<purchasesAmount<<endl;
    cout<<"Discount: "<<discountLevel<<"%"<<endl;
}

/*
Description: print the short form directory, this functions uses the parent classes version of this function
*/
string PreferredCustomer::getRecord()
{
    return CustomerData::getRecord() + " / " + "Account: " + to_string(purchasesAmount) +  " / " + "Discount: " + to_string(discountLevel) + "%";
}

/*
Description: take the purchase total and check which group for the discount the customer is in
Parameters: the purchase amount 
return: the discount amount
*/
double PreferredCustomer::discountAmount(double p)
{
    if(p >= 500 && p<1000){// if the lower level
        return 0.05;
    }
    else if(p>=1000&& p<1500){ // if the second level 
        return 0.06;
    }
    else if(p>=1500&&p<2000){// if the third level
        return 0.07;
    }
    else if(p>=2000){ // if the fourth level
        return 0.1;
    }
    else { // all else is 0
        return 0;
    }
}