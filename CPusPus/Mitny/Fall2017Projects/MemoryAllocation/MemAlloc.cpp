#include <iostream>

void print(int data);
void printRef(int &data);
void printAdd(int *data);

using namespace std;

int main() {

	int data = 8;
	cout << &data << endl;

	print(data);
	printRef(data);
	printAdd(&data);

	cin.get();
	cin.get();
	return 0;
}

void print(int data) {
	cout <<"Value: " << data << " Address: " << &data << " " << endl;
}

void printRef(int &data) {
	cout << "Value: " << data << " Address: " << &data << " " << endl;
}

void printAdd(int *data) {
	cout << "Value: " <<  data << " Address: " << &data << " " << endl;
}