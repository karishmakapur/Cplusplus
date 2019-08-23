/*
Karishma Kapur
CSIS 123A
ID: 0558326
8/24/18
Assignment 2: Class Construction 
main.cpp file 
Instantiates Double Class and Integer Class along with testing the methods from each class
*/

#include <iostream>
#include "Double.h"
#include "Integer.h"
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
}