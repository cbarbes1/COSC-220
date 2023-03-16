#include <iostream>
#include <iomanip>
#include "StockList.h"
#include "StockDay.h"
#include "Date.h"
#include <fstream>

using namespace std;

void loadDataFile(string, string, StockList&, StockList&);
void simulate(double&, double&, double, double , StockList&, StockList&, int);
int count(ifstream&);
void div();

int main()
{

    StockList stockData01;
    StockList stockData02;

    string fileName1;
    string fileName2;

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

    cout<<"Company 1 file: ";
    cin>>fileName1;

    cout<<"Company 2 file: ";
    cin>>fileName2;

    loadDataFile(fileName1, fileName2, stockData01, stockData02);

    numStocks = stockData01.getSize();

    div();

    cout<<"Simulation Date Range: "<<stockData01.getElement(0).getDate()<<" to "<<stockData01.getElement(stockData01.getSize()-1).getDate()<<endl;
    cout<<"Number of trading days:  "<<numStocks<<endl;
    cout<<endl;

    //code for init and percent 
    cout<<"Initial Investment in Company 1: "; 
    cin>>initInvest01;
    cout<<"Initial Investment in Company 2: ";
    cin>>initInvest02;
    cout<<"Percent to move on each Transaction: ";
    cin>>percentMove;
    percentMove = percentMove/100;
    initStocks1 = initInvest01/stockData01.getElement(0).getOpen();
    initStocks2 = initInvest02/stockData02.getElement(0).getOpen();
    DailyStock1 = initStocks1;
    DailyStock2 = initStocks2;
    Daily5Stock1 = initStocks2;
    Daily5Stock2 = initStocks2;
    Daily30Stock1 =initStocks2;
    Daily30Stock2 =initStocks2;
    Daily10Stock1 = initStocks2;
    Daily10Stock2 = initStocks2;
    
    cout<<endl;
    //code for the scheme
    
    simulate(DailyStock1, DailyStock2, percentMove, numStocks, stockData01, stockData02, 0);
    totalValue = (DailyStock1*(stockData01.getElement(numStocks-1).getClose()))+(DailyStock2*(stockData02.getElement(numStocks-1).getClose()));
    totalNoBuySell = (initStocks1*(stockData01.getElement(numStocks-1).getClose()))+(initStocks2*(stockData02.getElement(numStocks-1).getClose()));
    totalEarned = totalValue-totalNoBuySell;
    
    cout<<"Daily Buy/Sell Simulation"<<endl;
    cout<<setprecision(6)<<fixed<<endl;
    cout<<"Initial shares in company 1: "<<initStocks1<<endl;
    cout<<"Initial shares in company 2: "<<initStocks2<<endl;
    
    cout<<"Ending shares in company 1: "<<DailyStock1<<endl;
    cout<<"Ending shares in company 2:"<<DailyStock2<<endl;
    cout<<"Total investment value: "<<totalValue<<endl;
    cout<<"Total no buy/sell value: "<<totalNoBuySell<<endl;
    cout<<"Total earned by trading: "<<totalEarned<<endl;
    cout<<endl;

    //code for 5 day scheme

    
    simulate(Daily5Stock1, Daily5Stock2, percentMove, numStocks, stockData01, stockData02, 5);
    totalValue = (DailyStock1*(stockData01.getElement(numStocks-1).getClose()))+(DailyStock2*(stockData02.getElement(numStocks-1).getClose()));
    totalNoBuySell = (initStocks1*(stockData01.getElement(numStocks-1).getClose()))+(initStocks2*(stockData02.getElement(numStocks-1).getClose()));
    totalEarned = totalValue-totalNoBuySell;

    cout<<"Simulation Buy/Sell Every 5 Days."<<endl;
    cout<<"Initial shares in company 1: "<<initStocks1<<endl;
    cout<<"Initial shares in company 2: "<<initStocks2<<endl;
    
    cout<<"Ending shares in company 1: "<<DailyStock1<<endl;
    cout<<"Ending shares in company 2:"<<DailyStock2<<endl;
    cout<<"Total investment value: "<<totalValue<<endl;
    cout<<"Total no buy/sell value: "<<totalNoBuySell<<endl;
    cout<<"Total earned by trading: "<<totalEarned<<endl;
    cout<<endl;
    //code for 10 day scheme
    simulate(Daily10Stock1, Daily10Stock2, percentMove, numStocks, stockData01, stockData02, 10);
    totalValue = (DailyStock1*(stockData01.getElement(numStocks-1).getClose()))+(DailyStock2*(stockData02.getElement(numStocks-1).getClose()));
    totalNoBuySell = (initStocks1*(stockData01.getElement(numStocks-1).getClose()))+(initStocks2*(stockData02.getElement(numStocks-1).getClose()));
    totalEarned = totalValue-totalNoBuySell;

    cout<<"Simulation Buy/Sell Every 10 Days."<<endl;
    cout<<"Initial shares in company 1: "<<initStocks1<<endl;
    cout<<"Initial shares in company 2: "<<initStocks2<<endl;
    
    cout<<"Ending shares in company 1: "<<DailyStock1<<endl;
    cout<<"Ending shares in company 2:"<<DailyStock2<<endl;
    cout<<"Total investment value: "<<totalValue<<endl;
    cout<<"Total no buy/sell value: "<<totalNoBuySell<<endl;
    cout<<"Total earned by trading: "<<totalEarned<<endl;
    cout<<endl;
    //code for 30 day scheme
    simulate(Daily30Stock1, Daily30Stock2, percentMove, numStocks, stockData01, stockData02, 30);
    totalValue = (DailyStock1*(stockData01.getElement(numStocks-1).getClose()))+(DailyStock2*(stockData02.getElement(numStocks-1).getClose()));
    totalNoBuySell = (initStocks1*(stockData01.getElement(numStocks-1).getClose()))+(initStocks2*(stockData02.getElement(numStocks-1).getClose()));
    totalEarned = totalValue-totalNoBuySell;

    cout<<"Simulation Buy/Sell Every 30 Days."<<endl;
    cout<<"Initial shares in company 1: "<<initStocks1<<endl;
    cout<<"Initial shares in company 2: "<<initStocks2<<endl;

    cout<<"Ending shares in company 1: "<<DailyStock1<<endl;
    cout<<"Ending shares in company 2:"<<DailyStock2<<endl;
    cout<<"Total investment value: "<<totalValue<<endl;
    cout<<"Total no buy/sell value: "<<totalNoBuySell<<endl;
    cout<<"Total earned by trading: "<<totalEarned<<endl;
    cout<<endl;

}

