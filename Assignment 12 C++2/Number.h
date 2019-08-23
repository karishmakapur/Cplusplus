/*
Karishma Kapur
CSIS 123A
ID: 0558326
11/11/18
Assignment 12 - Polymorphism
Number.h file
Contains Number class and prototypes for methods and constructors
*/
#pragma once
#ifndef NUMBER
#define NUMBER

#include <string>
using std::string;

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
}
#endif