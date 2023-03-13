#include <iostream>
#include <iomanip>
#include "StockList.h"
#include "StockDay.h"
#include "Date.h"
#include <fstream>

using namespace std;

void loadDataFile(string, StockList&);
int count(ifstream&);
void div();

int main()
{
    StockList stockData;
    string fileName;
    double averageopen, averageclose, averagehigh, averagelow, averagevolume = 0;
    int countUp, countDown, neutral = 0;
    double sum = 0;
    double gainOrLoss = 0;
    int numStocks = 0;

    cout<<"File to load: ";
    cin>>fileName;

    loadDataFile(fileName, stockData);

    div();

    numStocks = stockData.getSize();

    for(int i = 0; i<numStocks; i++){

        averageopen += (stockData.getElement(i)).getOpen();
        averageclose += (stockData.getElement(i)).getClose();
        averagehigh += (stockData.getElement(i)).getAdjClose();
        averagelow += (stockData.getElement(i)).getLow();
        averagevolume += (stockData.getElement(i)).getVolume();

        sum += stockData.getElement(i).getOpen();

        gainOrLoss += stockData.getElement(i).getClose() - stockData.getElement(i).getOpen();

    }
    averageopen = averageopen/numStocks;
    averageclose = averageclose/numStocks;
    averagehigh = averagehigh/numStocks;
    averagelow = averagelow/numStocks;
    averagevolume = averagevolume/numStocks;

    for(int i = 0; i<numStocks; i++){
        if(stockData.getElement(i).getClose()<stockData.getElement(i+1).getClose()){
            countUp++;
        }
        else if(stockData.getElement(i).getClose()>stockData.getElement(i+1).getClose()){
            countDown++;
        }
        else if(stockData.getElement(i).getClose()==stockData.getElement(i+1).getClose()){
            neutral++;
        }
    }

    cout<<setprecision(10);
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

    cout<<"Stock Per Day Investment Scheme"<<endl;

    div();

    cout<<"Stock Per Day Cost: "<<sum<<endl;
    cout<<"Stock Per Day Shares: "<<stockData.getSize()<<endl;
    cout<<"Stock Per Day Worth: "<<numStocks*stockData.getElement((numStocks-1)).getClose()<<endl;

    cout<<"Buy/Sell Investment Scheme"<<endl;

    div();

    cout<<"Buy/Sell Worth: "<<gainOrLoss<<endl;
}

void loadDataFile(string name, StockList &arr)
{
    ifstream inFile;
    inFile.open(name);
    string line;
    int fileSize = count(inFile);
    inFile.open(name);
    

    getline(inFile, line);
    for(int i = 0; i<fileSize; i++){
        getline(inFile, line);
        int year = stoi(line.substr(0, line.find("-")));
        line = line.substr(line.find('-')+1);
        int month = stoi(line.substr(0, line.find('-')));
        line = line.substr(line.find('-')+1);
        int day = stoi(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        Date tempDate(month, day, year);
        float tempArr[5];
        int volume;
        tempArr[0] = stod(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        tempArr[1] = stod(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        tempArr[2] = stod(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        tempArr[3] = stod(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        tempArr[4] = stod(line.substr(0, line.find(',')));
        line = line.substr(line.find(',')+1);
        volume = stod(line);
        StockDay temp(tempDate, tempArr, volume);
        
        arr.append(temp);
    }
    inFile.close();
}

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

void div()
{
    cout<<"---------------------------------------"<<endl;
    cout<<endl;
}