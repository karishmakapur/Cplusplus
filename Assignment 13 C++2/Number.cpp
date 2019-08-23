/*
Karishma Kapur
CSIS 123A
ID: 0558326
11/17/18
Assignment 13 - Exceptions
Number.cpp file
Contains Implementation of Number and NumberException class methods and constructors
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
	NumberException::NumberException(string s)
	{
		this->errorMessage = s;
		this->errorCode = -1;
	}
	NumberException::NumberException(string s, int num)
	{
		this->errorCode = num;
		this->errorMessage = s;
	}
	string NumberException::getMessage()
	{
		return this->errorMessage;
	}
	int NumberException::getCode()
	{
		return this->errorCode;
	}
}