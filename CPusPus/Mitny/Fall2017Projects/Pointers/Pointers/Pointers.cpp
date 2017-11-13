// Pointers.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"
using namespace std;

int main()
{
	int regular = 10;
	cout << "regular (unchanged)" << regular;

	int * point1 = &regular;
	cout << "point1 (unchanged)" << point1;

	cin.get();
	cin.get();


    return 0;
}

