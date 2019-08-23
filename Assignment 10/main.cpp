/*
Karishma Kapur
ID: 0558326
Assignment 10
Modify Lab 9 so that the calculations for temperature conversion are done within functions. 
For this assignment you will need three separate functions.
*/

#include <iostream>

using namespace std;

double C2F(double);
double K2F(double);
double N2F(double);

int main()
{
	// variables
	double num;
	char tempType;

	// welcome statement
	cout << "This temperature conversion program converts other temperature types to farenheit." << endl;
	cout << "The temperature types are:\n"
		<< "\t C- Celcius\n"
		<< "\t K- Kelvin\n"
		<< "\t N- Newton\n"
		<< "\t 0X- eXit\n" << endl;
	cout << "To use the converter you must input a value and one of the temperatures types.\n"
		<< "For example, 32 C converts 32 degrees from Celcius to Farenheit." << endl;
	cout << "\n";

	// Prime loop
	
		cout << "Please enter a value and its type to be converted" << endl;
		cin >> num >> tempType;
		tempType = toupper(tempType);

	// while loop
	while (tempType != 'X')
	{
	

		//switch 
		switch (tempType)
		{
		case 'K':
			cout << num << tempType << " is " << K2F(num) << " in Farenheit." << endl;
			break;
		case 'C':
			cout << num << tempType << " is " << C2F(num) << " in Farenheit." << endl;
			break;
		case 'N':
			cout << num << tempType << " is " << N2F(num) << " in Farenheit." << endl;
			break;
		default:
			cout << "Invalid input. Please input a value and one of the temperatures types." << endl;
		}
		cout << "Please enter a value and its type to be converted" << endl;
		cin >> num >> tempType;
		tempType = toupper(tempType);



	}

	return 0;
}
double K2F(double num)
{
	return ((num - 273.15) * 1.8000 + 32);
}
double C2F(double num)
{
	return (((num * 9) / 5) + 32);
}
double N2F(double num)
{
	return (((num * 60) / 11) + 32);
}
