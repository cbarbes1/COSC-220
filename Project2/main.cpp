/*
Author: Cole Barbes
Creation Date: 04/13/23
Last Update: 04/13/23
Description: This main program implements polymorphism, dynamic binding, and object-oriented programming
to collect data about NBA and NFL players which is given in csv files
User Interface: Since this program would be implemented to clean data the user interface is simply running the program
*/
// include needed files
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "Person.h"
#include "NBAPlayer.h"
#include "NFLPlayer.h"

using namespace std;

// function prototype to load all data from the NBA file to the vector
void LoadNBADataFile(string, vector<Person*>&);

// function prototype to load all data from the NFL file to the vector
void LoadNFLDataFile(string, vector<Person*>&);

// function prototype to print the data in the vector
void printData(vector<Person*>&, string, string);

// function prototype to sort the vector by name ascending order
void sortByName(vector<Person*>&);

// function prototype to sort the vector by height in ascending order
void sortByHeight(vector<Person*>&);

// function prototype to sort the vector by weight in ascending order
void sortByWeight(vector<Person*>&);

// function prototype to populate the tall player vector 
void populateTall(vector<Person*>&, vector<Person*>&);

// function protoypt to populate the big player list
void populateBigPlayers(vector<Person*>&, vector<Person*>&);

// function prototype to populate the tallest player list
void populateTallestPlayers(vector<Person*>&, vector<Person*>&);

//function prototype to populate the oldest player list
void populateOldestPlayers(vector<Person*>&, vector<Person*>&);

// functino prototype to populate the youngest player list
void populateYoungestPlayers(vector<Person*>&, vector<Person*>&);

int main()
{
    //create the vectors
    vector<Person*> PlayerInfo;
    vector<Person*> TallPlayers;
    vector<Person*> BigPlayers;
    vector<Person*> YoungestPlayers;
    vector<Person*> TallestPlayers;
    vector<Person*> OldestPlayers;

    string fileName = "PlayerList.txt"; //define the output file name

    // load Data into the vector
    LoadNBADataFile("NBA.csv", PlayerInfo);
    LoadNFLDataFile("NFL.csv", PlayerInfo);

    
    printData(PlayerInfo, fileName, "Player List"); // print the list 

    sortByName(PlayerInfo); // sort the vector by name

    populateTall(PlayerInfo, TallPlayers); // call the funtion to populate the tall player list

    sortByHeight(TallPlayers); // sort the tall player list by height

    populateBigPlayers(PlayerInfo, BigPlayers); // call the function to populate the big player list

    sortByWeight(BigPlayers); // sort the big players by weight

    printData(PlayerInfo, fileName, "Player List Sorted"); // print the player info list sorted

    printData(TallPlayers, fileName, "Tall Player List"); // pritn the tall player list

    // this block of code adds a line to the file that says the number of players in the tall player list
    ofstream outFile; // declare an output file for analysis of output
    outFile.open(fileName, ios::app); // open the file

    outFile<<"Number of players over 6 feet, 11 inches = "<<TallPlayers.size()<<endl;
    outFile<<endl;

    outFile.close();



    printData(BigPlayers, "PlayerList.txt", "Big Player List"); // print the big player list

    // this block of code adds a line to the file that says the number of players over 350
    outFile.open(fileName, ios::app); // open the file

    outFile<<"Number of players over 350 lbs. = "<<BigPlayers.size()<<endl;
    outFile<<endl;
    
    outFile.close();


    populateTallestPlayers(TallPlayers, TallestPlayers); // populate the tallest player list

    sortByName(TallestPlayers); // sort the tallest by name

    printData(TallestPlayers, fileName, "Tallest Player List"); // print the list

    populateOldestPlayers(PlayerInfo, OldestPlayers); // populate the oldest list

    sortByName(OldestPlayers); // sort this list by name

    printData(OldestPlayers, fileName, "Oldest Players List"); // print the oldest

    populateYoungestPlayers(PlayerInfo, YoungestPlayers); // populate the youngest 

    sortByName(YoungestPlayers); // sort by name

    printData(YoungestPlayers, fileName, "Youngest Players List"); // print the list


    // delete the memory used inside the vector 
    for(unsigned long i = 0; i<PlayerInfo.size(); i++)
        delete PlayerInfo[i];
    
    PlayerInfo.clear(); // clear the vector memory
    TallPlayers.clear();
    BigPlayers.clear();
    YoungestPlayers.clear();
    TallestPlayers.clear();

    return 0;
}


void LoadNBADataFile(string fileName, vector<Person*>& Data)
{
    ifstream DataFile; // create the stream object 

    DataFile.open(fileName); // open the stream 

    if(DataFile){ // if the file is open continue
        
        string line = "";
        getline(DataFile, line);
        string first = "";
        string last = "";
        string jerseyNum = "";
        string pos = "";
        string length = "";
        string weight = "";
        string date = "";
        while(DataFile){
            first = "";
            last = "";
            jerseyNum = "";
            pos = "";
            length = "";
            weight = "";
            date = "";
            getline(DataFile, last, ',');
            getline(DataFile, first, ',');
            getline(DataFile, jerseyNum, ',');
            getline(DataFile, pos, ',');
            getline(DataFile, length, ',');
            getline(DataFile, weight, ',');
            getline(DataFile, date, '\n');
            
            FeetInches temp;
            temp.setLength(length);
            Date tempDate;
            tempDate.setMDY(date);
            if(!(last.empty())){
                NBAPlayer *tempPlayer = new NBAPlayer(first, last, temp, atof(weight.c_str()), tempDate, atoi(jerseyNum.c_str()), pos);
                Data.push_back(tempPlayer);
                tempPlayer = nullptr;
            }

        }
        DataFile.close();

    }else{ // if not print error message 
        cout<<"Hold on, the file could't open, try again!"<<endl;
    }
}


