/*
Karishma Kapur
CSIS 123A
ID: 0558326
8/30/18
Assignment 3: Overloaded Constructors
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
	void equals(double num); //void function that sets the value of the object
	Double add(Double d); //take Double as an argument and return Double
	Double sub(Double d); //take Double as an argument and return Double
	Double mul(Double d); //take Double as an argument and return Double
	Double div(Double d); //take Double as an argument and return Double
	double toDouble(); //return a primitive double

	//Overloaded Functions
	Double add(double num); //should take primitive values and return the base class type
	Double sub(double num); //should take primitive values and return the base class type
	Double mul(double num); //should take primitive values and return the base class type
	Double div(double num); //should take primitive values and return the base class type

	//Constructor
	Double();
	
	//Overloaded Constructors
	Double(Double& d);
	Double(double num);
	Double(Integer& i);
};
#endif
