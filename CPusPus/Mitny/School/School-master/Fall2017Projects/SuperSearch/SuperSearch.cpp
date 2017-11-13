//----------------------------------------------------------------------------
//  Title: SuperSearch
//			
//  File: C:\Users\mitchell.nye\Documents\Visual Studio 2017\Projects
//		    \SuperSearch\SuperSearch.cpp
//
//	Description: This cpp file implements a template function, and a normal
//				 function. These functions take in a vector and a number
//				 to search for. They proceed to search the vector for
//				 the three closest elements to that number and print them
//				 out to the console. The reason why there are two search
//				 functions is because I could not figure out how to use
//				 templates to store objects as well as search for the
//				 properties of those stored objects. I started out by
//				 making my template function with primitive types, and
//				 could not convert it. Then I created a normal search
//				 function for my Autobot class, in hopes of combining
//				 my template search with my autobot search. However,
//				 I came along struggles and was unable to properly
//				 rank my search results, and furthermore was unable to
//				 combine my functions. Fortunately, I was able to complete
//				 some of the program requirements like big O analysis.
//
//				 The Autobot part of my code was working, and I took screencaps
//				 of this before I commented out that part of my code. It wasn't
//				 compiling with linux, so it is commented out in order for my
//				 code to compile.
//
//
//  Programmer: Mitchell Nye
// 
//  Date: 10/8/2017
//
//  Version: 1.0
//
//	Environment: MS Windows 10
//  
//  Hardware: Intel I7-6600U CPU
//
//  Software: Visual Studio Community 2017
//
//	History Log: 10/22/2017	MN completed version 1.0
//
//----------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include "Autobot.h"

using namespace std;

template <class T>
void getClosest(vector<T> vect, T numToLookFor) // Big O: O*n + 12
{
	sort(vect.begin(), vect.end());
	T firstClosest = -90000; //NULL was giving me errors
	T secondClosest = -90000;
	T thirdClosest = -90000;
	T temp = -90000;

	if (vect.size() <= 0) 
	{
		cout << "There is nothing in the Vector!";
	} 
	else if (vect.size() == 1) 
	{
		firstClosest = vect[0];
	}
	else if (vect.size() == 2) 
	{
		if (abs(numToLookFor - vect[0]) <= abs(numToLookFor - vect[1])) 
		{
			firstClosest = vect[0];
			secondClosest = vect[1];
		}
		else if (abs(numToLookFor - vect[0]) > abs(numToLookFor - vect[1])) 
		{
			firstClosest = vect[1];
			secondClosest = vect[0];
		}
	}
	else  //find the first, second and third closest in the first 3 numbers of the vector
	{
		firstClosest = vect[0];

		if ((abs(numToLookFor - vect[0]) >= abs(numToLookFor - vect[1]) ))
		{
			firstClosest = vect[0]; 
			secondClosest = vect[1];
			thirdClosest = vect[2];
		}
		else {
			firstClosest = vect[1];
			secondClosest = vect[0];

			//check if the first is closer, or if the third is closer
			if (abs(numToLookFor - vect[2]) < (numToLookFor - vect[0]) && (abs(numToLookFor - vect[2]) < abs(numToLookFor - vect[1]))) {
				firstClosest = vect[2];
				secondClosest = vect[1];
				thirdClosest = vect[0];
			}
			else
			{
				thirdClosest = vect[2];
			}
		}

		for (int i = 2; i < int(vect.size()) - 1; i++) { //O(n) + 4
			if (abs(numToLookFor - vect[i]) <= abs(numToLookFor - firstClosest)) {
				temp = firstClosest;
				firstClosest = vect[i];
				thirdClosest = secondClosest;
				secondClosest = temp;
			}
			else if (abs(numToLookFor - vect[i]) <= abs(numToLookFor - secondClosest)) {
				thirdClosest = secondClosest;
				secondClosest = vect[i];
			}
			else if (abs(numToLookFor - vect[i]) < abs(numToLookFor - thirdClosest)) {
				thirdClosest = vect[i];
			}
		}
	}

	if (firstClosest == numToLookFor) {
		cout << "Exact Match! " << firstClosest << endl;
	}
	else
	{
		cout << "Could not find an exact match. Try searching for one of the following next time: " << endl;
		if (firstClosest != -90000)
			cout << "Additional Suggestion 1: " << firstClosest << endl;
		if (firstClosest != -90000)
			cout << "Additional Suggestion 2: " << secondClosest << endl;
		if (firstClosest != -90000)
			cout << "Additional Suggestion 3: " << thirdClosest << endl;
	}
}

