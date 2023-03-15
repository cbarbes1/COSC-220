/*
Author: Cole Barbes
Creation Date: 03/10/23
Last Update: 03/14/23
*/
#include "CustomerData.h"
#include "PersonData.h"
#include <string>

/*
Description: the default constructor for the class
*/
CustomerData::CustomerData() : PersonData(){
    customerNumber = 0000;
    mailingList = false;
}
CustomerData::~CustomerData()
{
}
/*
Description: set the customer number
*/
void CustomerData::setCustomerNumber(int cNum)
{
    customerNumber = cNum;
}
/*
Description: set the mailing list
*/
void CustomerData::setMailingList(bool list)
{
    mailingList = list;
}

/*
Description: get the customer number
Return: the customer number
*/
int CustomerData::getCustomerNumber()
{
    return customerNumber;
}

/*
Description: get the mailing list
Return: a boolean true or false 
*/
bool CustomerData::getMailingList()
{
    return mailingList;
}

/*
Description: print the short form directory using the base class function
*/
string CustomerData::getRecord()
{
    string mail = " ";
    if(mailingList){ mail = "Yes";}
    else { mail = "No";}
    string c= "" + to_string(customerNumber);
   
    return PersonData::getRecord()+" C#: "+c+" / "+ "ML: "+mail;
}

/*
Description: print the long form directory using the base class function
*/
void CustomerData::PrintRecord()
{
    PersonData::PrintRecord(); // call func from base class
    cout<<"Customer Number: "<<customerNumber<<endl;

    //check the mailing list var to see if yes or no is printed
    if(mailingList){  cout<<"Yes"<<endl;}
    else { cout<<"No"<<endl;}
}