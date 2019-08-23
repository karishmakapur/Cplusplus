/*
Karishma Kapur
CSIS 123A
ID: 0558326
11/11/18
Assignment 12 - Polymorphism
Number.cpp file
Contains Implementation of Number class methods and constructors
*/
#include "Number.h"
#include <iostream>
#include <typeinfo>
#include <string>

using std::string;

namespace Karishma {
	Number::Number()
		: string("0")
	{

	}
	Number::Number(string s)
		: string(s)
	{

	}
	string Number::toString() const
	{
		return this->data();
	}
	bool Number::isNaN()
	{
		return this->nan;
	}
	void Number::isNaN(string s)
	{
		recursiveNaN(s);
	}
}