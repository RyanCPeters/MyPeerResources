#include "stdafx.h"
#include "Autobot.h"

using namespace std;

template <class T> 

T GetMax (T a, T b)
{
	return (a > b) ? a : b;
}


int main()
{
	int x, y;
	Autobot a = Autobot("Zob");
	Autobot b = Autobot("Mitch");
	x = 0; y = 5;
	cout << GetMax <int>(x, y);
	cout << GetMax <string>(a.getName() , b.getName());

	cin.get();
	cin.get();
    return 0;
}

