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
	BotHasher();
	void makeHash();
	int getTheHash();
	void setOwner(Autobot &bot);
	BotHasher(const BotHasher &)
};
#endif