/*
Karishma Kapur
CSIS 123A
ID: 0558326
8/30/18
Assignment 3: Overloaded Constructors
main.cpp file
Instantiates Double Class and Integer Class along with testing the methods and constructors from each class
*/

#include <iostream>
#include "Double.h"
#include "Integer.h"
#include <iomanip>

using namespace std;

int main() {
	cout << "=================Doubles==========================" << endl;
	Double d1, d2, d3;
	//set Doubles
	d1.equals(12.35);
	d2.equals(12.34);

	//add Doubles
	d3 = d1.add(d2);
	cout << "add Doubles: " << d1.toDouble() << " + " << d2.toDouble() << " = " << d3.toDouble() << endl << endl;

	//subtract Doubles
	d3 = d1.sub(d2);
	cout << "subtract Doubles: " << d1.toDouble() << " - " << d2.toDouble() << " = " << d3.toDouble() << endl << endl;

	//multiply Doubles
	d3 = d1.mul(d2);
	cout << "multiply Doubles: " << d1.toDouble() << " * " << d2.toDouble() << " = " << d3.toDouble() << endl << endl;

	//divide Doubles
	d3 = d1.div(d2);
	cout << "divide Doubles: " << d1.toDouble() << " / " << d2.toDouble() << " = " << d3.toDouble() << endl << endl;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	cout << "==================Integers========================" << endl;
	Integer i1, i2, i3;
	//set Integers
	i1.equals(12);
	i2.equals(10);

	//add Integers
	i3 = i1.add(i2);
	cout << "add Integers: " << i1.toInt() << " + " << i2.toInt() << " = " << i3.toInt() << endl << endl;

	//subtract Integers
	i3 = i1.sub(i2);
	cout << "subtract Integers: " << i1.toInt() << " - " << i2.toInt() << " = " << i3.toInt() << endl << endl;

	//multiply Integers
	i3 = i1.mul(i2);
	cout << "multiply Integers: " << i1.toInt() << " * " << i2.toInt() << " = " << i3.toInt() << endl << endl;

	//divide Integers
	i3 = i1.div(i2);
	cout << "divide Integers: " << i1.toInt() << " / " << i2.toInt() << " = " << i3.toInt() << endl << endl;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	cout << "============Integer Construtor Tests==============" << endl;

	//Integer Constructors:
	//Default Integer Constructors
	Integer i4;
	cout << "Default Integer Constructor: i4 = " << i4.toInt() << endl << endl;

	//Overloaded Integer Constructor that passes an Integer Object
	i4.equals(5); //Shows that whatever value is in i4 is put into i5.
	Integer i5(i4);
	cout << "Overloaded Integer Constructor that passes an Integer Object: i5 = " << i5.toInt() << endl << endl;
	
	//Overloaded Integer Constructor that passes a primitive int.
	
	Integer i6(8);
	cout << "Overloaded Integer Constructor that passes a primitive int: i6 = " << i6.toInt() << endl << endl;
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	cout << "=============Double Construtor Tests==============" << endl;

	//Double Constructors:
	//Default Double Constructors
	cout << fixed << showpoint; //needed to show decimal points for whole numbers.
	Double d4;
	cout << "Default Double Constructor: d4 = " << d4.toDouble() << endl << endl;

	//Overloaded Double Constructor that passes a primitive double.
	Double d6(8.5);
	cout << "Overloaded Double Constructor that passes a primitive double: d6 = " << d6.toDouble() << endl << endl;

	//Overloaded Double Constructor that passes a Double Object
	d6.equals(9.8); //Shows that whatever value is in d6 is put into d7
	Double d7(d6);
	cout << "Overloaded Double Constructor that passes a Double Object: d7 = " << d7.toDouble() << endl << endl;

	//Overloaded Double Constructor that passes an Integer Object
	Double d8(i6);
	cout << "Overloaded Double Constructor that passes an Integer Object: d8 = " << d8.toDouble() << endl << endl;

	cout.unsetf(ios::fixed);
	cout.unsetf(ios::showpoint);


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	cout << "===========Overloaded Double Functions============" << endl;
	//Overloaded Double Mathematical Methods
	Double od1, od2;
	//set Double
	od1.equals(11.30);
	double primitiveDouble = 10.74;

	//add Doubles
	
	od2 = od1.add(primitiveDouble);
	cout << "add Doubles: " << od1.toDouble() << " + " << primitiveDouble << " = " << od2.toDouble() << endl << endl;

	//subtract Doubles
	od2 = od1.sub(primitiveDouble);
	cout << "subtract Doubles: " << od1.toDouble() << " - " << primitiveDouble << " = " << od2.toDouble() << endl << endl;

	//multiply Doubles
	od2 = od1.mul(primitiveDouble);
	cout << "multiply Doubles: " << od1.toDouble() << " * " << primitiveDouble << " = " << od2.toDouble() << endl << endl;

	//divide Doubles
	od2 = od1.div(primitiveDouble);
	cout << "divide Doubles: " << od1.toDouble() << " / " << primitiveDouble << " = " << od2.toDouble() << endl << endl;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	cout << "===========Overloaded Integer Functions===========" << endl;
	Integer oi1, oi2;
	//set Integers
	oi1.equals(11);
	int primitiveInt = 9;

	//add Integers
	oi2 = oi1.add(primitiveInt);
	cout << "add Integers: " << oi1.toInt() << " + " << primitiveInt << " = " << oi2.toInt() << endl << endl;

	//subtract Integers
	oi2 = oi1.sub(primitiveInt);
	cout << "subtract Integers: " << oi1.toInt() << " - " << primitiveInt << " = " << oi2.toInt() << endl << endl;

	//multiply Integers
	oi2 = oi1.mul(primitiveInt);
	cout << "multiply Integers: " << oi1.toInt() << " * " << primitiveInt << " = " << oi2.toInt() << endl << endl;

	//divide Integers
	oi2 = oi1.div(primitiveInt);
	cout << "divide Integers: " << oi1.toInt() << " / " << primitiveInt << " = " << oi2.toInt() << endl << endl;
}
