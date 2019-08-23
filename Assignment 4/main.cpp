/*
Karishma Kapur
Student ID: 0558326
June 11, 2018
Assignment #4
Assignment Description: You are tasked with creating a mileage caclulator
to calculate the amount of money that should be paid to employees. 
*/

#include <iostream>

using namespace std;

int main()
{
	int totalMiles;
	double amountDue;

	cout << "Enter the number of miles driven: ";
	cin >> totalMiles;

	if (totalMiles <= 100)
	{
		cout << "You are owed " << (.25 * totalMiles) << " dollars." << endl;
	}
	else
	{
		amountDue = (100 * .25) + ((totalMiles - 100)*.15);
		cout << "You are owed " << amountDue << " dollars." << endl;
	}

	return 0;
}