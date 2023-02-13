#include <fstream>
#include <string>
#include <istream>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct PersonTimeData{
    string name;
    double* times;
};

int lineCounter(ifstream &dataFile, string name);
bool status(ifstream &dataFile, string name);
double* initDoubleArray(string lineHolder, int dataCount);
double hourConv(int, int, int);

int main()
{

    ifstream dataFile;
    string fileName = "";
    string name = "";
    string line = "";
    bool fileStatus = false;
    int lineCount = 0;
    int dataCount = 0;
    

    cout<<"Input the file name: ";
    cin>>fileName;

    fileStatus = status(dataFile, fileName);

    lineCount = lineCounter(dataFile, fileName);
    
    cout<<lineCount<<endl;
    PersonTimeData* dataBase = new PersonTimeData[lineCount];

    for(int i = 0; i<lineCount; i++){
        getline(dataFile, line);

        name = line.substr(line.find('"')+1, line.find('"',2)-1);
        line = line.substr(line.find('"', line.find('"', 1))+2);


        // find the dataCount for the whole file based on the year count
        for(int i = 0; i<line.length(); i++){
            if(line.at(i) == '"') dataCount++;
        }
        dataCount = (dataCount/2);
        //
        cout<<dataCount<<endl;
        dataBase[i].name = name;
        dataBase[i].times = initDoubleArray(line, dataCount);
        dataCount = 0;
    }

    for(int i = 0; i<lineCount; i++){
        for(int j = 0; j<dataCount; j++){
            cout<<dataBase[i].name<<endl;
            cout<<dataBase[i].times[j]<<endl;
        }
    }
    

    for(int i = 0; i<lineCount; i++){
        delete[] dataBase[i].times;
        dataBase[i].times = nullptr;
    }

    delete[] dataBase;
    dataBase = nullptr;



    return 0;
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
    int quoteCount= 0;
    getline(dataFile, lineHolder);
    
    
    while(dataFile >> lineHolder){
        for(int i = 0; i<lineHolder.length(); i++){
            if(lineHolder.at(i) == '"') quoteCount++;
        }
        if(quoteCount>1)
            lineCount++;
        quoteCount = 0;
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
double hourConv(int hours, int minutes, int seconds)
{
    double min = 0.0;
    double sec = 0.0;
    double h = 0.0;
    sec = (double)seconds;
    min = (double)minutes;
    sec = sec/3600;
    min = min/60;
    h = (double)hours;
    double totalHours = 0;

    totalHours = (h+min+sec);

    return totalHours;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Description: <create a dynamic array of doubles given a string and its data content, converting each.>
// Parameters: <a string and an integer count >
// Return: <a dynamically allocated array of doubles>
///////////////////////////////////////////////////////////////////////////////////////////////////////////
double* initDoubleArray(string lineHolder, int dataCount)
{
    string word = "";
    int ch1 = 0;
    int ch2 = 0;
    int ch3 = 0;
    string line = lineHolder;
    double* tmpArr = new double[dataCount];

    for(int k = 0; k<dataCount; k++){
        word = line.substr(line.find('"')+1, line.find('"', 1)-1);
        ch1 = stoi(word.substr(0, word.find('-')));
        word = word.substr(word.find('-')+1);
        ch2 = stoi(word.substr(0, word.find('-')));
        word = word.substr(word.find('-')+1);
        ch3 = stoi(word.substr(0, word.find('-')));
        tmpArr[k] = hourConv(ch1, ch2, ch3);
    }
    for(int j = 0; j<dataCount; j++){
        cout<<tmpArr[j]<<endl;
    }
    return tmpArr;
}

