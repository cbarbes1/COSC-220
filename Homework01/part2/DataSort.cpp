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

// struct to hold each chunk of state data 
struct StateData{
    string state;
    double* numericData;
};

// opens a given file, after which returns whether it opened or not.
bool status(ifstream &, string);
// simple divider func
void div();
// count the number of lines in a file
int lineCounter(ifstream &, string);
// return the address of an array created from a string of doubles seperated by a space
double* initDoubleArray(string, int);
// return the address of an array created from a string of integers seperated by a space
int* initIntArray(string, int);

/////////////////////////////////////////////////////////////////////////////////////////////
//
// The main function of the program
// This main contains a program which takes a file in and 
// gives an analysis on the carbon dioxide emissions in a given state in a given year
//
//////////////////////////////////////////////////////////////////////////////////////////// 
int main()
{
    string fileName= "";  // string to bring in file name from user
    cout<<"Input the filename: ";
    cin>>fileName;

    ifstream dataFile; // create and open the fstream data file

    bool fileStatus = status(dataFile, fileName);

    if(fileStatus){//if the file opens

        int* years = nullptr;// pointer to point to a dynamic array of integers 
        StateData* states = nullptr;//pointer to point to a dynamic array of StateData structs
        string state = "";// state string holder
        int yearSelect = 0; //hold the selected years
        int stateSelect = 0;//hold selected state
        int dataCount = 0;// hold a count of the data in each line
        string line = "";//hold each line 
        int lineCount = 0;//count of lines

        getline(dataFile, line);//bring in the line from the file

        line = line.substr(line.find(',')+1);

        // find the dataCount for the whole file based on the year count
        for(int i = 0; i<line.length(); i++){
            if(line.at(i) == ',') dataCount++;
        }
        dataCount+=1;
        //

        years = initIntArray(line, dataCount);//get the address of the year array that is created in the function
        
        lineCount = lineCounter(dataFile, fileName);//get the value of the line count

        div();

        states = new StateData[lineCount];// initialize the dynamic array of structs

        // for loop to assign each of the pieces of data which includes assigning an address to the numericdata pointer
        for(int i = 0; i<lineCount; i++){
            getline(dataFile, line);
            string word = line.substr(0, line.find(','));//temporary variable to hold each string value
            line = line.substr(line.find(',')+1);
            state = word;
            states[i].state = state;
            states[i].numericData = initDoubleArray(line, dataCount);
        }

        cout<<"Select a state"<<endl;

        for(int i = 0; i<lineCount; i++){
            cout<<(i+1)<<". "<<states[i].state<<endl;
        }

        cout<<"Selection: ";
        cin>>stateSelect;
        cout<<endl;

        div();

        cout<<"Select a Year "<<endl;
        for(int i = 0; i<dataCount; i++){
            cout<<years[i]<<" "<<endl;
        }

        cout<<"Selection:";
        cin>>yearSelect;
        cout<<endl;

        yearSelect = (dataCount-((years[(dataCount-1)])-yearSelect)-1);//find the correct array index to print

        div();

        // print the information the user requested
        cout<<"The Energy-related carbon dioxide emissions for "<<states[(stateSelect-1)].state<<" in millions of "<<endl;
        cout<<"metric tons in the year "<<years[yearSelect]<<" was "<<states[(stateSelect-1)].numericData[yearSelect]<<endl;

        dataFile.close();// close the file

        //free up all used memory
        delete[] years;
        years = nullptr;
        for(int i =0; i<lineCount; i++){
            delete[] states[i].numericData;
            states[i].numericData = nullptr;
        }
        delete[] states;
        states = nullptr;

        return 0;
    }
    else{ // if the file does not open

        cout<<"oops, the file must not exist"<<endl;

    }
}

/////////////////////////////////////////////////////////////////////////////////////////////
//Description: <This function finds out if a file opens successfully.>
//Parameters: < The ifstream variable and the string which holds the name of the file>
//Return: <a boolean of whether or not the file opened>
//Notes: <This should help keep the code simple later on.>
//////////////////////////////////////////////////////////////////////////////////////////// 
bool status(ifstream &dataFile, string name){
    
    bool output;// variable to hold the output boolean

    dataFile.open(name);// open the file

    // check whether the file opened successfully or not
    if(dataFile.fail()){
        output = false;
    }
    else
        output = true;

    return output;// return value
}

/////////////////////////////////////////////////////////////////////////////////////////////
//Description: <This function finds out if a file opens successfully.>
//Parameters: < The ifstream variable and the string which holds the name of the file>
//Return: <a boolean of whether or not the file opened>
//Notes: <This should help keep the code simple later on.>
//////////////////////////////////////////////////////////////////////////////////////////// 
int lineCounter(ifstream &dataFile, string name){
    string lineHolder;
    int lineCount = 0;
    int commaCount= 0;
    getline(dataFile, lineHolder);
    
    
    while(dataFile >> lineHolder){
        for(int i = 0; i<lineHolder.length(); i++){
            if(lineHolder.at(i) == ',') commaCount++;
        }
        if(commaCount>1)
            lineCount++;
        commaCount = 0;
    }

    dataFile.close();
    dataFile.open(name);

    getline(dataFile, lineHolder);

    return (lineCount+1);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Description: <create a dynamic array of doubles given a string and its data content, converting each.>
// Parameters: <a string and an integer count >
// Return: <a dynamically allocated array of doubles>
///////////////////////////////////////////////////////////////////////////////////////////////////////////
double* initDoubleArray(string lineHolder, int dataCount)
{
    string word = "";
    string line = lineHolder;
    double* tmpArr = new double[dataCount];

    for(int k = 0; k<(dataCount-1); k++){
        word = line.substr(0, line.find(','));
        tmpArr[k] = stod(word);
        line = line.substr(line.find(',')+1);
    }
    tmpArr[(dataCount-1)] = stod(line);

    return tmpArr;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// Description: <create a dynamic array of integers given a string and its data content, converting each.>
// Parameters: <a string and an integer count >
// Return: <a dynamically allocated array of integers>
//////////////////////////////////////////////////////////////////////////////////////////// 
int* initIntArray(string lineHolder, int dataCount)
{
    string line = lineHolder;
    int* tmpArr = new int[dataCount];
    for(int k = 0; k<(dataCount-1); k++){
        string word = line.substr(0, line.find(','));
        tmpArr[k] = stoi(word);
        line = line.substr(line.find(',')+1);
    }
    tmpArr[(dataCount-1)] = stoi(line);

    return tmpArr;
}

/////////////////////////////////////////////////////////////////////////////////////////////
//Description: <This function finds out if a file opens successfully.>
//Parameters: < The ifstream variable and the string which holds the name of the file>
//Return: <a boolean of whether or not the file opened>
//Notes: <This should help keep the code simple later on.>
//////////////////////////////////////////////////////////////////////////////////////////// 
void div()
{
    cout<<endl;
    cout<<"---------------------------------------------------------------------------"<<endl;
    cout<<endl;
}