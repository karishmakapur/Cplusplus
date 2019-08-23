/*
Karishma Kapur
CSIS 123A
ID: 0558326
10/23/18
Assignment 10 Recursion
Double.h file
Contains Double class and prototypes for methods and constructors
*/
#pragma once
#ifndef DOUBLE
#define DOUBLE
#include "Integer.h"
#include <string>

using std::string;

//Create a class called Double. This class should have separate header and.cpp file
namespace Karishma {
	class Double {
	private:
		//primitive double data section
		double *doubleNum = NULL;
		bool *nan = NULL;

		//private functions
		void isNaN(string s);
		void recursiveNaN(string s);

		//memory allocation for doubleNum and nan
		void create();

	public:
		//Functions
		void equals(const double num); //void function that sets the value of the object
		Double& add(const Double &d); //take Double as an argument and return Double
		Double& sub(const Double &d); //take Double as an argument and return Double
		Double& mul(const Double &d); //take Double as an argument and return Double
		Double& div(const Double &d); //take Double as an argument and return Double
		double toDouble() const; //return a primitive double

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
		Double& operator = (const Double &d);
		bool operator == (const Double &d);
		bool operator != (const Double &d);

		//Operator Overloading Functions for Double Object taking a primitive double argument.
		Double& operator + (const double &num);
		Double& operator - (const double &num);
		Double& operator * (const double &num);
		Double& operator / (const double &num);
		Double& operator = (const double &num);
		bool operator == (const double &num);
		bool operator != (const double &num);


		//Constructor
		Double();

		//Overloaded Constructors
		Double(const Double& d);
		Double(double num);
		Double(Integer& i);

		//deconstructor
		~Double();

		//Assignment 6 functions
		string toString(); //toString() - Returns a string representation of the number
		void equals(const string s);
		bool isNaN();
		Double& operator=(const string s);
		Double(string s);

		void assignment10PrintFunc(string s);
	};
}
#endif
