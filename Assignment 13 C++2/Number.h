/*
Karishma Kapur
CSIS 123A
ID: 0558326
11/17/18
Assignment 13 - Exceptions
Number.h file
Contains Number and NumberException class and prototypes for methods and constructors.
*/
#pragma once
#ifndef NUMBER
#define NUMBER

#include <string>
#include <exception>
using std::string;
using std::exception;

namespace Karishma {
	class Number : public string {
	protected:
		bool nan = NULL;

	public:
		//public member functions
		//A no argument constructor that sets the data section to "0"
		Number();

		//An overloaded constructor that takes a string and sets the data section to the value being passed to it.
		Number(string s);

		virtual string toString() const;
		bool isNaN();
		void isNaN(string s);
		virtual void recursiveNaN(string s) = 0;
	};
	class NumberException : public exception {
	private:
		int errorCode;
		string errorMessage;
	public:
		NumberException() : errorCode(-1), errorMessage("Unknown") {}
		NumberException(string s);
		NumberException(string s, int num);

		string getMessage();
		int getCode();

	};
}
#endif