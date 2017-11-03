#include<iostream>
#include "Sharma_cannibals.h"

/*
// This class holds the recursive TryAMove function that finds the solution 
// to the explorers and cannibals problem. 
//
// Deeksha Sharma 10/15/2017
*/

using namespace std;

/*
Pre-condition: target is a valid char array 
Post-condition: returns true if number of explorers is more than number of
cannibals in the array passed in, false otherwise. 
*/
bool Cannibals::ValidState(char target[])
{ 
	int numC = 0; //will keep track of the number of Cs. 
	int numE = 0; //will keep track of the number of Es.
	for (int i = 0; a[i]; i++)
	{ //this will loop through the array and keep track of the number of Es and Cs
		if (target[i] == 'E') numE++;
		else numC++;
	}
	if (numC > numE) return false;
	return true;
}

/*
Pre-condition: target is a valid char array 
Post-condition: returns the number of elements in the array 
*/
int Cannibals::SizeOfArray(char target[])
{
	int numElements = 0;
	for (int i = 0; target[i]; i++)
	{
		if (target[i] != NULL) numElements++;
	}
	return numElements;
}

/*
Pre-condition: target is a valid char array 
Post-condition: prints out all the elements in the array on one line 
*/
char Cannibals::PrintArray(char[] target)
{
	//prints the target array 
	for (int i = 0; target[i]; i++)
	{
		cout << target[i];
	}
	cout << endl;
}

/*
Pre-condition: assumed that target is a valid char vector, and targetArray is
a valid char array
Post-condition: returns true if the chars in the target vector passed 
in were found in targetArray and sucessfully removed. 
*/
bool Cannibals::Remove(vector<char> target, char[] targetArray)
{
	bool sucRemove = false; //bool to keep track of whether the remove was sucessful 
	if (target[1] != NULL) 
	{ //the following is executed if the target char vector passed in has 2 chars 
		for (int i = 0; i < SizeOfArray(targetArray); i++)
		{ //removes target in index 1 of vector if target is found in targetArray 
			if (targetArray[i] == target[1])
			{
				targetArray[i] = NULL;
				sucRemove = true;
			}
		}
	}
	for (int i = 0; i < SizeOfArray(a); i++)
	{ //removes target in index 0 of vector if target is found in targetArray 
		if (a[i] == target[0] && sucAdd)
		{
			a[i] = NULL;
			sucRemove = true;
		}
	}
	return sucRemove;
}

/*
Pre-condition: assumed that target is a valid char vector, and targetArray is 
a valid char array
Post-condition: returns true if the chars in the target vector passed in were
found in targetArray and sucessfully added.
*/
 bool Cannibals::Add(vector<char> target, char[] targetArray)
{
	 bool sucAdd = false; //bool to keep track of whether the addition was sucessful 
	 if (target[1] != NULL)
	 { //the following is executed if the target char vector passed in has 2 chars 
		 for (int i = 0; i < SizeOfArray(targetArray); i++)
		 { //adds target in index 1 of vector in first uninitialized index of targetArray
			 if (targetArray[i] == NULL)
			 {
				 targetArray[i] = target;
				 sucAdd = true;
			 }
		 }
	 }
	 for (int i = 0; i < SizeOfArray(targetArray); i++)
	 { //adds target in index 0 of vector in first uninitialized index of targetArray
		 if (targetArray[i] == NULL)
		 {
			 targetArray[i] = target[0];
			 sucAdd = true;
		 }
	 }
	 return sucAdd;
}

/*
Pre-condition: assumed that targetIndex is a valid, initialzied int
Post-condition: returns true if the char vector at targetIndex was able to 
be moved from the bank the boat was on to the other bank.
*/
bool Cannibals::MoveBoat(int targetIndex) //char[] from, char[] to) 
{
	// the following is executed if last char in leftBank array is L then the boat is on leftBank 
	if (leftBank[6] == 'L')
	{ 
		//following is executed if remove of targetIndex of possibleMoves vector from leftBank is sucessful 
		if (Remove(possibleMoves[targetIndex], leftBank))
		{ 
			leftBank[6] = 'R';
			return Add(possibleMoves[targetIndex], rightBank);
		}
	}
	else
	{
		//following is executed if remove of targetIndex of possibleMoves vector from rightBank is sucessful 
		if (Remove(possibleMoves[targetIndex], rightBank))
		{
			leftBank[6] = 'L';
			return Add(possibleMoves[targetIndex], leftBank); 
		}
	}
	return false;
}

/*
Pre-condition: assumed that targetIndex is a valid, initialzied int
Post-condition: returns true if a sucessful solution was found and false otherwise 
*/
bool Cannibals::TryAMove(int targetIndex) 
{
	//following is executed if the move of targetIndex is sucessful 
	if (MoveBoat(targetIndex))
	{
		//base case
		if (SizeOfArray(rightBank) == 6) 
		{
			return true;
		}

		// if both banks are at a valid state the for loop will try all possible moves using recursive calls 
		if (ValidState(leftBank) && ValidState(rightBank))
		{
			for (int i = 0; i < possibleMoves.size(); ++i)
			{ 
				if (possibleMoves[i] == target) continue;
				if (TryAMove(possibleMoves[i]))
				{
					return Add(TryAMove(possibleMoves[i]), solutionArray); //???
				}
			}
		}
		//IS THIS ALL THAT WILL RESET THE ARRAY 
		TryAMove(target) //if at an invalid state this reset arrays to previous valid state
		//Remove(TryAMove(possibleMoves[i], solutionArray)); //WOULD SOLUTIONARRAY NEED TO BE RESET
	}
	//if either bank is not at a valid state
	return false;
}

