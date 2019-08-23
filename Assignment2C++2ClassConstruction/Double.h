/*
Karishma Kapur
CSIS 123A
ID: 0558326
8/24/18
Assignment 2: Class Construction
Double.h file 
Contains Double class and prototypes for methods
*/
#pragma once
#ifndef DOUBLE
#define DOUBLE

//Create a class called Double. This class should have separate header and.cpp file
class Double {
private:
	//primitive double data section
	double doubleNum;
public:
	void equals(double num); //void function that sets the value of the object
	Double add(Double d); //take Double as an argument and return Double
	Double sub(Double d); //take Double as an argument and return Double
	Double mul(Double d); //take Double as an argument and return Double
	Double div(Double d); //take Double as an argument and return Double
	double toDouble(); //return a primitive double
};
#endif
