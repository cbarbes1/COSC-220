/*
Author: Cole Barbes
Creation Date: 03/10/23
Last Update: 03/14/23
*/
#include "PersonData.h" // include the header

/*
Description: default Constructor for the Person Data class
*/
PersonData::PersonData()
{
    firstName = "";
    lastName = "";
    address = "";
    state = "";
    city = "";
    zip = "";
    phone = "";
}

PersonData::~PersonData(){
}
/*
Description: set the name
Parameters: 2 string values to take in the first and last
no return
*/
void PersonData::setName(string first, string last)
{
    firstName = first;
    lastName = last;
}

/*
Description: set the address
Parameters: 4 string variables to set each part of the address
no return
*/
void PersonData::setAddress(string a, string c, string s, string z)
{
    address = a;
    city = c;
    state = s;
    zip = z;
}

/*
Description: Set the phone number
*/
void PersonData::setPhone(string p)
{
    phone = p;
}

/*
Description: get the name
*/
string PersonData::getName()
{
    return firstName+lastName;
}

/*
Description: get the address
*/
string PersonData::getAddress()
{
    return address;
}

/*
Description: get the phone number
*/
string PersonData::getPhone()
{
    return phone;
}

/*
Description: create the base functions which returns the short form data base
return: the created string  
*/
string PersonData::getRecord()
{
    return firstName + " " +lastName + " / " + address + " / " + city + ", " + state + " " + zip + " / " + phone;
}

/*
Description: create the base function which returns the long form data base
*/
void PersonData::PrintRecord()
{
    cout<<endl;
    cout<<lastName<<", "<<firstName<<endl;
    cout<<address<<endl;
    cout<<city<<", "<<state<<" "<<zip<<endl;
    cout<<phone<<endl;
}