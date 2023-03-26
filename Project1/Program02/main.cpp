/*
Author: Cole Barbes
Creation Date: 03/10/23
Last Update: 03/16/23
Description: This program uses class objects that hold stock data and create a stock list of 2 companys
 
*/
#include <iostream>
#include <iomanip>
#include "StockList.h" // include the header
#include "StockDay.h" // include the header
#include "Date.h" // include the header
#include <fstream> 

using namespace std;

void loadDataFile(string, string, StockList&, StockList&); // function to load both files
void simulate(double&, double&, double, double , StockList&, StockList&, int); // function to simulate buying 
int count(ifstream&); // count the lines
void div(); // divider printer

int main()
{

    StockList stockData01; // create stock list 1
    StockList stockData02; // create stock list 2

    // create the string for the name
    string fileName1 = "";
    string fileName2 = "";

    // create vars to hold all calculation related numbers
    double initInvest01 = 0, initInvest02 = 0;
    double initStocks1 = 0, initStocks2 = 0;
    double DailyStock1 = 0, DailyStock2 = 0;
    double Daily5Stock1 = 0, Daily5Stock2 = 0;
    double Daily10Stock1 = 0, Daily10Stock2 = 0;
    double Daily30Stock1 = 0, Daily30Stock2 = 0;
    double totalValue = 0;
    double totalNoBuySell = 0;
    double totalEarned = 0;
    int numStocks = 0;
    double percentMove = 0;

    // take in the file names
    cout<<"Company 1 file: ";
    cin>>fileName1;

    cout<<"Company 2 file: ";
    cin>>fileName2;

    loadDataFile(fileName1, fileName2, stockData01, stockData02); // load the data file 

    numStocks = stockData01.getSize(); // get the size

    div();

    // print the basic needed info
    cout<<"Simulation Date Range: "<<stockData01[0].getDate()<<" to "<<stockData01[(stockData01.getSize()-1)].getDate()<<endl;
    cout<<"Number of trading days:  "<<numStocks<<endl;
    cout<<endl;

    //code for initial invest
    cout<<"Initial Investment in Company 1: "; 
    cin>>initInvest01;
    cout<<"Initial Investment in Company 2: ";
    cin>>initInvest02;
    cout<<"Percent to move on each Transaction: ";
    cin>>percentMove;
    // find all needed vars for code ahead
    percentMove = percentMove/100;
    
    initStocks1 = initInvest01/stockData01[0].getOpen();
    initStocks2 = initInvest02/stockData02[0].getOpen();

    DailyStock1 = initStocks1;
    DailyStock2 = initStocks2;
    Daily5Stock1 = initStocks1;
    Daily5Stock2 = initStocks2;
    Daily30Stock1 =initStocks1;
    Daily30Stock2 =initStocks2;
    Daily10Stock1 = initStocks1;
    Daily10Stock2 = initStocks2;
    
    cout<<endl;
    //code for the scheme
    
    // do some needed simulation
    simulate(DailyStock1, DailyStock2, percentMove, numStocks, stockData01, stockData02, 0);
    totalValue = (DailyStock1*(stockData01[numStocks-1].getClose()))+(DailyStock2*(stockData02[numStocks-1].getClose()));
    totalNoBuySell = (initStocks1*(stockData01[numStocks-1].getClose()))+(initStocks2*(stockData02[numStocks-1].getClose()));
    totalEarned = totalValue-totalNoBuySell;
    
    // create the first sim
    cout<<"Daily Buy/Sell Simulation"<<endl;
    cout<<setprecision(6)<<fixed<<endl;
    cout<<"Initial shares in company 1: "<<initStocks1<<endl;
    cout<<"Initial shares in company 2: "<<initStocks2<<endl;
    cout<<"Ending shares in company 1: "<<DailyStock1<<endl;
    cout<<"Ending shares in company 2: "<<DailyStock2<<endl;
    cout<<"Total investment value: "<<totalValue<<endl;
    cout<<"Total no buy/sell value: "<<totalNoBuySell<<endl;
    cout<<"Total earned by trading: "<<totalEarned<<endl;
    cout<<endl;

    //code for 5 day scheme sim
    simulate(Daily5Stock1, Daily5Stock2, percentMove, numStocks, stockData01, stockData02, 5);
    totalValue = (Daily5Stock1*(stockData01[numStocks-1].getClose()))+(Daily5Stock2*(stockData02[numStocks-1].getClose()));
    totalNoBuySell = (initStocks1*(stockData01[numStocks-1].getClose()))+(initStocks2*(stockData02[numStocks-1].getClose()));
    totalEarned = totalValue-totalNoBuySell;

    // create the second sim
    cout<<"Simulation Buy/Sell Every 5 Days."<<endl;
    cout<<"Initial shares in company 1: "<<initStocks1<<endl;
    cout<<"Initial shares in company 2: "<<initStocks2<<endl;
    
    cout<<"Ending shares in company 1: "<<Daily5Stock1<<endl;
    cout<<"Ending shares in company 2: "<<Daily5Stock2<<endl;
    cout<<"Total investment value: "<<totalValue<<endl;
    cout<<"Total no buy/sell value: "<<totalNoBuySell<<endl;
    cout<<"Total earned by trading: "<<totalEarned<<endl;
    cout<<endl;

    //code for 10 day scheme
    simulate(Daily10Stock1, Daily10Stock2, percentMove, numStocks, stockData01, stockData02, 10);
    totalValue = (Daily10Stock1*(stockData01[numStocks-1].getClose()))+(Daily10Stock2*(stockData02[numStocks-1].getClose()));
    totalNoBuySell = (initStocks1*(stockData01[numStocks-1].getClose()))+(initStocks2*(stockData02[numStocks-1].getClose()));
    totalEarned = totalValue-totalNoBuySell;

    // create the third sim
    cout<<"Simulation Buy/Sell Every 10 Days."<<endl;
    cout<<"Initial shares in company 1: "<<initStocks1<<endl;
    cout<<"Initial shares in company 2: "<<initStocks2<<endl;
    cout<<"Ending shares in company 1: "<<Daily10Stock1<<endl;
    cout<<"Ending shares in company 2: "<<Daily10Stock2<<endl;
    cout<<"Total investment value: "<<totalValue<<endl;
    cout<<"Total no buy/sell value: "<<totalNoBuySell<<endl;
    cout<<"Total earned by trading: "<<totalEarned<<endl;
    cout<<endl;

    //code for 30 day scheme
    simulate(Daily30Stock1, Daily30Stock2, percentMove, numStocks, stockData01, stockData02, 30);
    totalValue = (Daily30Stock1*(stockData01[numStocks-1].getClose()))+(Daily30Stock2*(stockData02[numStocks-1].getClose()));
    totalNoBuySell = (initStocks1*(stockData01[numStocks-1].getClose()))+(initStocks2*(stockData02[numStocks-1].getClose()));
    totalEarned = totalValue-totalNoBuySell;

    // create the fourth sim
    cout<<"Simulation Buy/Sell Every 30 Days."<<endl;
    cout<<"Initial shares in company 1: "<<initStocks1<<endl;
    cout<<"Initial shares in company 2: "<<initStocks2<<endl;
    cout<<"Ending shares in company 1: "<<Daily30Stock1<<endl;
    cout<<"Ending shares in company 2: "<<Daily30Stock2<<endl;
    cout<<"Total investment value: "<<totalValue<<endl;
    cout<<"Total no buy/sell value: "<<totalNoBuySell<<endl;
    cout<<"Total earned by trading: "<<totalEarned<<endl;
    cout<<endl;

}

