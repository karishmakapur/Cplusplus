/*
Karishma Kapur
CSIS 123A
ID: 0558326
11/11/18
Assignment 12 - Polymorphism
Integer.h file
Contains Integer class and prototypes for methods and constructors
*/
#pragma once
#ifndef INTEGER
#define INTEGER
#include <string>
#include "Number.h"

using std::string;

//Create a class called Integer. This class should have separate header and.cpp file
namespace Karishma {
	class Integer : public Number {
	private:
		//primitive integer data section
		//bool nan = NULL;

		//private functions
		//void isNaN(string s);
		virtual void recursiveNaN(string s);

	public:

		//Functions
		void equals(int num); //void function that sets the value of the object
		void equals(const string s);

		Integer& add(const Integer &i); //take Integer as an argument and return Integer
		Integer& sub(const Integer &i); //take Integer as an argument and return Integer
		Integer& mul(const Integer &i); //take Integer as an argument and return Integer
		Integer& div(const Integer &i); //take Integer as an argument and return Integer

		int toInt() const; //returns a primitive integer

		//Overloaded Functions
		Integer& add(const int &num); //should take primitive values and return the base class type
		Integer& sub(const int &num); //should take primitive values and return the base class type
		Integer& mul(const int &num); //should take primitive values and return the base class type
		Integer& div(const int &num); //should take primitive values and return the base class type

		//Default Constructor
		Integer();

		//Overloaded Constructor
		Integer(const Integer& i);
		Integer(int num);
		Integer(string s);

		//destructor
		~Integer();

		//Operator Overloading Functions for Integer Object taking a Integer Object argument
		Integer &operator + (const Integer &i);
		Integer &operator - (const Integer &i);
		Integer &operator * (const Integer &i);
		Integer &operator / (const Integer &i);
		Integer& operator = (const Integer &i);
		bool operator == (const Integer &i);
		bool operator != (const Integer &i);

		//Operator Overloading Functions for Integer Object taking a primitive integer argument
		Integer &operator + (const int &num);
		Integer &operator - (const int &num);
		Integer &operator * (const int &num);
		Integer &operator / (const int &num);
		Integer& operator = (const int &num);
		bool operator == (const int &num);
		bool operator != (const int &num);

		//Assignment 6 functions
		//string toString() const; //toString() - Returns a string representation of the number

		//bool isNaN();
		Integer& operator=(const string s);


		

	};
}
#endif
