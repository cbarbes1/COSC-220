#include "CustomerData.h"
#include "PersonData.h"
#include <string>

CustomerData::CustomerData() : PersonData(){
    customerNumber = 0000;
    mailingList = false;
}
void CustomerData::setCustomerNumber(int cNum)
{
    customerNumber = cNum;
}
void CustomerData::setMailingList(bool list)
{
    mailingList = list;
}
int CustomerData::getCustomerNumber()
{
    return customerNumber;
}
bool CustomerData::getMailingList()
{
    return mailingList;
}
string CustomerData::getRecord()
{
    string mail;
    if(mailingList){ mail = "Yes";}
    else { mail = "No";}
    string c= "" + to_string(customerNumber);
   
    return PersonData::getRecord()+" C#: "+c+" / "+ "ML: "+mail;
}
void CustomerData::PrintRecord()
{
    PersonData::PrintRecord();
    cout<<"Customer Number: "<<customerNumber<<endl;
    if(mailingList){  cout<<"Yes"<<endl;}
    else { cout<<"No"<<endl;}
}