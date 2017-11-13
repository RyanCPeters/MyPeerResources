//----------------------------------------------------------------------------
//  Title: Autobot
//			
//  File: C:\Users\mitchell.nye\Documents\Visual Studio 2017\Projects
//		    \MasterSet\Autobot.cpp
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

#include "Autobot.h"

Autobot::Autobot() : MAX_POWER_LEVEL(100), MIN_POWER_LEVEL(1),
	MAX_HEIGHT_IN_CENTIMETERS(10000), MIN_HEIGHT_IN_CENTIMETERS(1),
	MAX_WEIGHT_IN_KILOGRAMS(200000000.0), MIN_WEIGHT_IN_KILOGRAMS(1),
	MAX_KILLS(999999), DEFAULT_HEIGHT_IN_CENTIMETERS(700),
	DEFAULT_WEIGHT_IN_KILOGRAMS(2000.0), DEFAULT_POWER_LEVEL(5)
{
	name = "Humanoid Robot";
	heightInCentimeters = DEFAULT_HEIGHT_IN_CENTIMETERS;;
	weightInKilograms = DEFAULT_WEIGHT_IN_KILOGRAMS;
	powerLevel = DEFAULT_POWER_LEVEL;
	numKills = 0;
	alive = true;
}

Autobot::Autobot(string name) : MAX_POWER_LEVEL(100), MIN_POWER_LEVEL(1),
	MAX_HEIGHT_IN_CENTIMETERS(10000), MIN_HEIGHT_IN_CENTIMETERS(1),
	MAX_WEIGHT_IN_KILOGRAMS(200000000.0), MIN_WEIGHT_IN_KILOGRAMS(1),
	MAX_KILLS(999999), DEFAULT_HEIGHT_IN_CENTIMETERS(700),
	DEFAULT_WEIGHT_IN_KILOGRAMS(2000.0), DEFAULT_POWER_LEVEL(5)
{
	this->name = name;
	heightInCentimeters = DEFAULT_HEIGHT_IN_CENTIMETERS;;
	weightInKilograms = DEFAULT_WEIGHT_IN_KILOGRAMS;
	powerLevel = DEFAULT_POWER_LEVEL;
	numKills = 0;
	alive = true;
}

//----------------------------------------------------------------------------
// The "set" methods in this constructor check that the arguments are of valid
// size. If they are too big the variable is set to the max value, and if they
// are too small, they are set to the minimum value.
//----------------------------------------------------------------------------
Autobot::Autobot(string name, int heightInCentimeters, 
				double weightInKilograms, int powerLevel) : 
	MAX_POWER_LEVEL(100), MIN_POWER_LEVEL(1),
	MAX_HEIGHT_IN_CENTIMETERS(10000), MIN_HEIGHT_IN_CENTIMETERS(1),
	MAX_WEIGHT_IN_KILOGRAMS(200000000.0), MIN_WEIGHT_IN_KILOGRAMS(1),
	MAX_KILLS(999999), DEFAULT_HEIGHT_IN_CENTIMETERS(700),
	DEFAULT_WEIGHT_IN_KILOGRAMS(2000.0), DEFAULT_POWER_LEVEL(5)
{
	this->name = name;
	numKills = 0;
	alive = true;
	setHeightInCentimeters(heightInCentimeters);
	setWeightInKilograms(weightInKilograms);
	setPowerLevel(powerLevel);
}

Autobot::~Autobot()
{
}
;

string Autobot::getName() const
{
	return name;
}

bool Autobot::setName(string name)
{
	this->name = name;
	return true;
}

int Autobot::getHeightInCentimeters() const
{
	return heightInCentimeters;
}

bool Autobot::setHeightInCentimeters(int heightInCentimeters)
{
	if (heightInCentimeters > MAX_HEIGHT_IN_CENTIMETERS)
		this->heightInCentimeters = MAX_HEIGHT_IN_CENTIMETERS;
	else if (heightInCentimeters < MIN_HEIGHT_IN_CENTIMETERS)
		this->heightInCentimeters = MIN_HEIGHT_IN_CENTIMETERS;
	else
		this->heightInCentimeters = heightInCentimeters;
	return true;
}

double Autobot::getWeightInKilograms() const
{
	return weightInKilograms;
}

bool Autobot::setWeightInKilograms(double weightInKilograms)
{
	if (weightInKilograms > MAX_WEIGHT_IN_KILOGRAMS)
		this->weightInKilograms = MAX_WEIGHT_IN_KILOGRAMS;
	else if (weightInKilograms < MIN_WEIGHT_IN_KILOGRAMS)
		this->weightInKilograms = MIN_WEIGHT_IN_KILOGRAMS;
	else
		this->weightInKilograms = weightInKilograms;
	return true;
}

int Autobot::getPowerLevel() const
{
	return powerLevel;
}

bool Autobot::setPowerLevel(int powerLevel)
{
	if (powerLevel > MAX_POWER_LEVEL)
		this->powerLevel = MAX_POWER_LEVEL;
	else if (powerLevel < MIN_POWER_LEVEL)
		this->powerLevel = MIN_POWER_LEVEL;
	else
		this->powerLevel = powerLevel;
	return true;
}

