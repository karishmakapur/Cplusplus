/*
Karishma Kapur
CSIS 123A
ID: 0558326
8/24/18
Assignment 2: Class Construction
Integer.h file 
Contains Integer class and prototypes for methods
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
	void equals(int num); //void function that sets the value of the object
	Integer add(Integer i); //take Integer as an argument and return Integer
	Integer sub(Integer i); //take Integer as an argument and return Integer
	Integer mul(Integer i); //take Integer as an argument and return Integer
	Integer div(Integer i); //take Integer as an argument and return Integer
	int toInt(); //returns a primitive integer
};
#endif
