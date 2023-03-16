/*
Author: Cole Barbes
Creation Date: 03/10/23
Last Update: 03/16/23
Description: Program to do some stock schemes
*/
#include <iostream>
#include <iomanip>
 // include the h for needed classes
#include "StockList.h"
#include "StockDay.h"
#include "Date.h"
#include <fstream> // f stream for file stream

using namespace std; // standard

void loadDataFile(string, StockList&); // define function to load data
int count(ifstream&); // define count function
void div(); // divider function

int main()
{
    StockList stockData; // create the list object
    string fileName = ""; // create the filename var
    double averageopen = 0, averageclose = 0, averagehigh = 0, averagelow = 0; // create and init the average holders
    double averagevolume = 0; // create and init the average vol
    int countUp = 0, countDown = 0, neutral = 0; // create and init the count vars
    double sum = 0; // sum var to sum the cost
    double gainOrLoss = 0; // gain or lost var
    int numStocks = 0; // num stocks

    // take in the file name
    cout<<"File to load: ";
    cin>>fileName;

    loadDataFile(fileName, stockData); // call func to load the array

    div(); 

    numStocks = stockData.getSize(); // find the number of stocks
    
    // loop to find the averages and the sum of costs, as well as the gain or loss
    for(int i = 0; i<numStocks; i++){

        averageopen += (stockData.getElement(i)).getOpen();
        averageclose += (stockData.getElement(i)).getClose();
        averagehigh += (stockData.getElement(i)).getHigh();
        averagelow += (stockData.getElement(i)).getLow();
        averagevolume += (stockData.getElement(i)).getVolume();

        sum += stockData.getElement(i).getOpen();

        gainOrLoss += stockData.getElement(i).getClose() - stockData.getElement(i).getOpen();

    }

    // find the average
    averageopen = averageopen/(numStocks); 
    averageclose = averageclose/(numStocks);
    averagehigh = averagehigh/(numStocks);
    averagelow = averagelow/(numStocks);
    averagevolume = averagevolume/(numStocks);

    // loop to count the up and down days
    for(int i = 1; i<numStocks; i++){
        if(stockData.getElement(i).getOpen()>stockData.getElement(i-1).getClose()){
            countUp++;
        }
        else if(stockData.getElement(i).getOpen()<stockData.getElement(i-1).getClose()){
            countDown++;
        }
        else if(stockData.getElement(i).getOpen()==stockData.getElement(i-1).getClose()){
            neutral++;
        }
    }

    // output the first scheme
    cout<<setprecision(6)<<fixed;
    cout<<"Number of Days: "<<stockData.getSize()<<endl;
    cout<<"Date Range: "<<stockData.getElement(0).getDate()<<" to "<<(stockData.getElement(stockData.getSize()-1)).getDate()<<endl;
    cout<<"Up Days: "<<countUp<<endl;
    cout<<"Down Days: "<<countDown<<endl;
    cout<<"Neutral Days: "<<neutral<<endl;
    cout<<"Average Opening Value: "<<averageopen<<endl;
    cout<<"Average Closing Value: "<<averageclose<<endl;
    cout<<"Average High Value: "<<averagehigh<<endl;
    cout<<"Average Low Value: "<<averagelow<<endl;
    cout<<"Average Volume: "<<averagevolume<<endl;

    cout<<endl;

    //output the second scheme
    cout<<"Stock Per Day Investment Scheme"<<endl;

    div();

    cout<<setprecision(6)<<fixed;
    cout<<"Stock Per Day Cost: "<<sum<<endl;
    cout<<"Stock Per Day Shares: "<<stockData.getSize()<<endl;
    cout<<"Stock Per Day Worth: "<<numStocks*(stockData.getElement((numStocks-1)).getClose())<<endl;

    // output the third scheme

    cout<<"Buy/Sell Investment Scheme"<<endl;

    div();

    cout<<"Buy/Sell Worth: "<<gainOrLoss<<endl;
}

/*
Description: 
*/
void loadDataFile(string name, StockList &arr)
{
    ifstream inFile;
    inFile.open(name);
    string line;
    int fileSize = count(inFile);
    inFile.open(name);
    getline(inFile, line);
    int year = 0;
    int month = 0;
    int day = 0;
    
    double tempArr[6];
    for(int i = 0; i<fileSize; i++){
        getline(inFile, line);
        year = stoi(line.substr(0, line.find("-")));
        line = line.substr(line.find('-')+1);
        month = stoi(line.substr(0, line.find('-')));
        line = line.substr(line.find('-')+1);
        day = stoi(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        Date tempDate(month, day, year);
        tempArr[0] = stod(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        tempArr[3] = stod(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        tempArr[4] = stod(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        tempArr[1] = stod(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        tempArr[2] = stod(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        tempArr[5] = stod(line);
        if(i==1){ cout<<line<<endl;}
        StockDay temp(tempDate, tempArr);
        
        arr.append(temp);
    }
    inFile.close();
}

/*
count the lines in the file and close the file
*/
int count(ifstream& file){
    string line;
    int count = 0;
    getline(file, line);
    while(getline(file, line)){
        count++;
    }
    file.close();
    return count;
}

/*
simple div function
*/
void div()
{
    cout<<"---------------------------------------"<<endl;
    cout<<endl;
}