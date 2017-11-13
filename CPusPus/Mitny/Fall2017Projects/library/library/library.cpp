// library.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Book.h"
#include "BookShelf.h"
#include "GraphicNovel.h"
using namespace std;


int main()
{
	Book book1, book2, book3("To Kill a Mocking Bird", "Harper Lee"), book4("1984","Orwell",285,15.99);
	BookShelf fiction;
	GraphicNovel gn1;

	book1.setTitle("The Dying Grass");
	book1.setAuthor("William Vollmann");
	book1.setLength(1365);
	book1.setCost(55.00);
	book1.setBookmark(33);

	book2 = book1;

	cout << book2.getTitle() << endl;
	book1.turnPage(12);
	//book1.printDetails(cout);
	//book3.printDetails(cout);
	//book4.printDetails(cout);

	fiction.AddBook(book1);
	fiction.AddBook(book2);
	fiction.AddBook(book3);
	fiction.AddBook(book4);
	

	
	gn1.setAuthor("Moore");
	gn1.setTitle("Watchmen");
	gn1.setArtist("picasso");
	gn1.setInker("matisse");
	fiction.AddBook(gn1);
	gn1.printDetails(cout);
	fiction.PrintDetails(cout);
	cin.get();
	cin.get();
    return 0;
}