void LoadNFLDataFile(string fileName, vector<Person*>& Data)
{
    ifstream DataFile; // create the stream object 

    DataFile.open(fileName); // open the stream 

    if(DataFile){ // if the file is open continue
        
        string line = "";
        string name = "";
        string jerseyNum = "";
        string pos = "";
        string length = "";
        string weight = "";
        string date = "";
        string team = "";
        
        getline(DataFile, line);
        
        while(DataFile){
            name = "";
            jerseyNum = "";
            pos = "";
            length = "";
            weight = "";
            date = "";
            team = "";
            getline(DataFile, jerseyNum, ',');
            DataFile.get();
            getline(DataFile, name, '"');
            DataFile.get();
            getline(DataFile, pos, ',');
            getline(DataFile, length, ',');
            getline(DataFile, weight, ',');
            getline(DataFile, date, ',');
            getline(DataFile, team, '\n');
            
            FeetInches temp(0,atoi(length.c_str()));
            
            Date tempDate;
            tempDate.setMDY(date);
            if(!(name.empty())){
                NFLPlayer *tempPlayer = new NFLPlayer(name.substr(name.find(',')+2), name.substr(0, name.find(',')), temp, atof(weight.c_str()), tempDate, atoi(jerseyNum.c_str()), pos, team);
                Data.push_back(tempPlayer);
                tempPlayer = nullptr;
            }
        }
        DataFile.close();

    }else{ // if not print error message 
        cout<<"Hold on, the file could't open, try again!"<<endl;
    }
}


void printData(vector<Person*>& Data, string fileName, string outputLabel)
{
    ofstream outFile; // declare an output file for analysis of output
    outFile.open(fileName, ios::app); // open the file
    if(outFile){
        outFile<<outputLabel<<endl;
        //print the list 
        for(unsigned long i = 0; i<Data.size(); i++)
            outFile<<Data[i]->toString()<<endl;
        outFile<<endl;
        outFile.close(); // close the output file
    }else{
        cout<<"Error, File Handling"<<endl;
    }
    
}


void sortByName(vector<Person*>& Data)
{
    int size = Data.size();
    for (int itemsSorted = 1; itemsSorted < size; itemsSorted++) {
        Person *temp = Data[itemsSorted];
        int loc = itemsSorted - 1;
        while (loc >= 0 && Data[loc]->formal() > temp->formal()) {
            Data[loc + 1] = Data[loc];
            loc = loc - 1;
        }
        Data[loc + 1] = temp;
        
    }
}


void sortByHeight(vector<Person*>& Data)
{
    int size = Data.size();
    for (int itemsSorted = 1; itemsSorted < size; itemsSorted++) {
        Person *temp = Data[itemsSorted];
        int loc = itemsSorted - 1;
        while (loc >= 0 && Data[loc]->getHeight() > temp->getHeight()) {
            Data[loc + 1] = Data[loc];
            loc = loc - 1;
        }
        Data[loc + 1] = temp;
    }
}


void sortByWeight(vector<Person*>& Data)
{
    int size = Data.size();
    for (int itemsSorted = 1; itemsSorted < size; itemsSorted++) {
        Person *temp = Data[itemsSorted];
        int loc = itemsSorted - 1;
        while (loc >= 0 && Data[loc]->getWeight() > temp->getWeight()) {
            Data[loc + 1] = Data[loc];
            loc = loc - 1;
        }
        Data[loc + 1] = temp;
    }
}

void populateTall(vector<Person*>& initData, vector<Person*>& Data)
{
    FeetInches Tallest(6, 11);

    for(int i = 0; i<static_cast<int>(initData.size()); i++){
        if(initData[i]->getHeight() > Tallest){
            Data.push_back(initData[i]);
        }
    }
}

void populateBigPlayers(vector<Person*>& initData, vector<Person*>& Data)
{
    double Heaviest = 350;
    for(int i = 0; i<static_cast<int>(initData.size()); i++){
        if(initData[i]->getWeight() > Heaviest){
            Data.push_back(initData[i]);
        }
    }
}

void populateTallestPlayers(vector<Person*>& initData, vector<Person*>& Data)
{
    sortByHeight(initData);
    for(int i = 0; i<static_cast<int>(initData.size()); i++){
        if(initData[i]->getHeight()==initData.back()->getHeight()){
            Data.push_back(initData[i]);
        }
    }
}

void populateOldestPlayers(vector<Person*>& initData, vector<Person*>& Data)
{
    Date maxAge = initData[0]->getDOB();
    Date improperDate(0 ,0 , 0);

    for(int i = 1; i<static_cast<int>(initData.size()); i++){
        if(initData[i]->getDOB()<maxAge && initData[i]->getDOB()!=improperDate){
            maxAge = initData[i]->getDOB();
        }
    }

    for(int i = 0; i<static_cast<int>(initData.size()); i++){
        if(initData[i]->getDOB() == maxAge){
            Data.push_back(initData[i]);
        }
    }
}

void populateYoungestPlayers(vector<Person*>& initData, vector<Person*>& Data)
{
    Date minAge = initData[0]->getDOB();

    for(int i = 1; i<static_cast<int>(initData.size()); i++){
        if(initData[i]->getDOB()>minAge){
            minAge = initData[i]->getDOB();
        }
    }

    for(int i = 0; i<static_cast<int>(initData.size()); i++){
        if(initData[i]->getDOB() == minAge){
            Data.push_back(initData[i]);
        }
    }
}
