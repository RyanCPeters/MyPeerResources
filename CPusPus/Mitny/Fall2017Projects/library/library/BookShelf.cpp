#include "stdafx.h"
#include "BookShelf.h"


BookShelf::BookShelf()
{
	count = 0;
}


BookShelf::~BookShelf()
{
}

int BookShelf::getCount() const
{
	return count;
}

bool BookShelf::AddBook(Book book)
{
	int i = 0;
	if (count == MAX_BOOKS_PER_SHELF) {
		return false;
	}
	while (books[i].getTitle() != "") {
		i++;
	}
	books[i] = book;
	count++;
	return true;
}

Book BookShelf::RemoveBook(const Book & book)
{
	return Book();
}

Book BookShelf::RemoveBookByLocation(int location)
{
	return Book();
}

int BookShelf::Contains(const Book & book)
{
	return 0;
}

void BookShelf::PrintDetails(ostream &outstream)
{
	for (int i = 0; i < MAX_BOOKS_PER_SHELF; i++)
	{
		if (books[i].getTitle() != "") {
			outstream << "Book Number " << i << ":" << endl;
			books[i].printDetails(outstream);
			outstream << endl;

		}
	}
}
