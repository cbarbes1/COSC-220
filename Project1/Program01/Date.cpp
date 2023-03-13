#include "Date.h"

Date::Date()
{
    month = 01;
    day = 02;
    year = 1960;
}
Date::Date(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
}
void Date::setDate(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
}
int Date::getMonth()
{
    return month;
}
int Date::getDay()
{
    return day;
}
int Date::getYear()
{
    return year;
}
bool Date::operator==(const Date& right)
{
    return ((month == right.month) && (day == right.day) && (year == right.year));
}
bool Date::operator!=(const Date& right)
{
    return !((*this)==right);
}
bool Date::operator<(const Date& right)
{
    return (year <= right.year && (month < right.month || day < right.day));
}
bool Date::operator>(const Date& right)
{
    return (year >= right.year && (month > right.month || day > right.day));
}
bool Date::operator<=(const Date& right)
{
    return (year <= right.year || month <= right.month && day <= right.day);
}
bool Date::operator>=(const Date& right)
{
    return (year >= right.year || month >= right.month && day >= right.day);
}
ostream& operator<<(ostream & strm, const Date& obj)
{
    strm<<obj.month<<"/"<<obj.day<<"/"<<obj.year;
    return strm;
}