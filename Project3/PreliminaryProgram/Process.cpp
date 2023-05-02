#include "Process.h"

/*
Description: construct the object
Parameters: 2 integers
*/
Process::Process(int time, int stamp)
{
    exeTime = time;
    timeStamp = stamp;
}

/*
Description: copy constructor
*/
Process::Process(const Process &obj)
{
    exeTime = obj.exeTime;
    timeStamp = obj.timeStamp;
}

/*
destructor
*/
Process::~Process()
{

}

/*
Description: set the execution time 
Parameters: an integer of the time
*/
void Process::setExeTime(int time)
{
    exeTime = time;
}

/*
Description: get the execution time and return it
Return: the execution time
*/
int Process::getExeTime()
{
    return exeTime;
}

/*
Description: set the time stamp 
Parameters: an integer of the stamp
*/
void Process::setTimeStamp(int stamp)
{
    timeStamp = stamp;
}

/*
Description: get the time stamp 
return: the time stamp
*/
int Process::getTimeStamp()
{
    return timeStamp;
}

/*
Description: overloaded equals sign to set the parameters
*/
const Process Process::operator=(const Process &right)
{
    exeTime = right.exeTime;
    timeStamp = right.timeStamp;
    return *this;
}

/*
Description: overload the << to place the parameters into the stream
return: the stream
*/
ostream &operator << (ostream &strm, const Process &obj)
{
    strm<<"[ "<<obj.exeTime<<", "<<obj.timeStamp<<" ]";
    return strm;
}