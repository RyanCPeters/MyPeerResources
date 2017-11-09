#include <iostream>
#include "stdio.h"
#include "Autobot.h"
#include "List.h"

using namespace std;

int main() {
	Autobot bob = Autobot("Bob", 100, 200, 80);
	Autobot kristel = Autobot("Kristel", 10, 20, 90);
	Autobot theresa = Autobot("Theresa", 50, 30, 100);
	Autobot mitchell = Autobot("Mitchell", 70, 50, 99);
	Autobot generic1 = Autobot();
	Autobot namedGeneric = Autobot("Fred");
	Autobot bender = Autobot("Bender", 100, 50, 5);
	Autobot homer = Autobot("Homer", 1200, 1500, 30);
	Autobot mario = Autobot("Mario", 2000, 1000, 32);
	Autobot luigi = Autobot("Luigi", 10, 10, 10);
	
	List list1;
	list1.addNode(bob);
	list1.addNode(kristel);
	list1.addNode(theresa);
	list1.addNode(mitchell);
	list1.addNode(generic1);
	list1.addNode(namedGeneric);
	list1.addNode(bender);
	list1.addNode(homer);
	list1.addNode(mario);
	list1.addNode(luigi);
	list1.addNode(luigi);
	list1.addNode(luigi);

	cout << "Demonstrating printing the list backwards:" << endl;
	list1.printListBackwards();

	cout << "Demonstrating the delete function:" << endl;
	list1.deleteNode(luigi);

	cout << "Demonstrating the descending sort and forward printing:" << endl;
	list1.descendingBubbleSort();
	list1.printListForwards();

	cout << "Demonstrating the ascending sort and forward printing:" << endl;
	list1.ascendingBubbleSort();
	list1.printListForwards();

	cout << "Demonstrating searching for an autobot with powerLevel 90, "
			"should print out Kristel:" << endl;
	list1.linearSearchForAutobot(90);

	cout << "Demonstrating searching for an autobot with powerLevel 70, "
			"should print out unfound:" << endl;
	list1.linearSearchForAutobot(70);

	cin.get();
	cin.get();
	return 0;
}