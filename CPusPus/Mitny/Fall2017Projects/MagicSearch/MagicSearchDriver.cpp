#include <iostream>
#include <list>
#include <vector>
//#include "Dog.h"

using namespace std;

template <class myType>
class Dog {
	myType a, b;
public:
	Dog(int first, int second) {
		a = first;
		b = second;
	}
		myType getMax();
};

template <class myType>
myType Dog<myType>::getMax() {
	myType returnVal;
	returnVal = a > b ? a : b;
	return returnVal;
}

int main() {

	/*Dog scout = Dog("Scout", 100);
	Dog stella = Dog("Stella", 80);
	Dog roger = Dog("Roger", 50);
	Dog dozer = Dog("Dozer", 70);*/

	Dog<int>scout(100, 75);
	cout << scout.getMax();

	std::list<Dog(int first, int second)> listExample(0);

	listExample.push_front(scout);
	listExample.push_back(stella);

	for (Dog n : listExample) {
		cout << n.getCuteness() << endl;
	}

	cin.get();
	cin.get();
	return 0;
}