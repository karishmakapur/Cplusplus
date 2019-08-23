/*
Karishma Kapur
ID: 0558326
Assignment 9
Create a temperature conversion program that will convert the following to Fahrenheit :
*/

#include <iostream>

using namespace std;

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
		<< "\t X- eXit\n" << endl;
	cout << "To use the converter you must input a value and one of the temperatures types.\n" 
		<< "For example, 32 C converts 32 degrees from Celcius to Farenheit." << endl;
	cout << "\n";
	
	// Prime loop
	cout << "Please enter a value and its type to be converted" << endl;
	cin >> num >> tempType;
	tempType = toupper(tempType);
	
	// while loop
	while (tempType == 'C' || tempType == 'K' || tempType == 'N' || tempType == 'X')
	{
		// if / else
		if (tempType == 'X')
			{

				break;
			}

			//switch 
			switch (tempType)
			{
			case 'K':
				cout << num << tempType << " is " << ((num - 273.15) * 1.8000 + 32) << " in Farenheit." << endl;
				break;
			case 'C':
				cout << num << tempType << " is " << (((num * 9) / 5) + 32) << " in Farenheit." << endl;
				break;
			case 'N':
				cout << num << tempType << " is " << (((num * 60) / 11) + 32) << " in Farenheit." << endl;
				break;
			}

			cout << "Please enter a value and its type to be converted" << endl;
			cin >> num >> tempType;
			tempType = toupper(tempType);
			
		
		
	}

		return 0;
}