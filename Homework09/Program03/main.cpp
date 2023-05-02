/*
Author: Cole Barbes
Creation Date: 04/21/23
Last Update: 04/21/23
Description: This file defines a recursive function to find all solutions to the 8 queens problem for a index
User Interface: simple main function to get the starting index
*/
#include <iostream> 
#include <vector>

using namespace std;

bool safeLocation(int row, int col, const vector<int> &queenList); // prototype for the safeLocation checker

void saveSolution(vector<vector<int>>& saveVector, vector<int>& solVector); // prototype for the save solution function

bool placeQueens(vector<vector<int>>& saveVector, vector<int> &queenList, int col); // prototype for the place queen recursive function


int main() {
	int row;

	vector<int> queenList(8); // create a vector to use as the solution vector
	vector<vector<int>> saveVector; //vector that holds the successful solutions

	bool checker; // var to hold the output of placequeens

	// take the input
	cout << "Enter row for queen in column 0: ";
	cin >> row;
	while(row<0 || row>7){
		cout<<"Sorry but the chess board is not "<<row<<" x "<<row<<endl;
		cout<<"Enter a valid row for the queen in column 0: ";
		cin>>row;
	}
	cout << endl;
	
	queenList[0] = row; // set the first pick

	checker = placeQueens(saveVector, queenList, 1); // call the recursive function

	// print the solution vector
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
bool placeQueens(vector<vector<int>>& saveVector, vector<int> &queenList, int col) {
	int row;
	bool foundLocation;

	if (col == 8){	// stopping condition
		foundLocation = true;
		saveSolution(saveVector, queenList);
	}
	else {
		foundLocation = false;
		row = 0;

		while (row < 8){
			if (safeLocation(row, col, queenList)) {
				queenList[col] = row;
				foundLocation = placeQueens(saveVector, queenList, col+ 1);
			}
			row++;
		}

	}

	// pass success or failure back to previous col
	return foundLocation;
}