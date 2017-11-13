#include "Autobot.h"

int main() {
	Autobot bob = Autobot("bob", 10, 10, 10);
	Autobot steve = Autobot("steve", 20, 20, 20);

	steve.attack(bob);

	cout << steve << endl;
	cout << bob << endl;

	cin.get();
	cin.get();
	return 0;
}