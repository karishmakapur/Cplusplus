/* 
Karishma Kapur
ID: 0558326
Assignment 12
Description: Pythagorean Theorem function
*/
#include <iostream>
#include <string>
#include <cmath>

double pythag(double, double, char);

using namespace std;

int main()
{
	double side1, side2;
	string ostr1 = "Pythagorean theorem, Enter sides A and B and I will solve for C\n";
	string ostr2 = "Now enter sides B and C and I will solve for A\n";
	string ostr3 = "Finally, enter sides A and C and I will solve for B\n";
	string x = "CAB";

	for (int i = 0; i <= 2; i++)
	{
		switch (i)
		{
		case 0:
		{
			cout << ostr1;
			break;
		}
		case 1:
		{
			cout << ostr2;
			break;
		}
		case 2:
		{
			cout << ostr3;
			break;
		}

		}
		cin >> side1 >> side2;
		cout << "Side " << x.at(i) << " is equal to " << pythag(side1, side2, x.at(i)) << endl;
	}
	return 0;
}

double pythag(double side1, double side2, char unknownSide)
{ 
	double calculation;
	switch (unknownSide)
	{
	case 'A':
	{
		calculation = sqrt(pow(side2, 2) - pow(side1, 2));

		break;
	}
	case 'B':
	{
		calculation = sqrt(pow(side2, 2) - pow(side1, 2));
		break;
	}
	case 'C':
		calculation = sqrt(pow(side1, 2) + pow(side2, 2));
		break;

	}
	return calculation;
}