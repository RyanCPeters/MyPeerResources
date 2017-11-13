#include "Dog.h"

Dog::Dog()
{
	name = "Spike";
	this->cutenessLevel = 10;
}

Dog::Dog(string name)
{
	this->name = name;
	this->cutenessLevel = 10;
}

Dog::Dog(string name, int cuteness)
{
	this->name = name;
	this->cutenessLevel = cuteness;
}

Dog::~Dog()
{
}

string Dog::getName()
{
	return name;
}

bool Dog::setName(string name)
{
	this->name = name;
	return true;
}

int Dog::getCuteness()
{
	return cutenessLevel;
}

bool Dog::setCuteness(int cuteness)
{
	this->cutenessLevel = cuteness;
	return true;
}