void loadDataFile(string name1, string name2, StockList &arr1, StockList &arr2)
{
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
    int fileSize1 = count(inFile01);
    inFile01.open(name1);
    int fileSize2 = count(inFile02);
    inFile02.open(name2);
    int year1 = 0;
    int year2 = 0;
    int month1 = 0;
    int month2 = 0;
    int day1 = 0;
    int day2 = 0;
    double tempArr1[6];
    double tempArr2[6];
    getline(inFile01, line1);
    getline(inFile02, line2);
    
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

    if(temparr1.getElement(0).getDate()<temparr2.getElement(0).getDate()){
        start = temparr2.getElement(0).getDate();
    }
    else if(temparr2.getElement(0).getDate()<temparr1.getElement(0).getDate()){
        start = temparr1.getElement(0).getDate();
    }
    else {
        start = temparr1.getElement(0).getDate();
    }
    if(temparr1.getElement(temparr1.getSize()-1).getDate()<temparr2.getElement(temparr2.getSize()-1).getDate()){
        end = temparr2.getElement(temparr2.getSize()-1).getDate();
    }
    else if(temparr2.getElement(temparr2.getSize()-1).getDate()<temparr1.getElement(temparr1.getSize()-1).getDate()){
        end = temparr1.getElement(temparr1.getSize()-1).getDate();
    }
    else {
        end = temparr1.getElement(temparr1.getSize()-1).getDate();
    }
    
    for(int i =0; i<temparr1.getSize(); i++){
        for(int j = 0; j<temparr2.getSize(); j++){
            if((temparr1.getElement(i).getDate())==(temparr2.getElement(j).getDate())){
                arr1.append(temparr1.getElement(i));
                arr2.append(temparr2.getElement(j));
            }
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
void simulate(double& Stock1, double& Stock2, double percentMove, double numStocks, StockList& stockData01, StockList& stockData02, int sim)
{
    double Stocks1 = Stock1;
    double Stocks2 = Stock2;
    double moneyHolder = 0;
    cout<<stockData01.getElement(0).getClose();
    if(sim == 0){
        for(int i = 1; i<(numStocks-1); i++){ 
            if(stockData01.getElement(i).getClose()>stockData01.getElement(i-1).getOpen()&&stockData02.getElement(i).getClose()<stockData02.getElement(i-1).getOpen()){
                moneyHolder = (percentMove*(Stocks1));
                Stocks1 = (Stocks1 - moneyHolder);
                moneyHolder = moneyHolder*stockData01.getElement(i).getClose();
                Stocks2 = Stocks2 + (moneyHolder/stockData02.getElement(i).getClose());
            }
            else if(stockData02.getElement(i).getClose()>stockData02.getElement(i-1).getOpen()&&stockData01.getElement(i).getClose()>stockData01.getElement(i-1).getOpen()){
                moneyHolder = (percentMove*Stocks2);
                Stocks2 = Stocks2 - moneyHolder;
                moneyHolder = moneyHolder*stockData02.getElement(i).getClose();
                
                Stocks1 = Stocks1 + (moneyHolder/stockData01.getElement(i).getClose());
            }
        }
    }
    else if(sim==5){
        for(int i = 5; i<numStocks; i+=5){
            if(stockData01.getElement(i).getClose()>stockData01.getElement(i-5).getOpen()&&stockData02.getElement(i).getClose()<stockData02.getElement(i-1).getOpen()){
                double moneyHolder = (percentMove*Stocks1);
                Stocks1 = Stocks1 - moneyHolder;
                moneyHolder = moneyHolder*stockData01.getElement(i).getClose();
                
                Stocks2 = Stocks2 + (moneyHolder/stockData02.getElement(i).getClose());
            }
            else if(stockData02.getElement(i).getClose()>stockData02.getElement(i-5).getOpen()&&stockData01.getElement(i).getClose()>stockData01.getElement(i-1).getOpen()){
                double moneyHolder = (percentMove*Stocks2);
                Stocks2 = Stocks2 - moneyHolder;
                moneyHolder = moneyHolder*stockData02.getElement(i).getClose();
                
                Stocks1 = Stocks1 + (moneyHolder/stockData01.getElement(i).getClose());
            }
        }
    }
    else if(sim==10){
        for(int i = 10; i<numStocks; i+=10){
            if(stockData01.getElement(i).getClose()>stockData01.getElement(i-10).getOpen()&&stockData02.getElement(i).getOpen()<stockData02.getElement(i-1).getOpen()){
                double moneyHolder = (percentMove*Stocks1);
                Stocks1 = Stocks1 - moneyHolder;
                moneyHolder = moneyHolder*stockData01.getElement(i).getClose();
                
                Stocks2 = Stocks2 + (moneyHolder*stockData02.getElement(i).getClose());
            }
            else if(stockData02.getElement(i).getClose()>stockData02.getElement(i-10).getOpen()&&stockData01.getElement(i).getClose()>stockData01.getElement(i-1).getOpen()){
                double moneyHolder = (percentMove*Stocks2);
                Stocks2 = Stocks2 - moneyHolder;
                moneyHolder = moneyHolder*stockData02.getElement(i).getClose();
                
                Stocks1 = Stocks1 + (moneyHolder*stockData01.getElement(i).getClose());
            }
        }
    }
    else if(sim==30){
        for(int i = 30; i<numStocks; i+=30){
            if(stockData01.getElement(i).getClose()>stockData01.getElement(i-30).getOpen()&&stockData02.getElement(i).getClose()<stockData02.getElement(i-1).getOpen()){
                double moneyHolder = (percentMove*Stocks1);
                Stocks1 = Stocks1 - moneyHolder;
                moneyHolder = moneyHolder*stockData01.getElement(i).getClose();
                
                Stocks2 = Stocks2 + (moneyHolder*stockData02.getElement(i).getClose());
            }
            else if(stockData02.getElement(i).getClose()>stockData02.getElement(i-30).getOpen()&&stockData01.getElement(i).getClose()>stockData01.getElement(i-1).getOpen()){
                double moneyHolder = (percentMove*Stocks2);
                Stocks2 = Stocks2 - moneyHolder;
                moneyHolder = moneyHolder*stockData02.getElement(i).getClose();
                
                Stocks1 = Stocks1 + (moneyHolder*stockData01.getElement(i).getClose());
            }
        }
    }
    Stock1 = Stocks1;
    Stock2 = Stocks2;
}
void div()
{
    cout<<"---------------------------------------"<<endl;
    cout<<endl;
}