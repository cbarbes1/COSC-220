/*
 * Author: <Cole Barbes>
 * Creation Date: <02/06/23>
 * Last Update: <02/06/23>
 * Description: <>
 * User Interface: <List of all user options and short descriptions of each option>
 * Notes: <Any notes that a user of the program should know about>
 */
#include <fstream>
#include <string>
#include <istream>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct StateDate{
    string state;
    int* years;
    double* numericData;
};

int main()
{
    string fileName;  // string to bring in file name from user
    cout<<"Input the filename: ";
    cin>>fileName;

    ifstream dataFile(fileName); // create and open the fstream data file

    if(dataFile.is_open()){
        string header;
        int lineCount = 0;
        getline(dataFile, header);

        cout<<header<<endl;

        header = header.substr(header.find(",")+1);

        int count = 0;
        for(int i = 0; i<header.size(); i++){
            if(header.at(i) == ',') count++;
        }

        cout<<count<<endl;

        int* yearArr = new int[count+1];

        for(int i = 0; i<=count; i++){
            string word = header.substr(0, header.find(","));
            yearArr[i] = stoi(word);
            cout<<word<<endl;
            header = header.substr(header.find(",")+1);
        }
        while(dataFile){
            
            lineCount++;
        }
        cout<<lineCount<<endl;
        dataFile.clear();
        delete[] yearArr;
        yearArr = nullptr;
    }
    else{

        cout<<"oops, the file must not exist"<<endl;

    }
}


