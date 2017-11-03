#ifndef BOTHASHER_H
#define BOTHASHER_H

#include "Autobot.h"

class BotHasher {
private:
	int theHash;
	int multiplier;
	bool madeHash;
	Autobot myBot;

public:
	BotHasher(Autobot &myBot);
	void makeHash();
	int getTheHash();
};
#endif