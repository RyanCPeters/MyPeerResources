#pragma once
/*
// Complex numbers: are represented as X+Yi where x and Y are real numbers.
// X is referred to as the real part and Y as the imaginary part of the
// complex number. For example complex(5.6,7.2) means
// 5.6+7.2i.
//
// Implementation and assumptions:
//   -- Complex are stored as real integers X and Y.
//   -- i^2 = -1
//   -- Dividing by zero produces a printed error message and returns 0.
//
// Deeksha Sharma 10/10/2017
*/


#include <vector>
#include <string> 

class Cannibals
{
public:
	//last char is L if boat is on left bank and is R if boat is on right bank
	char leftBank[] = {'E', 'E', 'E', 'C', 'C', 'C', 'L'}; 
	char rightBank[6] = {0};
	//possibleMoves is a vector of vectors of chars that holds all possible combination of moves 
	std::vector<std::vector<char>> possibleMoves = {{'E', NULL},{ 'C',NULL },{ 'E','E' },{ 'C','C' },{ 'E','C' }};
	//this will hold all the moves that lead to the solution
	char solutionArray[40] = {0}; //DOES THIS INITIALIZE THE ARRAY TO NULL??

	bool ValidState(char[]); //checks if banks are at a valid state
	bool MoveBoat(char[]); //moves people between banks //WHAT IS THE ERROR EXPECTED UNQUALIFIED_ID BEFORE '[' TOKEN
	bool TryAMove(char[]); //the recursisve method 
	int SizeOfArray(char[]); //gets size of array 
	string PrintArray(char[]); //prints the array //WHAT IS THE ERROR EXPECTED UNQUALIFIED_ID BEFORE '[' TOKEN
};

