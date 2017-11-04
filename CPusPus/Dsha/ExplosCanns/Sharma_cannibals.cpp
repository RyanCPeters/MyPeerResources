#include<iostream>
#include <sstream>
#include "Sharma_cannibals.h"

/*
// This class holds the recursive TryAMove function that finds the solution 
// to the explorers and cannibals problem. 
//
// Deeksha Sharma 10/15/2017
*/



using namespace std;
// note that in the possibleMoves vector that the '.' char denotes an empty seat in the boat for that crossing.
Cannibals::Cannibals():possibleMoves({{'E', '.'},{ 'C','.'},{ 'E','E' },{ 'C','C' },{ 'E','C' }}),
					   failState({NULL,NULL,NULL}),
					   baseCase({'-','-','-','-','-','-','R'})
{
	//this loop calls the recursive function and tries all possible moves
	vector<vector<char>> solutionArray;
	for (int i = 0; i < possibleMoves.size(); ++i){
		solutionArray.clear();
		solutionArray = TryAMove(i, leftBank);
		if(solutionArray.back() == baseCase) break;
	}
	cout << "solutionArray.size() = " << solutionArray.size() << endl;
	//this prints out the contents of the rightBank array after the recursive call
	for(const vector<char> &vec : solutionArray)cout << PrintArray(vec) << endl;

}

/*
 * This function handles the boolean checking to ensure that a given state for the left bank
 * is in compliance with the assignment specifications.
 *
Pre-condition: target is a valid char array
Post-condition: returns true if number of explorers is more than number of
cannibals in the array passed in, false otherwise.
*/
bool Cannibals::ValidState(const vector<char> &target)
{
	int numC = 0; //will keep track of the number of Cs. 
	int numE = 0; //will keep track of the number of Es.
	for (int i = 0; i < target.size(); i++)
	{ //this will loop through the array and keep track of the number of Es and Cs
		if (target[i] == 'E') numE++;
		else if(target[i] == 'C')numC++;
	}
	// if all the explorers are on the right bank, then we only need check if Explorers >= 0 && (cannibals >=0 && cannibals <4)
	return numE >= 0 && numC >=0 && numE < 4 && numC < 4 && (numE <1 || numE >= numC) && target != leftBank;
}

bool Cannibals::ValidState(const vector<char> &curState, const vector<char> &nextState)
{
	int currC = 0, nextC = 0; //will keep track of the number of Cs.
	int currE = 0, nextE = 0; //will keep track of the number of Es.
	for (int i = 0; i < curState.size(); i++)
	{ //this will loop through the array and keep track of the number of Es and Cs
		if (curState[i] == 'E') ++currE;
		else if(curState[i] == 'C')++currC;

		if(nextState[i] == 'E')++nextE;
		else if(nextState[i] == 'C')++nextC;
	}
	// if all the explorers are on the right bank, then we only need check if Explorers >= 0 && (cannibals >=0 && cannibals <4)
	return ValidState(curState) && ValidState(nextState) && nextState != curState;
}

/*
Pre-condition: assumed that target is a valid char vector, and targetArray is
a valid char array
Post-condition: returns true if the chars in the target vector passed 
in were found in targetArray and sucessfully removed. 
*/
bool Cannibals::AddRemove(const vector<char> &nextMove, vector<char> &stateArray, const bool &goRight)
{
	bool actionPerformed[2] = {false,false}; // bool to keep track of whether the remove was sucessful
	actionPerformed[1] = nextMove[1] == '.'; // if there's an empty seat in the boat, then the second action is already done!
	vector<char> testDummy;
	for(const char &c : stateArray) testDummy.push_back(c);
	for(const char &ch : nextMove){
		for(int idxInState = 0; idxInState < testDummy.size() && !(actionPerformed[0] && actionPerformed[1]); ++idxInState){
			// actionPerformed[0] is false until we get the first character match in the following if statement
			if( (goRight && stateArray[idxInState] == ch) || (!goRight && stateArray[idxInState] == '-') ){
				if(!actionPerformed[0] || !actionPerformed[1]){
					// actionPerformed[1] won't get updated unless we've already had one character match above to set
					// actionPerformed[0] = true
					if(actionPerformed[0]) actionPerformed[1] = true;
					actionPerformed[0] = true;
					testDummy[idxInState] = (goRight)? '-': ch;
				}
			}
		}
	}
	stateArray = ValidState(testDummy)? testDummy : stateArray;
	return actionPerformed[0] && actionPerformed[1] && ValidState(testDummy);
}

/*
Pre-condition: assumed that targetIndex is a valid, initialzied int
Post-condition: returns true if the char vector at targetIndex was able to 
be moved from the bank the boat was on to the other bank.
*/
bool Cannibals::MoveBoat(const int &targetIndex, vector<char> &stateArray) //char[] from, char[] to)
{
	return AddRemove(possibleMoves[targetIndex], stateArray, stateArray[6] == 'L');
}

/*
Pre-condition: assumed that targetIndex is a valid, initialzied int
Post-condition: returns true if a sucessful solution was found and false otherwise 
*/
std::vector<std::vector<char>> Cannibals::TryAMove(int &targetIndex, const vector<char> myCurState)
{
	cout << PrintArray(myCurState) << "current state\n";
	if(!ValidState(myCurState))return {failState};
	vector<vector<char>> ret;
	ret.push_back(myCurState);
	if(ret.back() == baseCase)return ret;
	vector<char> myNextState = myCurState;
	bool movingBoat = MoveBoat(targetIndex, myNextState);
	cout << PrintArray(myNextState) << "next state\n";
	if (ValidState(myNextState) && movingBoat)
	{
		myNextState[6] = (myNextState.back() == 'L')?'R':'L';
		ret.push_back(myNextState);
		if(myNextState == baseCase) return ret;
		vector<vector<char>> goDeep;
		for (int i = 0; i < possibleMoves.size(); ++i)
		{
			goDeep.clear();
			goDeep = TryAMove(i,myNextState);
			if(goDeep.back() == baseCase)break;
		}
		ret.assign(goDeep.begin(),goDeep.end());

	}
	return ret;
}

/*
Pre-condition: target is a valid char array
Post-condition: prints out all the elements in the array on one line
*/
string Cannibals::PrintArray(const vector<char> &target)const
{
	stringstream ret;
	int explorers = 0, cannibals = 0,boat = 0;

	// in this for loop we get the head count for explorers and cannibals while also building the left bank portrayal ret
	for(const char &c : target){
		if(c == 'E'){
			++explorers;
			ret << 'E';
		} else if(c == 'C'){
			++cannibals;
			ret << 'C';
		} else if(c == 'L'){
			++boat;
		}else{
			ret << '-';
		}
	}
	ret << " ";
	string s = (boat == 1)?"\\../____":"____\\../";
	ret << " ";
	for(int exp = 0; exp < 3-explorers; ++exp){
		ret << 'E';
	}
	for(int cann = 0; cann < 3-cannibals; ++cann){
		ret << 'C';
	}
	for(int dirt = 0; dirt < 6 - (cannibals + explorers); ++dirt){
		ret << '-';
	}
	return ret.str();
}