/*
Description: This function loads the data file into two arrays and then gets the common dates and sets them into respective array
Parameters: the two names and the stocklist arrays
Return: return nothing only edit the referenced array locations
*/
void loadDataFile(string name1, string name2, StockList &arr1, StockList &arr2)
{

    // create all needed vars
    Date start;
    Date end;
    StockList temparr1;
    StockList temparr2;
    ifstream inFile01;
    ifstream inFile02;
    inFile01.open(name1);
    inFile02.open(name2);
    string line1;
    string line2;
    int year1 = 0;
    int year2 = 0;
    int month1 = 0;
    int month2 = 0;
    int day1 = 0;
    int day2 = 0;

    // create the arrays
    double tempArr1[6];
    double tempArr2[6];

    // create the file vars
    int fileSize1 = count(inFile01);
    inFile01.open(name1);
    int fileSize2 = count(inFile02);
    inFile02.open(name2);

    //get the dumb line
    getline(inFile01, line1);
    getline(inFile02, line2);
    
    // loop for the first file
    for(int i = 0; i<fileSize1; i++){
        getline(inFile01, line1);
        
        year1 = stoi(line1.substr(0, line1.find("-")));
        line1 = line1.substr(line1.find('-')+1);
        month1 = stoi(line1.substr(0, line1.find('-')));
        line1 = line1.substr(line1.find('-')+1);
        day1 = stoi(line1.substr(0, line1.find(',')));
        line1 = line1.substr(line1.find(',')+1);
        
        Date tempDate1(month1, day1, year1);
        
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
        tempArr1[5] = stod(line1);
        StockDay temp1(tempDate1, tempArr1);
            
            
        temparr1.append(temp1);
    }

    // loop for the second 
    for(int i = 0; i<fileSize2; i++){
        getline(inFile02, line2);
        year2 = stoi(line2.substr(0, line2.find("-")));
        line2 = line2.substr(line2.find('-')+1);
        month2 = stoi(line2.substr(0, line2.find('-')));
        line2 = line2.substr(line2.find('-')+1);
        day2 = stoi(line2.substr(0, line2.find(',')));
        line2 = line2.substr(line2.find(',')+1);
        Date tempDate2(month2, day2, year2);
        
        
        tempArr2[0] = stod(line2.substr(0, line2.find(',')));
        line2 = line2.substr(line2.find(',')+1);
        tempArr2[3] = stod(line2.substr(0, line2.find(',')));
        line2 = line2.substr(line2.find(',')+1);
        tempArr2[4] = stod(line2.substr(0, line2.find(',')));
        line2 = line2.substr(line2.find(',')+1);
        tempArr2[1] = stod(line2.substr(0, line2.find(',')));
        line2 = line2.substr(line2.find(',')+1);
        tempArr2[2] = stod(line2.substr(0, line2.find(',')));
        line2 = line2.substr(line2.find(',')+1);
        tempArr2[5] = stod(line2);
        StockDay temp2(tempDate2, tempArr2);
            
        temparr2.append(temp2);
        
    }

    // check the start date
    if(temparr1[0].getDate()<temparr2[0].getDate()){
        start = temparr2[0].getDate();
    }
    else if(temparr2[0].getDate()<temparr1[0].getDate()){
        start = temparr1[0].getDate();
    }
    else {
        start = temparr1[0].getDate();
    }

    // check the end date
    if(temparr1[(temparr1.getSize()-1)].getDate()<temparr2[(temparr2.getSize()-1)].getDate()){
        end = temparr2.getElement(temparr2.getSize()-1).getDate();
    }
    else if(temparr2[(temparr2.getSize()-1)].getDate()<temparr1[(temparr1.getSize()-1)].getDate()){
        end = temparr1[(temparr1.getSize()-1)].getDate();
    }
    else {
        end = temparr1[(temparr1.getSize()-1)].getDate();
    }
    
    // for loop to append the arrays with the needed data
    for(int i = temparr1.find(start); i<temparr1.find(end); i++){
        arr2.append(temparr2[temparr2.find(temparr1[i].getDate())]);
        
    }
    // for loop to append the arrays with the needed data
    for(int i = temparr2.find(start); i<temparr2.find(end); i++){
        arr1.append(temparr1[temparr1.find(temparr2[i].getDate())]);
    }

    // close the files
    inFile01.close();
    inFile02.close();
}

