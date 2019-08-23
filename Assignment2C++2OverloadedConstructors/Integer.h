/*
Karishma Kapur
CSIS 123A
ID: 0558326
8/30/18
Assignment 3: Overloaded Constructors
Integer.h file
Contains Integer class and prototypes for methods and constructors
*/
#pragma once
#ifndef INTEGER
#define INTEGER

//Create a class called Integer. This class should have separate header and.cpp file
class Integer {
private:
	//primitive integer data section
	int integerNum;
public:
	//Functions
	void equals(int num); //void function that sets the value of the object
	Integer add(Integer i); //take Integer as an argument and return Integer
	Integer sub(Integer i); //take Integer as an argument and return Integer
	Integer mul(Integer i); //take Integer as an argument and return Integer
	Integer div(Integer i); //take Integer as an argument and return Integer
	int toInt(); //returns a primitive integer

	//Overloaded Functions
	Integer add(int num); //should take primitive values and return the base class type
	Integer sub(int num); //should take primitive values and return the base class type
	Integer mul(int num); //should take primitive values and return the base class type
	Integer div(int num); //should take primitive values and return the base class type

	//Default Constructor
	Integer();

	//Overloaded Constructor
	Integer(Integer& i);
	Integer(int num);
};
#endif
