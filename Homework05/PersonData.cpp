#include "PersonData.h"

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
void PersonData::setName(string first, string last)
{
    firstName = first;
    lastName = last;
}
void PersonData::setAddress(string a, string c, string s, string z)
{
    address = a;
    city = c;
    state = s;
    zip = z;
}
void PersonData::setPhone(string p)
{
    phone = p;
}
string PersonData::getName()
{
    return firstName+lastName;
}
string PersonData::getAddress()
{
    return address;
}
string PersonData::getPhone()
{
    return phone;
}
string PersonData::getRecord()
{
    return firstName + " " +lastName + " / " + address + " / " + city + ", " + state + " " + zip + " / " + phone;
}
void PersonData::PrintRecord()
{
    cout<<lastName<<", "<<firstName<<endl;
    cout<<address<<endl;
    cout<<city<<", "<<state<<" "<<zip<<endl;
    cout<<phone<<endl;
}