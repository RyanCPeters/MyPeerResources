#include <stdarg.h>
#include <vector>
#include "Autobot.h"
#include <iterator>
#include <algorithm>


using namespace std;

bool descendingSort(int i, int j) {
	return (i > j);
}

int main() {

	vector<Autobot> vAutos(4);

	Autobot auto1 = Autobot("1");
	Autobot auto2 = Autobot("2");
	Autobot auto3 = Autobot("3");
	Autobot auto4 = Autobot("4");

	vAutos.push_back(auto1);
	vAutos.push_back(auto2);
	vAutos.push_back(auto3);
	vAutos.push_back(auto4);

	for (std::vector<Autobot>::iterator it = vAutos.begin(); it != vAutos.end(); it++) {
		cout << ' ' << *it;
	}

	/*for (std::vector<Autobot>::iterator it = vAutos.end() - 1; it != vAutos.begin(); it--) {
		cout << ' ' << *it;
	}*/

	sort(vAutos.begin(), vAutos.end());
		


	cin.get();
	cin.get();

	return 0;
}