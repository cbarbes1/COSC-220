/*
 * Author: <Cole Barbes>
 * Creation Date: <02/06/23>
 * Last Update: <02/06/23>
 * Description: <>
 * User Interface: <List of all user options and short descriptions of each option>
 * Notes: <Any notes that a user of the program should know about>
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct StateDate{
    string state;
    double* numericData;
};

int main()
{

    string fileName;  // string to bring in file name from user
    cout<<"Input the filename: ";
    cin>>fileName;

    ifstream dataFile(fileName); // create and open the fstream data file

    if(dataFile.is_open()){
        while(dataFile){
            string header;
            getline(fileName, header);
            cout<<header<<endl;
        }
    }

}
