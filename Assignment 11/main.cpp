/*
Karishma Kapur
ID: 0558326
Assignment 11
Description: Write a function called sumConsonants that will take as arguments two upper case letters. 
Your function should return a sum of all the ascii values of the consonants between the starting 
character and the ending character. Your main function should pass two values to the function and
output the sum of all the consonant character values including the first and the last.
*/

#include <iostream>

using namespace std;

int sumConsonants(char, char);

int main()
{
	char firstChar, lastChar;
	int x;
	cout << "Enter two upper case chars " << endl;
	cin >> firstChar >> lastChar;
	x = sumConsonants(firstChar,lastChar);
	cout << "The sum of the consonants between the two characters is " << x << endl;
	return 0;
}

int sumConsonants(char firstChar, char lastChar)
{
	char temp;
	int sum = 0;

	if (!isupper(firstChar) || !isupper(lastChar))
	{
		return -1;
	}
	if (firstChar > lastChar)
	{
		temp = firstChar;
		firstChar = lastChar;
		lastChar = temp;
	}

	for (char i = firstChar; i <= lastChar; i++)
	{
		if ((i != 'A') && (i != 'E') && (i != 'I') && (i != 'O') && (i != 'U'))
		{
			sum += static_cast<int>(i);
		}
		

	}
	return sum;
}