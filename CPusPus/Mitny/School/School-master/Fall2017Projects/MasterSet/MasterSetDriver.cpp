//----------------------------------------------------------------------------
//  Title: MasterSetDriver
//			
//  File: C:\Users\mitchell.nye\Documents\Visual Studio 2017\Projects
//		    \MasterSetDriver\MasterSetDriver.cpp
//
//	Description: This Class tests the MasterSet Class.
//
//  Programmer: Mitchell Nye
// 
//  Date: 11/5/2017
//
//  Version: 1.0
//
//	Environment: MS Windows 10
//  
//  Hardware: Intel I7-6600U CPU
//
//  Software: Visual Studio Community 2017
//
//	History Log: 11/5/2017	MN completed version 1.0
//
//----------------------------------------------------------------------------


//#include "DoubleList.h"
#include "MasterSet.h"
#include "Autobot.h"
#include <stddef.h>

#include <iostream>
#include <sstream>
#include <string>
#include <iterator>

using namespace std;

int main()
{
	//Item initialization for list
	Autobot bob1 = Autobot("Bob1", 1, 1, 1);
	Autobot bob2 = Autobot("Bob2", 2, 2, 2);
	Autobot bob3 = Autobot("Bob3", 3, 3, 3);
	Autobot bob4 = Autobot("Bob4", 4, 4, 4);
	Autobot bob5 = Autobot("Bob5", 5, 5, 5);

	Autobot bob6 = Autobot("Bob6", 6, 6, 6);
	Autobot bob7 = Autobot("Bob7", 7, 7, 7);
	Autobot bob8 = Autobot("Bob8", 8, 8, 8);
	Autobot bob9 = Autobot("Bob9", 9, 9, 9);
	Autobot bob10 = Autobot("Bob10", 10, 10, 10);

	Autobot bob11 = Autobot("Bob11", 11, 11, 11);
	
	//Linked List Stores Pointers to Objects
	Autobot * b1 = &bob1;
	Autobot * b2 = &bob2;
	Autobot * b3 = &bob3;
	Autobot * b4 = &bob4;
	Autobot * b5 = &bob5;

	Autobot * b6 = &bob6;
	Autobot * b7 = &bob7;
	Autobot * b8 = &bob8;
	Autobot * b9 = &bob9;
	Autobot * b10 = &bob10;

	Autobot * b11 = &bob11;

	//Create Double List
	DoubleList<Autobot> autoList = DoubleList<Autobot>();

	//Insert Items into Linked List
	autoList.insert(b1);
	autoList.insert(b10);
	autoList.insert(b11);
	autoList.insert(b9);
	autoList.insert(b7);

	autoList.insert(b8);
	autoList.insert(b2);
	autoList.insert(b3);
	autoList.insert(b5);
	autoList.insert(b4);

	autoList.insert(b6);
	autoList.insert(b6);
	autoList.insert(b6);


	std::cout<< "Here is my unsorted linked list of Autobots:" << std::endl;
	autoList.print();

	std::cout<< "\nHere is my sorted linked list of Autobots:" << std::endl;
	autoList.sort();
	autoList.print();

	std::cout<< "\nHere is my list after removing two of the duplicates:" << std::endl;
	autoList.deleteNode(b6);
	autoList.deleteNode(b6);
	autoList.print();

	std::cout<< "\nHere is an autobot that I searched for (bob9):" << std::endl;
	autoList.get(b9);


	//Here is where I test my set implementation
	string string1 = "this";
	string string2 = "is";
	string string3 = "a";
	string string4 = "test";
	string string5 = "of";

	string string6 = "my";
	string string7 = "masterSet";
	string string8 = "implementation";
	string string9 = "mitchell";
	string string10 = "nye";

	string string11 = "boop";

	//Set stores pointers to objects
	string * s1 = &string1;
	string * s2 = &string2;
	string * s3 = &string3;
	string * s4 = &string4;
	string * s5 = &string5;

	string * s6 = &string6;
	string * s7 = &string7;
	string * s8 = &string8;
	string * s9 = &string9;
	string * s10 = &string10;

	string * s11 = &string11;


	//Create Set
	MasterSet<string> setTest = MasterSet<string>();

	//Insert items into set
	setTest.insertSet(s1);
	setTest.insertSet(s2);
	setTest.insertSet(s10);
	setTest.insertSet(s11);
	setTest.insertSet(s8);

	setTest.insertSet(s7);
	setTest.insertSet(s6);
	setTest.insertSet(s5);
	setTest.insertSet(s4);
	setTest.insertSet(s3);

	setTest.insertSet(s7);
	setTest.insertSet(s6);
	setTest.insertSet(s5);
	setTest.insertSet(s4);
	setTest.insertSet(s3);

	setTest.insertSet(s9);
	setTest.insertSet(s9);
	setTest.insertSet(s9);
	setTest.insertSet(s9);
	setTest.insertSet(s9);

	setTest.insertSet(s5);
	setTest.insertSet(s4);
	setTest.insertSet(s3);
	setTest.insertSet(s10);
	setTest.insertSet(s10);

	setTest.insertSet(s10);
	setTest.insertSet(s10);
	setTest.insertSet(s10);
	setTest.insertSet(s10);
	setTest.insertSet(s10);

	std::cout << "\nTesting the set, it should automatically sort and print the keys." << std::endl;
	std::cout << "I have already added many duplicates. there should be 5 mitchells" << std::endl;
	setTest.printWithKeys();

	std::cout << "\nTesting the different sorting of the set by count:" << std::endl;
	setTest.sortSet();
	setTest.printWithKeys();

	std::cout << "\nTesting the functionality of getting top 3 counts:" << std::endl;
	setTest.getTopThree();

	cin.get();
	cin.get();
	return 0;
}