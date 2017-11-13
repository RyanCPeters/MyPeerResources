#pragma once
#include <string>
#include <iostream>
using namespace std;

class Robot
{
public:
	//Constructors
	Robot(); //Constructor
	Robot(string name);
	Robot(string name, bool isSentient);
	~Robot();

	//Getters and Setters
	string getName() const; 
	bool setName(string name);

	string getMaterial() const;
	bool setMaterial(string material);

	bool getIsSentient() const;
	bool setIsSentient(bool sentience);

	int getID() const;
	bool setID(int ID);

	string getName() const;
	bool setName(string name);

	int getNumLimbs() const;
	bool setNumLimbs(int numLimbs);

	int getNumMics() const;
	bool setNumMics(int numMics);

	//Actions
	int walk(int numSteps);
	void kill(Robot killedRobot);
	string talk(string words);
	void clean(string dirtyObject);
	void selfDestruct();

private:
	string material;
	float weight;
	bool isSentient;
	int id;
	string name;
	int numLinks;
	int numMics;
};