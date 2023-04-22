/*
Author: Cole Barbes
Creation Date: 04/21/23
Last Update: 04/21/23
Description: This file defines a recursive function to find all solutions to the n queens problem for each starting index
User Interface: simple main function to get the starting index
*/
#include <iostream> 
#include <vector>

using namespace std;

bool safeLocation(int row, int col, const vector<int> &queenList); // prototype for the safeLocation checker

void saveSolution(vector<vector<int>>& saveVector, vector<int>& solVector); // prototype for the save solution function

bool placeQueens(vector<vector<int>>& saveVector, vector<int> &queenList, int col, int n); // prototype for the place queen recursive function


int main() {
    int n; // store the n value 
	
	bool checker; // checker val

	// take the input
    cout<<"Enter the board size n X n. n = ";
    cin>>n;
	cout << endl;

    vector<int> queenList(n); // the computation vector
	vector<vector<int>> saveVector; // solution vector
	
	// for loop to get each computation for starting value
    for(int i = 0; i<n; i++){
        queenList[0] = i;
        checker = placeQueens(saveVector, queenList, 1, n);
    }
	
	// for loop to print the vector
	for(unsigned int i = 0; i<saveVector.size(); i++){
		for(unsigned int j = 0; j<saveVector[i].size(); j++)
			cout<<saveVector[i][j]<<" ";
		cout<<endl;
	}
	cout<<"There are "<<saveVector.size()<<" solutions"<<endl; // print the number of solutions
	
	

	return 0;
}

// check if the solution is valid
bool safeLocation(int row, int col, const vector<int> &queenList) {
	for (int qCol = 0; qCol < col; qCol++) {
		int qRow = queenList[qCol];
		if (qRow == row)
			return false;
		else if (qCol == col)
			return false;
		else if (qCol - qRow == col - row || qCol + qRow == col + row)
			return false;
	}
	return true;
}

// simple function to save each solution
void saveSolution(vector<vector<int>>& saveVector, vector<int>& solVector){
	saveVector.push_back(solVector);
}

// Place a queen in columns col through 7
bool placeQueens(vector<vector<int>>& saveVector, vector<int> &queenList, int col, int n) {
	int row;
	bool foundLocation;

	if (col == n){	// stopping condition
		foundLocation = true;
		saveSolution(saveVector, queenList);
	}
	else {
		foundLocation = false;
		row = 0;

		while (row < n){
			if (safeLocation(row, col, queenList)) {
				queenList[col] = row;
				foundLocation = placeQueens(saveVector, queenList, col+ 1, n);
			}
			
			row++;
		}

	}

	// pass success or failure back to previous col
	return foundLocation;
}