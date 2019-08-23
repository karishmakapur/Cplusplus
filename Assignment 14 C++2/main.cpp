/*
Karishma Kapur
CSIS 123A
ID: 0558326
Date: 11/21/18
Assignment #14 Templates
main.cpp
Stack class code
*/
#include <iostream>
#include "Stack.h"
#include <string>
using namespace std;

int main() {

	//Int testing
	cout << "================stInt testing===================" << endl;
	Stack<int> stInt; //holds Int
	stInt.push(1);
	stInt.push(2);
	stInt.push(3);
	stInt.push(4);
	stInt.push(5);
	cout << "Value at position 0 is " << stInt.peek(0) << endl;
	int peekPos = 3; 
	cout << "Value at position " << peekPos << " is " << stInt.peek(peekPos) << endl;
	peekPos = stInt.size() - 1;
	cout << "Value at the end of the Stack (position " << peekPos << ") is " << stInt.peek(peekPos) << endl;
	cout << "removed last element: " << stInt.peek(peekPos) << endl;
	stInt.pop();
	peekPos = stInt.size() - 1;
	cout << "Value at the end of the Stack (position " << peekPos << ") is " << stInt.peek(peekPos) << endl;
	
	//Double testing
	cout << "=================stDouble testing=============" << endl;
	Stack<double> stDouble;
	stDouble.push(1.45);
	stDouble.push(2.45);
	stDouble.push(3.45);
	stDouble.push(4.45);
	stDouble.push(5.45);
	cout << "Value at position 0 is " << stDouble.peek(0) << endl;
	peekPos = 3;
	cout << "Value at position " << peekPos << " is " << stDouble.peek(peekPos) << endl;
	peekPos = stDouble.size() - 1;
	cout << "Value at the end of the Stack (position " << peekPos << ") is " << stDouble.peek(peekPos) << endl;
	cout << "removed last element: " << stDouble.peek(peekPos) << endl;
	stDouble.pop();
	peekPos = stDouble.size() - 1;
	cout << "Value at the end of the Stack (position " << peekPos << ") is " << stDouble.peek(peekPos) << endl;

	//String testing
	cout << "=================stString testing=============" << endl;
	Stack<string> stString;
	stString.push("string 1");
	stString.push("string 2");
	stString.push("string 3");
	stString.push("string 4");
	stString.push("string 5");
	cout << "Value at position 0 is " << stString.peek(0) << endl;
	peekPos = 3;
	cout << "Value at position " << peekPos << " is " << stString.peek(peekPos) << endl;
	peekPos = stString.size() - 1;
	cout << "Value at the end of the Stack (position " << peekPos << ") is " << stString.peek(peekPos) << endl;
	cout << "removed last element: " << stString.peek(peekPos) << endl;
	stString.pop();
	peekPos = stString.size() - 1;
	cout << "Value at the end of the Stack (position " << peekPos << ") is " << stString.peek(peekPos) << endl;

	//char testing
	cout << "=================stChar testing=============" << endl;
	Stack<char> stChar;
	stChar.push('a');
	stChar.push('b');
	stChar.push('c');
	stChar.push('d');
	stChar.push('e');
	cout << "Value at position 0 is " << stChar.peek(0) << endl;
	peekPos = 3;
	cout << "Value at position " << peekPos << " is " << stChar.peek(peekPos) << endl;
	peekPos = stChar.size() - 1;
	cout << "Value at the end of the Stack (position " << peekPos << ") is " << stChar.peek(peekPos) << endl;
	cout << "removed last element: " << stChar.peek(peekPos) << endl;
	stChar.pop();
	peekPos = stChar.size() - 1;
	cout << "Value at the end of the Stack (position " << peekPos << ") is " << stChar.peek(peekPos) << endl;
	

}