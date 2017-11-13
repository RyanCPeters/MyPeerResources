#pragma once
#include <string>
#include <iostream>
using namespace std;

class Book
{
public:
	//Constructors
	Book(); //Constructor
	Book(string title, string author);
	Book(string title, string author, int length, float cost);
	~Book();

	//getters and setters
	string getTitle() const; //tells whoever is using the method that it is an accessor and it will not change the data
	bool setTitle(string title);
	string getAuthor() const;
	bool setAuthor(string author);
	int getLength() const;
	bool setLength(int length);
	int getBookmark() const;
	bool setBookmark(int bookmark);
	float getCost() const;
	bool setCost(float cost);

	//Actions
	int turnPage(int numPages);
	void printDetails(ostream &theStream) const; //passing in a reference to an output string

private:
	string title;
	int length;
	int bookmark;
	string author;
	float cost;
};

