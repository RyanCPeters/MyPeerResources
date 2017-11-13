// MyYard.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct
{
	int width;
	int length;
} Rectangle;

int Area(const Rectangle &rect);


int main()
{
	int result;
	Rectangle myYard = { 5, 7 };
	result = Area(myYard);
	cout << "My Yard which is " << myYard.width << " by " << myYard.length << " is " << result << endl;
	cin.get();
	cin.get();
    return 0;
}

int Area(const Rectangle &rect) // pass by const reference to save space and time, but wont be able to change value
{
	int area = rect.width * rect.length;
	rect.width = 0;
	return area;
}

