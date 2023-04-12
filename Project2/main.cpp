#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "Person.h"
#include "NBAPlayer.h"
#include "NFLPlayer.h"

using namespace std;

void LoadNBADataFile(string, vector<Person*>&);
void LoadNFLDataFile(string, vector<Person*>&);
void printData(vector<Person*>&, string, string);

void sortByName(vector<Person*>&);

void sortByHeight(vector<Person*>&);

void sortByWeight(vector<Person*>&);

void populateTallest(vector<Person*>&, vector<Person*>&);

void populateBigPlayers(vector<Person*>&, vector<Person*>&);

void populateTallestPlayers(vector<Person*>&, vector<Person*>&);

int main()
{
    //create the array
    vector<Person*> PlayerInfo;
    vector<Person*> TallPlayers;
    vector<Person*> BigPlayers;
    vector<Person*> YoungestPlayers;

    string fileName = "PlayerList.txt";

    // load Data into the vector
    LoadNBADataFile("NBA.csv", PlayerInfo);
    LoadNFLDataFile("NFL.csv", PlayerInfo);

    
    printData(PlayerInfo, fileName, "Player List");

    sortByName(PlayerInfo);

    populateTallest(PlayerInfo, TallPlayers);

    sortByHeight(PlayerInfo);

    populateBigPlayers(PlayerInfo, BigPlayers);

    sortByWeight(BigPlayers);

    printData(PlayerInfo, fileName, "Player List Sorted");


    printData(TallPlayers, fileName, "Tallest Players");
    
    
    ofstream outFile; // declare an output file for analysis of output
    outFile.open(fileName, ios::app); // open the file

    outFile<<"Number of players over 6 feet, 11 inches = "<<TallPlayers.size()<<endl;

    outFile.close();

    

    printData(BigPlayers, "PlayerList.txt", "Biggest Players");

    outFile.open(fileName, ios::app); // open the file

    outFile<<"Number of players over 350 lbs. = "<<BigPlayers.size()<<endl;
    
    outFile.close();

    // delete the memory used inside the vector 
    for(unsigned long i = 0; i<PlayerInfo.size(); i++)
        delete PlayerInfo[i];
    
    PlayerInfo.clear(); // clear the vector memory

    

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
        for(int i = 0; i<size; i++){
            if(Data[i]->formal() == Data[loc]->formal()){
                
            }
        }
        
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

void populateTallest(vector<Person*>& initData, vector<Person*>& Data)
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

void populateTallestPlayers(vector<Person*>&, vector<Person*>&)
{
}
