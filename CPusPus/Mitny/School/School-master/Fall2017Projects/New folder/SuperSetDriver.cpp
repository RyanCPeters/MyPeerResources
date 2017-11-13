#include "DoubleList.h"
#include <iostream>
#include "SuperSet.h"

#include "Autobot.h"

using namespace std;

int main()
{
	Autobot * autoPtr = nullptr;
	Autobot * autoPtr2 = nullptr;
	Autobot * autoPtr3 = nullptr;

	Autobot bob = Autobot("Bob", 10, 10, 10);
	Autobot kristel = Autobot("Kristel", 70, 70, 70);
	Autobot darren = Autobot("Darren", 60, 60, 60);
	autoPtr = &bob;
	autoPtr2 = &kristel;
	autoPtr3 = &darren;

	DoubleList<Autobot> myList = DoubleList<Autobot>();

	//myList.insert(autoPtr);
	//myList.insert(autoPtr);
	//myList.insert(autoPtr2);
	//myList.insert(autoPtr3);
	//myList.print();
	//myList.sort();
	//myList.print();
	//myList.get(autoPtr);
	//
	//myList.deleteNode(autoPtr);
	//myList.deleteNode(autoPtr);
	//myList.deleteNode(autoPtr);
	//myList.get(autoPtr);
	//myList.print();




	int * intPtr1 = nullptr;
	int * intPtr2 = nullptr;
	int * intPtr3 = nullptr;

	int first = 5;
	int second = 10;
	int third = 8;

	intPtr1 = &first;
	intPtr2 = &second;
	intPtr3 = &third;

	DoubleList<int> intList = DoubleList<int>();
	intList.insert(intPtr1);
	intList.insert(intPtr2);
	intList.insert(intPtr3);
	intList.print();
	intList.sort();
	intList.print();

	intList.get(intPtr1);
	intList.deleteNode(intPtr1);
	intList.deleteNode(intPtr1);

	SuperSet<int> superTester = SuperSet<int>();
	superTester.insert(intPtr1);
	superTester.print();


	cin.get();
	cin.get();
	return 0;
}