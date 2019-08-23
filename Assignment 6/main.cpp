/*
Karishma Kapur
ID: 0558236
Assignment #6
Assignment Description: Write a simple calculator program.
*/
#include <iostream>

using namespace std;

int main()
{
	int num1, num2;
	char oper;
	cout << "Enter an expression: " << endl;
	cin >> num1 >> oper >> num2;

	switch (oper)
	{
	case '*':
		cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
		break;
	case '+':
		cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
		break;
	case '-':
		cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
		break;
	case '/':
		cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
		break;
	default: 
		cout << "Invalid Operator. " << endl;

	}

	
	return 0;
}