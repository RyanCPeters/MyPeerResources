#include "stdafx.h"
#include "GraphicNovel.h"


GraphicNovel::GraphicNovel() : Book()
{
	inker = "";
	artist = "";
}


GraphicNovel::~GraphicNovel()
{
}

string GraphicNovel::getInker() const
{
	return inker;
}

string GraphicNovel::getArtist() const
{
	return artist;
}

bool GraphicNovel::setInker(string inker)
{
	this->inker = inker;
	return true;
}

bool GraphicNovel::setArtist(string artist)
{
	this->artist = artist;
	return true;
}

void GraphicNovel::replaceInkerWithArtist()
{
	inker = artist;
}

void GraphicNovel::printDetails(ostream & outStream) const
{
	Book::printDetails(outStream);
	outStream << "Artist: " << artist << endl << "Inker: " << inker << endl;
}
