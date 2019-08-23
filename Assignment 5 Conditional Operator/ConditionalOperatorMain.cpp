/*
Karishma Kapur
ID: 0558326
Assignment #5
Assignment Description: Write a program that will take in a whole number then using the conditional
operator determine if the number is odd or even.
The conditional operator should assign a value of "Odd" or "Even" to a string variable to be displayed
to the screen.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int val;
	string str1;
	cout << "Enter a number and I will check to see if it is odd or even: ";
	cin >> val;
	str1 = ((val % 2) == 0) ? "even" : "odd";
	cout << "The number you input is " << str1 << endl;


	return 0;
}