#pragma once
#include "Book.h";
const int MAX_BOOKS_PER_SHELF = 12;

class BookShelf
{
public:
	BookShelf();
	~BookShelf();

	//getters and setters
	int getCount() const;

	//actions
	bool AddBook(Book book);
	Book RemoveBook(const Book &book);
	Book RemoveBookByLocation(int location);
	int Contains(const Book &book);
	void PrintDetails(ostream &outstream);

private:
	Book books[MAX_BOOKS_PER_SHELF];
	int count;
};

