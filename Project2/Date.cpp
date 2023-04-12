/*
Author: Cole Barbes
Creation Date: 03/10/23
Last Update: 03/16/23
*/
#include "Date.h" // include header

/*
Description: default constructor
*/
Date::Date()
{
    month = 01;
    day = 02;
    year = 1960;
}

/*
Description: Constructor
Parameters: 3 integer values for the date
*/
Date::Date(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
}

/*
Description: Set the date
Parameters: 3 integer value for the date
*/
void Date::setDate(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
}

/*
Description: set the date given a string
Parameters: a string holding the date 
*/
void Date::setMDY(string date){
    month = atoi((date.substr(0, date.find('/'))).c_str());
    date = date.substr(date.find('/')+1);
    day = atoi((date.substr(0, date.find('/'))).c_str());
    date = date.substr(date.find('/')+1);
    year = atoi((date.substr(0)).c_str());
}

/*
Description: get the month
Return: Month
*/
int Date::getMonth()
{
    return month;
}

/*
Description: get the day
Return: the day
*/
int Date::getDay()
{
    return day;
}

/*
Description: get the year
Return: the year
*/
int Date::getYear()
{
    return year;
}

/*
Description: Overloaded conditional =
Parameters: the right date
Return true or false 
*/
bool Date::operator==(const Date& right)
{
    return ((month == right.month) && (day == right.day) && (year == right.year));
}

/*
Description: Overloaded conditional !=
Parameters: the right date
Return true or false 
*/
bool Date::operator!=(const Date& right)
{
    return !((*this)==right);
}

/*
Description: Overloaded conditional <
Parameters: the right date
Return true or false 
*/
bool Date::operator<(const Date& right)
{
    return (year < right.year || month < right.month || day < right.day);
}

/*
Description: Overloaded conditional >
Parameters: the right date
Return true or false 
*/
bool Date::operator>(const Date& right)
{
    return (year > right.year || month > right.month || day > right.day);
}

/*
Description: Overloaded conditional <=
Parameters: the right date
Return true or false 
*/
bool Date::operator<=(const Date& right)
{
    return (year <= right.year || month <= right.month || day <= right.day);
}

/*
Description: Overloaded conditional >=
Parameters: the right date
Return true or false 
*/
bool Date::operator>=(const Date& right)
{
    return (year >= right.year || month >= right.month || day >= right.day);
}

/*
Description: Overloaded stream <<
Parameters: the date object being printed
return the stream to print
*/
ostream& operator<<(ostream & strm, const Date& obj)
{
    strm<<obj.month<<"/"<<obj.day<<"/"<<obj.year;
    return strm;
}


/*
Description: This function overloads the to string function to produce a nice string for this type
*/
string Date::toString(){
    return (to_string(month) + "/" + to_string(day) + "/" + to_string(year));
}