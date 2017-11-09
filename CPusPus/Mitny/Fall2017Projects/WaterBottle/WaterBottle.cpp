#include <iostream>
#include <string>

using namespace std;

class WaterBottle {
private:
	double volume;
	string name;
public:
	WaterBottle();
	WaterBottle(string name);
	~WaterBottle();
	double getVolume();
	void setVolume(double);
	string getName();
	void setName(string);

	WaterBottle operator+(WaterBottle);
};

WaterBottle::WaterBottle() {
	name = "blah";
	volume = 8.9;
}

WaterBottle::WaterBottle(string name) {
	this->name = name;
	volume = 1.2;
}

WaterBottle WaterBottle::operator+(WaterBottle awb) {
	WaterBottle newWaterBottle;
	newWaterBottle.setVolume(awb.getVolume() + getVolume());
	return newWaterBottle;
}

WaterBottle::~WaterBottle() {

}

double WaterBottle::getVolume() {
	return volume;
}

void WaterBottle::setVolume(double vol) {
	volume = vol;
}

string WaterBottle::getName() {
	return name;
}

void WaterBottle::setName(string name) {
	this->name = name;
}


int main() {

	WaterBottle bottle1 = WaterBottle("Bottle1");
	cout << bottle1.getName() << " " << bottle1.getVolume() << endl;

	WaterBottle* w = new WaterBottle[5];

	w[0] = w[0] + w[1];

	for (int i = 0; i < 5; i++) {
		cout << w[i].getName() << " " << i << " " << w[i].getVolume() << endl;
	}

	cin.get();
	cin.get();
	return 0;
}