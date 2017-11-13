#include "stdafx.h"
#include "Book.h"


Book::Book()
{
	length = 0;
	bookmark = 0;
	cost = 0;
	title = "";
	author = "";
}

Book::Book(string title, string author)
{
	this->title = title;
	this->author = author;
}

Book::Book(string title, string author, int length, float cost)
{
	this->length = length;
	this->cost = cost;
	this->title = title;
	this->author = author;
}


Book::~Book()
{
}

string Book::getTitle() const
{
	return title;
}

bool Book::setTitle(string title)
{
	this->title = title; //points at the instance variable of the object
	return true;
}

string Book::getAuthor() const
{
	return author;
}

bool Book::setAuthor(string author)
{
	this->author = author;
	return true;
}

int Book::getLength() const
{
	return length;
}

bool Book::setLength(int length)
{
	this->length = length;
	return true;
}

int Book::getBookmark() const
{
	return bookmark;
}

bool Book::setBookmark(int bookmark)
{
	if (bookmark < 0 || bookmark > length)
		return false;
	this->bookmark = bookmark;
	return true;
}

float Book::getCost() const
{
	return cost;
}

bool Book::setCost(float cost)
{
	if (cost < 0)
		return false;
	this->cost = cost;
	return true;
}

int Book::turnPage(int numPages)
{
	setBookmark(bookmark + numPages);
	return bookmark;
}

void Book::printDetails(ostream &outStream) const
{
	outStream << "Title: " << title << endl;
	outStream << "Author " << author << endl;
	outStream << "Number of pages " << length << endl;
	outStream << "Price " << cost << endl;
	outStream << "Current location " << bookmark << endl;
}
