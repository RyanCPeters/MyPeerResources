#include "BotHasher.h"

using namespace std;

BotHasher::BotHasher() : multiplier(1234), theHash(-1) //myBot = _myBot
{

}

void BotHasher::makeHash() {

	theHash = multiplier * myBot.getHeightInCentimeters * (myBot.getNumKills + 1);
	madeHash = true;
}

int BotHasher::getTheHash() {
	return madeHash ? theHash : -1;
}

void BotHasher::setOwner(Autobot & bot)
{
	myBot = bot;
}
