#include "DoubleList.h"
#include <iostream>

using namespace std;

int main()
{

	DoubleList<int> myList = DoubleList<int>();
	myList.pushBack(5);
	myList.pushBack(10);
	myList.pushBack(15);

	cin.get();
	cin.get();
	return 0;
}