/*
Author: Cole Barbes
Creation Date: 04/26/23
Last Update: 04/26/23
Description: This file implements a priority queue
*/
#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>
#include "PriorityQueue.h" // import priority queue h file
#include "Process.h" // import the process h file

using namespace std; 
using namespace std::chrono;

void runSimulation(int, int, int, int, double, int); // simulation function

int main()
{
    srand(time(0)); // seed rand

    Process progExecution; // temp process

    vector<int> waitTimes;

    // variables
    int CPUCores = 0;
    int minExe = 0;
    int maxExe = 0;
    int priorityLevel = 0;
    int lengthOfSim = 0;
    int waitTime = 0;
    double numberOfProcessesPerCycle = 0.0;

    // take the input the user
    cout<<"Input the Number of CPU Cores: ";
    cin>>CPUCores;

    cout<<"Input the Minimum Number of Execution Cycles per Process: ";
    cin>>minExe;

    cout<<"Input the Maximum Number of Execution Cycles per Process: ";
    cin>>maxExe;

    cout<<"Input the Number of Priority Levels: ";
    cin>>priorityLevel;

    cout<<"Input the Number of New Processes per Cycle: ";
    cin>>numberOfProcessesPerCycle;

    cout<<"Input the Length of the Simulation in Cycles: ";
    cin>>lengthOfSim;

    cout<<endl;

    //

    runSimulation(CPUCores, minExe, maxExe, priorityLevel, numberOfProcessesPerCycle, lengthOfSim);
    

    return 0;

}

void runSimulation(int CPUCores, int minExe, int maxExe, int priorityLevel, double numberOfProcessesPerCycle, int lengthOfSim){
    long int idleTime = 0;
    long int numberExecuted = 0;
    long int TotalWaitTime = 0;
    long int ExecUnprocessed = 0;
    long int WaitUnprocessed = 0;
    int MaxWaitUnprocessed = 0;
    double newProcessAmount = 0.0;
    Process progExecution;
    PriorityQueue<Process> processQueue; // 
    vector<int> CPU(CPUCores, 0);

    // This loop runs for the length of the simulation
    for(int i = 0; i<lengthOfSim; i++){
        // this loop iterates through the cpu vector 
        for(int j = 0; j<CPUCores; j++){
            if(CPU[j]==0){ // if 0 we have to place a process on the core
                if(processQueue.isEmpty()){ // if the process queue is empty increment the idle time
                    idleTime++;
                }else{ // if there is processes add it.
                    progExecution = processQueue.dequeue();
                    CPU[j]=progExecution.getExeTime();
                    numberExecuted++;
                    TotalWaitTime += (i-progExecution.getTimeStamp());
                }
            }
            if(CPU[j]!=0){ // if there is a process execute a 1 execution time
                CPU[j]--;
            }  
        }
        newProcessAmount += numberOfProcessesPerCycle; // add the number of processes to the var to iterate to 1
        while(newProcessAmount >= 1){ // if the var is 1 or greater add a process 
            Process temp;
            temp.setExeTime((rand()%(maxExe-minExe))+minExe);
            temp.setTimeStamp(i);
            processQueue.enqueue(temp, ((rand()%priorityLevel)+1));
            newProcessAmount-=1;
        }
    }
    
    cout<<"============ Simulation Results ============"<<endl;
    cout<<"Idle Time = "<<idleTime<<endl;
    cout<<"Processes Completed = "<<numberExecuted<<endl;
    cout<<"Total Wait Time of Completed Processes = "<<TotalWaitTime<<endl;
    cout<<"Number Of Processes Remaining in the Queue = "<<processQueue.size()<<endl;
    if(processQueue.size() > 0){
        int firstPlace = 0;
        MaxWaitUnprocessed = lengthOfSim-processQueue[firstPlace].data.getTimeStamp();
        for(int i =0; i<processQueue.size(); i++){
            if((lengthOfSim-processQueue[i].data.getTimeStamp())>MaxWaitUnprocessed){
                MaxWaitUnprocessed = lengthOfSim-processQueue[i].data.getTimeStamp();
            }
            ExecUnprocessed += processQueue[i].data.getExeTime();
            WaitUnprocessed += processQueue[i].data.getTimeStamp();
        }
        cout<<"Total Execution Time Needed for Unprocessed Processes = "<<ExecUnprocessed<<endl;
        cout<<"Total Wait Time for Unprocessed Processes = "<<WaitUnprocessed<<endl;
        cout<<"Maximum Wait Time for Unprocessed Processes = "<<MaxWaitUnprocessed<<endl;
    }

    
}