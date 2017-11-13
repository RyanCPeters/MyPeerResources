//----------------------------------------------------------------------------
//  Title: Autobot
//			
//  File: C:\Users\mitchell.nye\Documents\Visual Studio 2017\Projects
//		    \Autobot\Autobot.h
//
//	Description: This Class allows the user to create Autobot objects
//				 that contain data about themselves including:
//				 name, height, weight, power level, kill count,
//				 and whether they are alive or not. The objects can
//			     attack, selfDestruct and talk. By using + or +=
//				 the autobots can combine their stats together.
//				 They can also be compared with == or !=. Lastly, the
//				 << operator can be used to display their stats.
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

#ifndef AUTOBOT_H
#define AUTOBOT_H

#include <string>
#include <iostream>
using namespace std;

class Autobot
{
	friend ostream& operator<<(ostream &outStream, const Autobot &autobot);

public:
	Autobot();
	Autobot(string name);
	Autobot(string name, int heightInCentimeters, double weightInKilograms, int powerLevel);
	~Autobot();

	string getName() const;
	bool setName(string name);

	int getHeightInCentimeters() const;
	bool setHeightInCentimeters(int heightInCentimeters);

	double getWeightInKilograms() const;
	bool setWeightInKilograms(double weightInKilograms);

	int getPowerLevel() const;
	bool setPowerLevel(int powerLevel);

	int getNumKills() const;
	bool setNumKills(int numKills);

	bool getIsAlive() const;
	bool setIsAlive(bool isAlive);

	Autobot operator+(const Autobot &autobot) const;
	Autobot& operator +=(const Autobot &autobot);

	Autobot& operator -=(const Autobot &autobot);
	Autobot operator-(const Autobot &autobot) const;
	operator int() const;

	bool operator==(const Autobot &autobot) const;
	bool operator!=(const Autobot &autobot) const;

	bool operator>(const Autobot &autobot) const;
	bool operator>=(const Autobot &autobot) const;

	bool operator<(const Autobot &autobot) const;
	bool operator<=(const Autobot &autobot) const;

	bool attack(Autobot &enemy);
	void selfDestruct();
	void talk(ostream &outStream) const;

private:
	const int MAX_POWER_LEVEL;
	const int MIN_POWER_LEVEL;

	const int MAX_HEIGHT_IN_CENTIMETERS;
	const int MIN_HEIGHT_IN_CENTIMETERS;
	
	const double MAX_WEIGHT_IN_KILOGRAMS;
	const double MIN_WEIGHT_IN_KILOGRAMS;

	const int MAX_KILLS;

	const int DEFAULT_HEIGHT_IN_CENTIMETERS;
	const double DEFAULT_WEIGHT_IN_KILOGRAMS;
	const int DEFAULT_POWER_LEVEL;

	string name;
	int heightInCentimeters;
	double weightInKilograms;
	int powerLevel;
	int numKills;
	bool alive;
};

#endif