//----------------------------------------------------------------------------
//  Title: AutobotDriver
//			
//  File: C:\Users\mitchell.nye\Documents\Visual Studio 2017\Projects
//		    \Autobot\AutobotDriver.cpp
//
//	Description: This is a driver class to test the various functions of the
//				 Autobot class.
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
//	History Log: 10/08/2017	MN completed version 1.0
//
//----------------------------------------------------------------------------

#include <iostream>
#include "Autobot.h"

using namespace std;

int main() 
{
	//Demonstrating Autobot Creation, Invariants, and talk method:
	Autobot ironHide = Autobot("IronHide", 20000000, -5, 200);
	cout << "I have created an Autobot named IronHide. I entered data"
		" that is out of bounds for his stats.\nThe class takes the "
		"data and manipulates it, so that it fits in the bounds.\n"
		"The talk method will display these stats:\n" << endl;

	ostream & os = cout;
	ironHide.talk(os);

	Autobot bumbleBee = Autobot("BumbleBee");
	cout << "I have created a generic Autobot named BumbleBee. "
		"The talk method will display his stats:\n" << endl;
	bumbleBee.talk(os);

	Autobot genericAutobot = Autobot();
	cout << "I have created a generic Autobot without a name. "
		"The talk method will display its stats:\n" << endl;
	genericAutobot.talk(os);

	//Demonstrating the use of the +, << operands and selfDestruct method
	cout << "Now I will add two autobots together using the + "
		"operator. I will use the talk method to display the new stats.\n" 
		<< endl;
	(genericAutobot + bumbleBee).talk(os);

	cout << "Now IronHide will self destruct and try to talk.\n" << endl;
	ironHide.selfDestruct();
	ironHide.talk(os);

	cout << "He can't talk because he is dead, so we can use the << "
		"operand to display his stats:\n" << endl;
	cout << ironHide;

	cout << "If we try to add IronHide to another autobot, it won't work:" << endl;
	ironHide + bumbleBee;
	bumbleBee + ironHide;

	//Demonstrating the += operand
	cout << "\nHere I demonstrate the += operand. The second autobot gets"
		" added to the first:" << endl;
	bumbleBee += genericAutobot;
	cout << bumbleBee;

	cout << "It won't add if either one is not alive:" << endl;
	bumbleBee += ironHide;
	ironHide += bumbleBee;
	cout << endl << bumbleBee << ironHide;

	//Demonstrating the == and != operands
	cout << "Now I will create 2 BumbleBee objects and use the == \n"
		"and != operands to compare them. BumbleBee should be different\n"
		"than the other two." << endl;
	Autobot bumbleBee2 = Autobot("BumbleBee");
	Autobot bumbleBee3 = Autobot("BumbleBee");
	
	if (bumbleBee == bumbleBee2)
		cout << "BumbleBee == BumbleBee2" << endl;
	if (bumbleBee2 == bumbleBee3)
		cout << "BumbleBee2 == BumbleBee3" << endl;

	if (bumbleBee != bumbleBee2)
		cout << "BumbleBee != bumbleBee2" << endl;
	if (bumbleBee2 != bumbleBee3)
		cout << "Bumblebee2 != bumbleBee3" << endl;

	cout << "\nBumbleBee:\n" << bumbleBee;
	cout << "BumbleBee2:\n" << bumbleBee2;
	cout << "BumbleBee3:\n" << bumbleBee3;

	//Demonstrating the attack method
	cout << "Lastly, there is an attack method. Whichever robot has a <= \n"
		"power level will die, and the kill count of whoever is left standing \n"
		"increments by 1. Bumblebee will attack Bumblebee2" << endl;
	bumbleBee.attack(bumbleBee2);
	bumbleBee.talk(os);

	cout << "Because I only used pointers in the parameters of my methods, \n"
		"I do not need to add anything to the object destructor. Their memory\n"
		"has already been cleared, and the destructor gets called implicitly\n"
		"on the program's termination." << endl;

	cin.get();
	cin.get();
	return 0;
}