#include <iostream>
#include <cstdlib>    
#include <ctime>       

#include "Die.h"
#include "Array2D.h"

using namespace std;

bool rollCheck(Array2D &, int, int, int);
void diceRoller(Array2D &, int, int);

int main() 
{
    srand(time(0));

    Array2D Simulation;

    int trials = 0;
    int rolls = 0;
    int count = 0;
    bool checker = false;

    cout<<"Please enter the number of trials: "<<endl;
    cin>>trials;
    cout<<"Please enter the number of rolls per trial: "<<endl;
    cin>>rolls;
    
    while(trials < 1 && rolls < 1){
        cout<<"You cannot do 0 trials or 0 rolls"<<endl;
        cout<<"Please enter the number of trials: "<<endl;
        cin>>trials;
        cout<<"Please enter the number of rolls per trial: "<<endl;
        cin>>rolls;
    }

    Simulation.resize(trials, rolls);

    diceRoller(Simulation, trials, rolls);

    for(int i = 0; i<trials; i++){
        checker = rollCheck(Simulation, i, 0, Simulation.get(i, 0));
        if(checker){ 
            count++;
            Simulation.rowPrint(i);
        }
    }

    cout<<"Number of trials resulting in the same roll value was "<<count<<"."<<endl;

    return 0;
}

bool rollCheck(Array2D &Arr, int t, int y, int value)
{
    if(Arr.get(t, y)==value&& y<(Arr.getCols()-1)){
        return rollCheck(Arr, t, y+1, value);
    }
    else if(Arr.get(t, y)==value&&y==(Arr.getCols()-1)){
        return true;
    }
    else{
        return false;
    }
}

void diceRoller(Array2D & S, int trials, int rolls)
{
    Die d1;
    Die d2;

    for(int i = 0; i<trials; i++)
    {
        for(int j = 0; j<rolls; j++)
        {
            d1.roll();
            d2.roll();
            S.set(i, j, (d1.getValue()+d2.getValue()));
        }
    }

}