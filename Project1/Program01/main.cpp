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

        averageopen += stockData[i].getOpen();
        averageclose += (stockData[i]).getClose();
        averagehigh += (stockData[i]).getHigh();
        averagelow += (stockData[i]).getLow();
        averagevolume += (stockData[i]).getVolume();

        sum += stockData[i].getOpen(); // sum the cost of buying every day

        gainOrLoss += (stockData[i].getClose())-(stockData[i].getOpen()); // get the gain or loss of the stock over its entire life

    }

    // find the average
    averageopen = averageopen/(numStocks); 
    averageclose = averageclose/(numStocks);
    averagehigh = averagehigh/(numStocks);
    averagelow = averagelow/(numStocks);
    averagevolume = averagevolume/(numStocks);

    // loop to count the up and down days
    for(int i = 0; i<numStocks; i++){
        
        if(stockData[i].getOpen()==stockData[i].getClose()){
            neutral++;
            
        }
        else if(stockData[i].getOpen()<stockData[i].getClose()){
            countUp++;
        }
        else if(stockData[i].getOpen()>stockData[i].getClose()){
            countDown++;
        }
    }

    // output the first scheme
    cout<<setprecision(6)<<fixed;
    cout<<"Number of Days: "<<stockData.getSize()<<endl;
    cout<<"Date Range: "<<stockData[0].getDate()<<" to "<<stockData[(stockData.getSize()-1)].getDate()<<endl;
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
    cout<<"Stock Per Day Worth: "<<numStocks*(stockData[(numStocks-1)].getClose())<<endl;

    // output the third scheme

    cout<<"Buy/Sell Investment Scheme"<<endl;

    div();

    cout<<"Buy/Sell Worth: "<<gainOrLoss<<endl;
    
    div();
}

/*
Description: 
*/
void loadDataFile(string name, StockList &arr)
{
    ifstream inFile; // create the fileobject
    inFile.open(name); // open the file
    string line = "";  // create the line var
    int fileSize = count(inFile); // count the file lines
    inFile.open(name);// open the file
    getline(inFile, line);// get the dumb line not needed
    // create vars to hold the date 
    int year = 0; 
    int month = 0;
    int day = 0;
    
    double tempArr[6]; // create the array for data

    // for loop to get the data into the main array
    for(int i = 0; i<fileSize; i++){
        getline(inFile, line);// get the line
        // cut the line up  into each data segment
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
        
        StockDay temp(tempDate, tempArr); // create the stock data object
        
        arr.append(temp); // set into the array
    }
    inFile.close(); // close the file
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