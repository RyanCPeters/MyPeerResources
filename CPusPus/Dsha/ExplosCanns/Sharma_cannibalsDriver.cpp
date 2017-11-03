#include <iostream>
#include "Sharma_cannibals.h"

/*
// This class has the driver function for the Cannibals class specified in the 
// Sharma_cannibals.h file. It creates an instance of the Cannibals class, 
// invokes the TryAMove recursive function and then prints out the resulting
// solution.
// 
// Deeksha Sharma 10/15/2017
*/

using namespace std;

int main()
{
	//calls the constructor to create the possible moves array 
	Cannibals cannibalInstance;

	//this loop calls the recursive function and tries all possible moves 
	for (int i = 0; i < cannibalInstance.possibleMoves.size(); ++i)
	{
		cannibalInstance.TryAMove(cannibalInstance.possibleMoves[i]);
	}

	//this prints out the contents of the rightBank array after the recursive call
	PrintArray(cannibalInstance.solutionArray);
}
