/*
Karishma Kapur
CSIS 123A
ID: 0558326
9/12/18
Assignment 5 Operator Overloading
Double.h file
Contains Double class and prototypes for methods and constructors
*/
#pragma once
#ifndef DOUBLE
#define DOUBLE
#include "Integer.h"

//Create a class called Double. This class should have separate header and.cpp file
class Double {
private:
	//primitive double data section
	double doubleNum;
public:
	//Functions
	void equals(const double num); //void function that sets the value of the object
	Double& add(const Double &d); //take Double as an argument and return Double
	Double& sub(const Double &d); //take Double as an argument and return Double
	Double& mul(const Double &d); //take Double as an argument and return Double
	Double& div(const Double &d); //take Double as an argument and return Double
	double toDouble(); //return a primitive double

	//Overloaded Functions
	Double& add(const double &num); //should take primitive values and return the base class type
	Double& sub(const double &num); //should take primitive values and return the base class type
	Double& mul(const double &num); //should take primitive values and return the base class type
	Double& div(const double &num); //should take primitive values and return the base class type

	//Operator Overloading Functions for Double Object taking a Double object argument
	Double& operator + (const Double &d);
	Double& operator - (const Double &d);
	Double& operator * (const Double &d);
	Double& operator / (const Double &d);
	void operator = (const Double &d);
	bool operator == (const Double &d);
	bool operator != (const Double &d);

	//Operator Overloading Functions for Double Object taking a primitive double argument.
	Double& operator + (const double &num);
	Double& operator - (const double &num);
	Double& operator * (const double &num);
	Double& operator / (const double &num);
	void operator = (const double &num);
	bool operator == (const double &num);
	bool operator != (const double &num);
	

	//Constructor
	Double();
	
	//Overloaded Constructors
	Double(Double& d);
	Double(double num);
	Double(Integer& i);
};
#endif
