#ifndef DOG_H
#define DOG_H

#include <string>

using namespace std;

class Dog
{
public:
	Dog();
	Dog(string name);
	Dog(string name, int cuteness);
	~Dog();
	string getName();
	bool setName(string name);
	int getCuteness();
	bool setCuteness(int cuteness);
private:
	string name;
	int cutenessLevel;
};
#endif