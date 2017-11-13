#pragma once
#include "Book.h"
class GraphicNovel : public Book
{
public:
	GraphicNovel();
	~GraphicNovel();

	//getters and setters
	string getInker() const;
	string getArtist() const;
	bool setInker(string inker);
	bool setArtist(string artist);

	void replaceInkerWithArtist();
	void printDetails(ostream &outStream) const;

private:
	string inker;
	string artist;
};

