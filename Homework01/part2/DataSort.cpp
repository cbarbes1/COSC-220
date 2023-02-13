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

struct StateData{
    string state;
    double* numericData;
};

bool status(ifstream &, string);
void div();
int lineCounter(ifstream &, string);

int main()
{
    string fileName= "";  // string to bring in file name from user
    cout<<"Input the filename: ";
    cin>>fileName;

    ifstream dataFile; // create and open the fstream data file

    bool fileStatus = status(dataFile, fileName);

    if(fileStatus){

        int* years = nullptr;// pointer to point to a dynamic array of integers 
        StateData* states = nullptr;//pointer to point to a dynamic array of StateData structs
        double* tmpArr = nullptr;// pointer to point to a dynamic array of doubles temporarily 
        string state = "";// state string holder
        int yearSelect = 0; //hold the selected years
        int stateSelect = 0;//hold selected state
        int dataCount = 0;// hold a count of the data in each line
        string line = "";//hold each line 
        int count = 0;//count of lines

        getline(dataFile, line);
        line = line.substr(line.find(',')+1);
        for(int i = 0; i<line.length(); i++){
            if(line.at(i) == ',') dataCount++;
        }
        dataCount+=1;
        years = new int[dataCount];
        for(int i = 0; i<dataCount; i++){
            string word = line.substr(0, line.find(','));
            line = line.substr(line.find(',')+1);
            years[i] = stoi(word);
        }
        
        count = lineCounter(dataFile, fileName);

        div();

        states = new StateData[count];

        for(int i = 0; i<count; i++){
            getline(dataFile, line);
            tmpArr = new double[dataCount];
            
            string word = line.substr(0, line.find(','));//temporary variable to hold each string value
            line = line.substr(line.find(',')+1);
            state = word;
            for(int k = 0; k<(dataCount-1); k++){
                word = line.substr(0, line.find(','));
                tmpArr[k] = stod(word);
                line = line.substr(line.find(',')+1);
            }
            tmpArr[(dataCount-1)] = stod(line);
            states[i].numericData = tmpArr;
            states[i].state = state;
            tmpArr = nullptr;
        }
        cout<<"Select a state"<<endl;
        for(int i = 0; i<count; i++){
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
        yearSelect = (dataCount-((years[(dataCount-1)])-yearSelect)-1);

        div();

        cout<<"The Energy-related carbon dioxide emissions for "<<states[(stateSelect-1)].state<<" in millions of "<<endl;
        cout<<"metric tons in the year "<<years[yearSelect]<<" was "<<states[(stateSelect-1)].numericData[(yearSelect-1)]<<endl;

        dataFile.close();
        delete[] tmpArr;
        tmpArr = nullptr;
        delete[] years;
        years = nullptr;
        for(int i =0; i<count; i++){
            delete[] states[i].numericData;
            states[i].numericData = nullptr;
        }
        delete[] states;
        states = nullptr;
    }
    else{

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

void div()
{
    cout<<endl;
    cout<<"---------------------------------------------------------------------------"<<endl;
    cout<<endl;
}