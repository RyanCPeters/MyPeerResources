// HelloWorld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" //helps compile things faster
#include <iostream>
using namespace std;

void pOut(int * point);
void vOut(int point);
void constOut(const int * point);

void modifyVar(int * point);


int main()
{
	int regular = 10;
	int * point1 = &regular;

	vOut(regular);
	pOut(point1);
	constOut(point1);

	modifyVar(point1);

	cout << "Modify: " << regular;

	cin.get();
	cin.get();
    return 0;
}

void pOut(int * point) { //Prints out regular
	cout << *point;
}

void vOut(int point) { //Makes a copy of the variable and does not affect the original
	point = 50;
	cout << point;
}

void constOut(const int * point) { //New pointer that points to the other pointer, which is pointing to regular
	int * castp = (int *)point; //cast the constant pointer to a normal pointer
	*castp = 200;//dereference (allowing you to change the value)
	cout << *point;
}

void modifyVar(int * point) { //Changing the value of regular from a method, using a pointer
	*point = 5;
}