int Autobot::getNumKills() const
{
	return numKills;
}

bool Autobot::setNumKills(int numKills)
{
	if (numKills < 0)
		numKills = 0;
	else
		this->numKills = numKills;
	return true;
}

bool Autobot::getIsAlive() const
{
	return alive;
}

bool Autobot::setIsAlive(bool isAlive)
{
	alive = isAlive;
	return true;
}

bool Autobot::operator<(const Autobot &autobot) const
{
	return (powerLevel < autobot.powerLevel);
}

bool Autobot::operator>(const Autobot &autobot) const
{
	return (powerLevel > autobot.powerLevel);
}

//----------------------------------------------------------------------------
// Relies on operator+=()
//
// Returns a temporary Autobot that has the stats of two combined Autobots
//----------------------------------------------------------------------------
Autobot Autobot::operator+(const Autobot & autobot) const
{
	Autobot combinedAutobots = *this;
	combinedAutobots += autobot;
	return combinedAutobots;
}

//----------------------------------------------------------------------------
// Combines and stores the stats of the two Autobots in the first Autobot.
// If either of them are not alive, the combination fails.
//----------------------------------------------------------------------------
Autobot& Autobot::operator+=(const Autobot & autobot)
{
	if (alive && autobot.alive) 
	{
		name += " " + autobot.name;
		setHeightInCentimeters(heightInCentimeters += 
			autobot.heightInCentimeters);
		setWeightInKilograms(weightInKilograms += autobot.weightInKilograms);
		setPowerLevel(powerLevel += autobot.powerLevel);
		numKills += autobot.numKills;
	}
	else if (alive && !autobot.alive)
	{
		cout << "*Warning* Cannot combine " << autobot.name <<
			" because he/she is dead." << endl;
	}
	else if (!alive && autobot.alive)
	{
		cout << "*Warning* Cannot combine " << name <<
			" because he/she is dead." << endl;
	}
	return *this;
}

bool Autobot::operator==(const Autobot & autobot) const
{
	return(name == autobot.name) &&
		(heightInCentimeters == autobot.heightInCentimeters) &&
		(weightInKilograms == autobot.weightInKilograms) &&
		(powerLevel == autobot.powerLevel) &&
		(numKills == autobot.numKills) &&
		(alive == autobot.alive);
}

bool Autobot::operator!=(const Autobot & autobot) const
{
	return(name != autobot.name) ||
		(heightInCentimeters != autobot.heightInCentimeters) ||
		(weightInKilograms != autobot.weightInKilograms) ||
		(powerLevel != autobot.powerLevel) ||
		(numKills != autobot.numKills) ||
		(alive != autobot.alive);
}

//----------------------------------------------------------------------------
// Determines if an attack can happen (both robots must be alive), and then
// compares the power levels of the Autobots to determine who lives and who
// dies.
//----------------------------------------------------------------------------
bool Autobot::attack(Autobot & enemy)
{
	if (alive && enemy.alive) 
	{
		if (powerLevel > enemy.powerLevel) 
		{
			numKills++;
			enemy.alive = false;
		}
		else if (powerLevel == enemy.powerLevel) 
		{
			enemy.alive = false;
			alive = false;
		}
		else 
		{
			enemy.numKills++;
			alive = false;
		}
		return true;
	}
	else 
	{
		cout << "Decommisioned Autobots cannot fight." << endl;
		return false;
	}
}

void Autobot::selfDestruct()
{
	name += " (Decomissioned)";
	alive = false;
}

void Autobot::talk(ostream &outStream) const
{
	if (alive) 
	{
		outStream << "I am Autobot " << name << endl;
		outStream << "I am " << heightInCentimeters << " centimeters tall" <<
			endl;
		outStream << "I weigh " << weightInKilograms << " kilograms" << endl;
		outStream << "I have a power level of " << powerLevel << endl;
		outStream << "I have " << numKills << " kills" << endl;
		outStream << "Nice to meet you.\n" << endl;
	}
	else 
	{
		outStream << "The Autobot " << name <<
		" attempts to talk and sparks fly from its speaker.\n" << endl;
	}
}

//----------------------------------------------------------------------------
// Allows use of << operator for output of stats (useful for dead Autobots
// that can't talk
//----------------------------------------------------------------------------
ostream& operator<<(ostream & outStream, const Autobot & autobot)
{
	outStream << "Name: " << autobot.name << endl;
	outStream << "Height: " << autobot.heightInCentimeters << 
		" centimeters" << endl;
	outStream << "Weight: " << autobot.weightInKilograms << 
		" kilograms" << endl;
	outStream << "Power Level: " << autobot.powerLevel << endl;
	outStream << "Kill count: " << autobot.numKills << " kills" << endl;
	outStream << "Is Sentient: " << (autobot.alive ? "True" : "False") << 
		"\n" << endl;
	return outStream;
}