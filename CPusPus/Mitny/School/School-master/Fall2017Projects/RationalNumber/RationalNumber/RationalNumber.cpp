// 
//  Rational class represents a rational value as "a / b" where a and b are integers
//  Operators with denominator as 0 keep the denominator as 0--not a rational.
//

#include "stdafx.h"
#include <iostream>
#include "Rational.h"
using namespace std;

int main()
{
	int waitVar;
	Rational rat1(3, 7), rat2(5, 10);
	Rational rat3, rat4, rat5, rat6;
	cout << "Welcome to our calculator" << endl;

	cout << "rat1: " << rat1 << endl;
	cout << "rat2: " << rat2 << endl;
	cout << "rat3: " << rat3 << endl;

	cout << "rat1 + rat2 = " << (rat1 + rat2) << endl;
	cout << "rat1 - rat2 = " << (rat1 - rat2) << endl;
	cout << "rat1 * rat2 = " << (rat1 * rat2) << endl;
	cout << "rat1 / rat2 = " << (rat1 / rat2) << endl;
	cout << "-rat1 = " << -rat1 << endl;

	rat1 -= rat2;
	cout << "rat1 -= rat2; rat1: " << rat1 << endl;



	cout << "Input a rational. Numerator and denomiator as two integers: ";
	cin >> rat3;
	cout << "You entered: " << rat3 << endl;

	if (rat3 == rat2)
	{
		cout << "The rational you entered is equal to rat2" << endl;
	}
	else
	{
		cout << "The rational you entered is not equal to rat2" << endl;
	}

	cin.get();
	cin.get();

	return 0;
}