/*
Description: count the number of lines of data in a file
Parameters: given a file ifstream
Return: 
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
Description: this function simulates each section based on a defined version of the function
Parameters: the stock init values reference vars, the percent move, the number of stocks, and the arrays, then the sim parameter for which one
*/
void simulate(double& Stocks1, double& Stocks2, double percentMove, double numStocks, StockList& stockData01, StockList& stockData02, int sim)
{
    double moneyHolder = 0;
    if(sim == 0){ // if sim 0 run sim for 1 day
        for(int i = 0; i<numStocks; i++){ 
            // loop through the arrays 
            // find the cheaper stock, set into the stock
            if(stockData01[i].getClose()>stockData01[i].getOpen()&&stockData02[i].getClose()<stockData02[i].getOpen()){ 
                moneyHolder = (percentMove*(Stocks1));
                Stocks1 = (Stocks1 - moneyHolder);
                moneyHolder = moneyHolder*stockData01[i].getClose();
                Stocks2 = Stocks2 + (moneyHolder/stockData02[i].getClose());
            }
            else if(stockData02[i].getClose()>stockData02[i].getOpen()&&stockData01[i].getClose()<stockData01[i].getOpen()){
                moneyHolder = (percentMove*(Stocks2));
                Stocks2 = Stocks2 - moneyHolder;
                moneyHolder = moneyHolder*stockData02[i].getClose();
                
                Stocks1 = Stocks1 + (moneyHolder/stockData01[i].getClose());
            }
        }
    }
    else if(sim==5){// if sim 5 run sim for 5 day
    // loop through the arrays 
        for(int i = 5; i<numStocks; i+=5){
            // loop through the arrays 
            // find the cheaper stock, set into the stock
            if(stockData01[i].getClose()>stockData01[i-5].getOpen()&&stockData02[i].getClose()<stockData02[i-5].getOpen()){
                moneyHolder = (percentMove*Stocks1);
                Stocks1 = Stocks1 - moneyHolder;
                moneyHolder = moneyHolder*stockData01[i].getClose();
                
                Stocks2 = Stocks2 + (moneyHolder/stockData02[i].getClose());
            }
            else if(stockData02[i].getClose()>stockData02[i-5].getOpen()&&stockData01[i].getClose()<stockData01[i-5].getOpen()){
                moneyHolder = (percentMove*Stocks2);
                Stocks2 = Stocks2 - moneyHolder;
                moneyHolder = moneyHolder*stockData02[i].getClose();
                
                Stocks1 = Stocks1 + (moneyHolder/stockData01[i].getClose());
            }
        }
    }
    else if(sim==10){// if sim 10 run sim for 10 day
    // loop through the arrays 
        for(int i = 10; i<numStocks; i+=10){
            // loop through the arrays 
            // find the cheaper stock, set into the stock
            if(stockData01[i].getClose()>stockData01[i-10].getOpen()&&stockData02[i].getClose()<stockData02[i-10].getOpen()){
                moneyHolder = (percentMove*Stocks1);
                Stocks1 = Stocks1 - moneyHolder;
                moneyHolder = moneyHolder*stockData01[i].getClose();
                
                Stocks2 = Stocks2 + (moneyHolder/stockData02[i].getClose());
            }
            else if(stockData02[i].getClose()>stockData02[i-10].getOpen()&&stockData01[i].getClose()<stockData01[i-10].getOpen()){
                moneyHolder = (percentMove*Stocks2);
                Stocks2 = Stocks2 - moneyHolder;
                moneyHolder = moneyHolder*stockData02[i].getClose();
                
                Stocks1 = Stocks1 + (moneyHolder/stockData01[i].getClose());
            }
        }
    }
    else if(sim==30){ // if sim 30 run sim for 30 day
    // loop through the arrays 
        for(int i = 30; i<numStocks; i+=30){
            // loop through the arrays 
            // find the cheaper stock, set into the stock
            if(stockData01[i].getClose()>stockData01[i-30].getOpen()&&stockData02[i].getClose()<stockData02[i-30].getOpen()){
                moneyHolder = (percentMove*Stocks1);
                Stocks1 = Stocks1 - moneyHolder;
                moneyHolder = moneyHolder*stockData01[i].getClose();
                
                Stocks2 = Stocks2 + (moneyHolder/stockData02[i].getClose());
            }
            else if(stockData02[i].getClose()>stockData02[i-30].getOpen()&&stockData01[i].getClose()<stockData01[i-30].getOpen()){
                moneyHolder = (percentMove*Stocks2);
                Stocks2 = Stocks2 - moneyHolder;
                moneyHolder = moneyHolder*stockData02[i].getClose();
                
                Stocks1 = Stocks1 + (moneyHolder/stockData01[i].getClose());
            }
        }
    }
}

/*
simple divider printer
*/
void div()
{
    cout<<"---------------------------------------"<<endl;
    cout<<endl;
}