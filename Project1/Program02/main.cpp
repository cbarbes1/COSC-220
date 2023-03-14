#include <iostream>
#include <iomanip>
#include "StockList.h"
#include "StockDay.h"
#include "Date.h"
#include <fstream>

using namespace std;

void loadDataFile(string, string, StockList&, StockList&);
int count(ifstream&);
void div();

int main()
{
    StockList stockData01;
    StockList stockData02
    string fileName1;
    string fileName2
    double initInvest01 = 0, initInvest02 = 0;
    int numStocks = 0;
    Date dateFirst;
    Date dateSecond;

    cout<<"Company 1 file: ";
    cin>>fileName1;

    cout<<"Company 2 file: ";
    cin>>fileName2

    loadDataFile(fileName1, stockData01);

    div();

    if(stockData01.getElement(0).getDate()<stockData02.getElement(0).getDate()){
        dateFirst = (stockData02.getElement(0)).getDate();
    }
    else if(stockData01.getElement(0).getDate()>stockData02.getElement(0).getDate()){
        dateFirst = (stockData01.getElement(0)).getDate();
    }
    else {
        dateFirst = (stockData01.getElement(0)).getDate();
    }

    if(stockData01.getElement(stockData01.getSize()).getDate()<stockData02.getElement(stockData02.getSize()).getDate()){
        dateSecond = (stockData02.getElement(stockData02.getSize())).getDate();
    }
    else if(stockData01.getElement(stockData01.getSize()).getDate()>stockData02.getElement(stockData02.getSize()).getDate()){
        dateSecond = (stockData01.getElement(stockData01.getSize())).getDate();
    }
    else {
        dateSecond = (stockData01.getElement(stockData01.getSize())).getDate();
    }
    

    cout<<"Simulation Date Range: "<<dateFirst<<" to "<<dateSecond<<endl;
    cout<<"Number of trading days:  "<<stockData02.getSize()<<endl;
    cout<<endl;
    //code for init and percent 
    cout<<"Initial Investment in Company 1: "; 

    cout<<"Initial Investment in Company 2: ";

    cout<<"Percent to move on each Transaction: ";

    cout<<endl;
    //code for the scheme
    cout<<"Daily Buy/Sell Simulation"<<endl;
    cout<<"Initial shares in company 1: "<<endl;
    cout<<"Initial shares in company 2: "<<endl;
    cout<<"Ending shares in company 1: "<<endl;
    cout<<"Ending shares in company 2:"<<endl;
    cout<<"Total investment value: "<<endl;
    cout<<"Total no buy/sell value: "<<endl;
    cout<<"Total earned by trading: "<<endl;
    cout<<endl;
    //code for 5 day scheme
    cout<<"Simulation Buy/Sell Every 5 Days."<<endl;
    cout<<"Initial shares in company 1: "<<endl;
    cout<<"Initial shares in company 2: "<<endl;
    cout<<"Ending shares in company 1: "<<endl;
    cout<<"Ending shares in company 2:"<<endl;
    cout<<"Total investment value: "<<endl;
    cout<<"Total no buy/sell value: "<<endl;
    cout<<"Total earned by trading: "<<endl;
    cout<<endl;
    //code for 10 day scheme
    cout<<"Simulation Buy/Sell Every 10 Days."<<endl;
    cout<<"Initial shares in company 1: "<<endl;
    cout<<"Initial shares in company 2: "<<endl;
    cout<<"Ending shares in company 1: "<<endl;
    cout<<"Ending shares in company 2:"<<endl;
    cout<<"Total investment value: "<<endl;
    cout<<"Total no buy/sell value: "<<endl;
    cout<<"Total earned by trading: "<<endl;
    cout<<endl;
    //code for 30 day scheme
    cout<<"Simulation Buy/Sell Every 30 Days."<<endl;
    cout<<"Initial shares in company 1: "<<endl;
    cout<<"Initial shares in company 2: "<<endl;
    cout<<"Ending shares in company 1: "<<endl;
    cout<<"Ending shares in company 2:"<<endl;
    cout<<"Total investment value: "<<endl;
    cout<<"Total no buy/sell value: "<<endl;
    cout<<"Total earned by trading: "<<endl;

}

void loadDataFile(string name1, string name2, StockList &arr1, StockList &arr2)
{
    ifstream inFile01;
    ifstream inFile02;
    inFile01.open(name1);
    inFile02.open(name2)
    string line1;
    string line2;
    int fileSize1 = count(inFile01);
    inFile01.open(name1);
    int fileSize2 = count(inFile02);
    inFile01.open(name2);

    int fileSize = 0;
    
    if(fileSize1<fileSize2){ fileSize = fileSize2;}
    else { fileSize = fileSize1;}

    getline(inFile01, line1);
    getLine(inFile02, line2);

    for(int i = 0; i<fileSize; i++){
        getline(inFile, line1);
        int year1 = stoi(line1.substr(0, line1.find("-")));
        line1 = line1.substr(line1.find('-')+1);
        int year2 = stoi(line2.substr(0, line2.find("-")));
        line2 = line2.substr(line2.find('-')+1);
        int month1 = stoi(line1.substr(0, line1.find('-')));
        line1 = line1.substr(line1.find('-')+1);
        int month2 = stoi(line2.substr(0, line2.find('-')));
        line2 = line2.substr(line.find('-')+1);
        int day1 = stoi(line1.substr(0, line1.find(',')));
        line1 = line1.substr(line.find(',')+1);
        int day2 = stoi(line2.substr(0, line2.find(',')));
        line2 = line2.substr(line2.find(',')+1);
        Date tempDate1(month1, day1, year1);
        Date tempDate2(month2, day2, year2);
        if(tempDate1==tempDate2){
            float tempArr1[5];
            int volume1;
            tempArr1[0] = stod(line1.substr(0, line1.find(',')));
            line1 = line1.substr(line1.find(',')+1);
            tempArr1[3] = stod(line1.substr(0, line1.find(',')));
            line1 = line1.substr(line1.find(',')+1);
            tempArr1[4] = stod(line1.substr(0, line1.find(',')));
            line1 = line1.substr(line1.find(',')+1);
            tempArr1[1] = stod(line1.substr(0, line1.find(',')));
            line1 = line1.substr(line1.find(',')+1);
            tempArr1[2] = stod(line1.substr(0, line1.find(',')));
            line1 = line1.substr(line1.find(',')+1);
            volume1 = stod(line1);
            StockDay temp1(tempDate, tempArr, volume);
            
            arr1.append(temp1);

            float tempArr2[5];
            int volume2;
            tempArr2[0] = stod(line2.substr(0, line2.find(',')));
            line2 = line2.substr(line2.find(',')+1);
            tempArr2[3] = stod(line.substr(0, line2.find(',')));
            line2 = line2.substr(line2.find(',')+1);
            tempArr2[4] = stod(line2.substr(0, line2.find(',')));
            line2 = line2.substr(line2.find(',')+1);
            tempArr2[1] = stod(line2.substr(0, line2.find(',')));
            line2 = line2.substr(line2.find(',')+1);
            tempArr2[2] = stod(line2.substr(0, line2.find(',')));
            line2 = line2.substr(line2.find(',')+1);
            volume2 = stod(line2);
            StockDay temp2(tempDate, tempArr, volume);
            
            arr2.append(temp2);
        }
    }
    inFile01.close();
    inFile02.close();
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