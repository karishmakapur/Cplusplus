/*
Karishma Kapur
ID # 0558326
Assignment 7
Description: Write a program that will accept n number of integers from the keyboard. 
When the loop exits output the largest and smallest value entered.
*/

#include <iostream>

using namespace std;

int main()
{
	int times;
	int number;
	int largest;
	int smallest;
	
	cout << "How many numbers do you want to enter?" << endl;
	cin >> times;
	
	cout << "Enter a number: " << endl;
	cin >> number;
	
	smallest = number;
	largest = number;

	for (int i = 0; i < (times - 1); i++)
	{
		cout << "Enter a number: " << endl;
		cin >> number;
		
		if (number < smallest)
		{
			smallest = number;
		}
		if (number > largest)
		{
			largest = number;
		}
	}

	cout << "The largest number is " << largest << endl;
	cout << "The smallest number is " << smallest << endl;
	return 0;
}