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
private:

	//last char is L if boat is on left bank and is R if boat is on right bank
	std::vector<char> leftBank = {'E', 'E', 'E', 'C', 'C', 'C', 'L'};
	const std::vector<std::vector<char>> possibleMoves;
	const std::vector<char> failState;
	const std:: vector<char> baseCase;

public:

	// creating constructor which will provide the definition of the possibleMoves public class member
	Cannibals();

	bool AddRemove(const std::vector<char> &nextMove, std::vector<char> &stateArray, const bool &goRight);
	bool ValidState(const std::vector<char>&); //checks if banks are at a valid state
	bool ValidState(const std::vector<char>&, const std::vector<char>& );
	bool MoveBoat(const int &targetIndex, std::vector<char> &stateArray); //moves people between banks //WHAT IS THE ERROR EXPECTED UNQUALIFIED_ID BEFORE '[' TOKEN
	std::vector<std::vector<char>> TryAMove(int &targetIndex, std::vector<char> myCurState); //the recursisve method
	std::string PrintArray(const std::vector<char> &target)const; //prints the array //WHAT IS THE ERROR EXPECTED UNQUALIFIED_ID BEFORE '[' TOKEN
};