//Autobot * getClosest(vector<Autobot> vect, int numToLookFor) //same big O as the function above.
//{
//	Autobot *firstClosest = NULL;
//	Autobot *secondClosest = NULL;
//	Autobot *thirdClosest = NULL;
//	Autobot *temp = NULL;
//
//	if (vect.size() <= 0)
//	{
//		cout << "There is nothing in the Vector!";
//	}
//	else if (vect.size() == 1)
//	{
//		firstClosest = &vect[0];
//	}
//	else if (vect.size() == 2)
//	{
//		if (abs(numToLookFor - vect[0].getPowerLevel()) <= abs(numToLookFor - vect[1].getPowerLevel()))
//		{
//			firstClosest = &vect[0];
//			secondClosest = &vect[1];
//		}
//		else if (abs(numToLookFor - vect[0].getPowerLevel()) > abs(numToLookFor - vect[1].getPowerLevel()))
//		{
//			firstClosest = &vect[1];
//			secondClosest = &vect[0];
//		}
//	}
//	else
//	{
//		firstClosest = &vect[0];
//		for (unsigned int i = 0; i < vect.size() - 1; i++) {
//			if (abs(numToLookFor - vect[i].getPowerLevel()) <= abs(numToLookFor - firstClosest->getPowerLevel())) {
//				if (i != 0) {
//					temp = firstClosest;
//					firstClosest = &vect[i];
//					thirdClosest = secondClosest;
//					secondClosest = temp;
//				}
//			}
//			else if (abs(numToLookFor - vect[i].getPowerLevel()) <= abs(numToLookFor - secondClosest->getPowerLevel())) {
//				thirdClosest = secondClosest;
//				secondClosest = &vect[i];
//			}
//			else if (abs(numToLookFor - vect[i].getPowerLevel()) < abs(numToLookFor - thirdClosest->getPowerLevel())) {
//				thirdClosest = &vect[i];
//			}
//		}
//	}
//
//	if (firstClosest->getPowerLevel() == numToLookFor) {
//		cout << "Exact Match! " << &firstClosest << endl;
//	}
//	else
//	{
//		cout << "\nCould not find an exact match. Try searching for one of the following next time: " << endl;
//		if (firstClosest != NULL)
//			cout << "Additional Suggestion 1: " << *firstClosest << endl;
//		if (secondClosest != NULL)
//			cout << "Additional Suggestion 2: " << *secondClosest << endl;
//		if (thirdClosest != NULL) 
//			cout << "Additional Suggestion 3: " << *thirdClosest << endl;
//	}
//	return firstClosest;
//}


int main() {

	cout << "Here are the tests on my int vector:\n" << endl;

	vector<int> myVector;
	myVector.push_back(10);
	myVector.push_back(20);
	myVector.push_back(30);
	myVector.push_back(40);
	myVector.push_back(50);

	myVector.push_back(60);
	myVector.push_back(70);
	myVector.push_back(80);
	myVector.push_back(90);
	myVector.push_back(100);

	cout << "\nSearched 96, not an exact match." << endl;
	getClosest<int>(myVector, 96);

	cout << "\nSearched 90, an exact match." << endl;
	getClosest<int>(myVector, 90);

	cout << "\nAdded 70, searched for 56." << endl;
	myVector.push_back(76);
	getClosest<int>(myVector, 56);

	cout << "\nRemoved 6 elements off of the back including the 70's, searched for 22." << endl;
	myVector.pop_back();
	myVector.pop_back();
	myVector.pop_back();
	myVector.pop_back();
	myVector.pop_back();
	myVector.pop_back();
	getClosest<int>(myVector, 22);

	//cout << "\nHere are the tests on my Autobot vector:" << endl;

	//Autobot bob = Autobot("Bob", 10, 10, 10);
	//Autobot kristel = Autobot("Kristel", 20, 20, 20);
	//Autobot theresa = Autobot("Theresa", 30, 30, 30);
	//Autobot mitchell = Autobot("Mitchell", 40, 40, 40);
	//Autobot troy = Autobot("Troy", 50, 50, 50);

	//Autobot andrew = Autobot("Andrew", 60, 60, 60);
	//Autobot tory = Autobot("Tory", 70, 70, 70);
	//Autobot jeff = Autobot("Jeff", 80, 80, 80);
	//Autobot matt = Autobot("Matt", 90, 90, 90);
	//Autobot scot = Autobot("Scot", 100, 100, 100);

	//vector<Autobot> AutobotVector;
	//AutobotVector.push_back(bob);
	//AutobotVector.push_back(kristel);
	//AutobotVector.push_back(troy);
	//AutobotVector.push_back(theresa);
	//AutobotVector.push_back(andrew);

	//AutobotVector.push_back(mitchell);
	//AutobotVector.push_back(tory);
	//AutobotVector.push_back(jeff);
	//AutobotVector.push_back(matt);
	//AutobotVector.push_back(scot);

	//cout << "\nSearched 55, not an exact match." << endl;
	//getClosest(AutobotVector, 55);

	//cout << "\nSearched 30, an exact match." << endl;
	//getClosest(AutobotVector, 30);

	//cout << "\nAdded tory, searched for 56." << endl;
	//AutobotVector.push_back(tory);
	//getClosest(AutobotVector, 56);

	//cout << "\nRemoved 5 elements off of the back, searched for 33." << endl;
	//AutobotVector.pop_back();
	//AutobotVector.pop_back();
	//AutobotVector.pop_back();
	//AutobotVector.pop_back();
	//AutobotVector.pop_back();
	//getClosest(AutobotVector, 33);

	cin.get();
	cin.get();
	return 0;
}