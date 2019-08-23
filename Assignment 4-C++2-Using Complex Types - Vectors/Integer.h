/*
Karishma Kapur
CSIS 123A
ID: 0558326
9/12/18
Assignment 5 Operator Overloading
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
	Integer& add(const Integer &i); //take Integer as an argument and return Integer
	Integer& sub(const Integer &i); //take Integer as an argument and return Integer
	Integer& mul(const Integer &i); //take Integer as an argument and return Integer
	Integer& div(const Integer &i); //take Integer as an argument and return Integer
	int toInt(); //returns a primitive integer

	//Overloaded Functions
	Integer& add(const int &num); //should take primitive values and return the base class type
	Integer& sub(const int &num); //should take primitive values and return the base class type
	Integer& mul(const int &num); //should take primitive values and return the base class type
	Integer& div(const int &num); //should take primitive values and return the base class type

	//Default Constructor
	Integer();

	//Overloaded Constructor
	Integer(Integer& i);
	Integer(int num);

	//Operator Overloading Functions for Integer Object taking a Integer Object argument
	Integer &operator + (const Integer &i);
	Integer &operator - (const Integer &i);
	Integer &operator * (const Integer &i);
	Integer &operator / (const Integer &i);
	void operator = (const Integer &i);
	bool operator == (const Integer &i);
	bool operator != (const Integer &i);

	//Operator Overloading Functions for Integer Object taking a primitive integer argument
	Integer &operator + (const int &num);
	Integer &operator - (const int &num);
	Integer &operator * (const int &num);
	Integer &operator / (const int &num);
	void operator = (const int &num);
	bool operator == (const int &num);
	bool operator != (const int &num);
};
#endif
