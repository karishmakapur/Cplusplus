/*
Karishma Kapur
CSIS 123A
ID: 0558326
10/23/18
Assignment 10 Recursion
Integer.cpp file
Contains Implementation of Integer class methods and constructors
*/
#include "Integer.h"
#include <string>
#include <ctype.h> //for isdigit()
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::bad_alloc;
using std::boolalpha;

//Create a class called Integer. This class should have separate header and.cpp file

namespace Karishma {

	void Integer::equals(int num)
	{
		*this->integerNum = num;
		*this->nan = false;

	}

	Integer& Integer::add(const Integer &i)
	{
		try {
			Integer *tmp = new Integer;
			*tmp->integerNum = *this->integerNum + *i.integerNum;
			*tmp->nan = false;
			return *tmp;
		}
		catch (const bad_alloc& e) {
			cout << "Integer add - cannot create return object " << e.what() << endl;
			exit(EXIT_FAILURE);
		}


	}

	Integer& Integer::sub(const Integer &i)
	{
		try {
			Integer *tmp = new Integer;
			*tmp->integerNum = *this->integerNum - *i.integerNum;
			*tmp->nan = false;
			return *tmp;
		}
		catch (const bad_alloc& e) {
			cout << "Integer sub - cannot create return object " << e.what() << endl;
			exit(EXIT_FAILURE);
		}

	}

	Integer& Integer::mul(const Integer &i)
	{
		try {
			Integer *tmp = new Integer;
			*tmp->integerNum = *this->integerNum * *i.integerNum;
			*tmp->nan = false;
			return *tmp;
		}
		catch (const bad_alloc& e) {
			cout << "Integer mul - cannot create return object. " << e.what() << endl;
			exit(EXIT_FAILURE);
		}
	}

	Integer& Integer::div(const Integer &i)
	{
		try {
			Integer *tmp = new Integer;
			*tmp->integerNum = *this->integerNum / *i.integerNum;
			*tmp->nan = false;
			return *tmp;
		}
		catch (const bad_alloc& e) {
			cout << "Integer div - cannot create return object. " << e.what() << endl;
			exit(EXIT_FAILURE);
		}
	}

	int Integer::toInt() const
	{

		return *this->integerNum;
	}

	Integer& Integer::add(const int &num)
	{
		try {
			Integer *tmp = new Integer;
			*tmp->integerNum = *this->integerNum + num;
			*tmp->nan = false;
			return *tmp;
		}
		catch (const bad_alloc& e) {
			cout << "int add - cannot create return object. " << e.what() << endl;
			exit(EXIT_FAILURE);
		}

	}

	Integer& Integer::sub(const int &num)
	{
		try {
			Integer *tmp = new Integer;
			*tmp->integerNum = *this->integerNum - num;
			*tmp->nan = false;
			return *tmp;
		}
		catch (const bad_alloc& e) {
			cout << "int sub - cannot create return object. " << e.what() << endl;
			exit(EXIT_FAILURE);
		}
	}

	Integer& Integer::mul(const int &num)
	{
		try {
			Integer *tmp = new Integer;
			*tmp->integerNum = *this->integerNum * num;
			*tmp->nan = false;
			return *tmp;
		}
		catch (const bad_alloc& e) {
			cout << "int mul - cannot create return object. " << e.what() << endl;
			exit(EXIT_FAILURE);
		}
	}

	Integer& Integer::div(const int &num)
	{
		try {
			Integer *tmp = new Integer;
			*tmp->integerNum = *this->integerNum / num;
			*tmp->nan = false;
			return *tmp;
		}
		catch (const bad_alloc& e) {
			cout << "int div - cannot create return object. " << e.what() << endl;
			exit(EXIT_FAILURE);
		}

	}

	//Default Constructor
	Integer::Integer()
	{
		this->create();
		this->equals(0);
	}

	//Overloaded Constructor
	Integer::Integer(const Integer& i)
	{
		this->create();
		this->equals(i.toInt());
	}

	//Overloaded Constructor
	Integer::Integer(int num)
	{
		this->create();
		this->equals(num);
	}

	//destructor
	Integer::~Integer()
	{
		//std::cout << "In destructor" << std::endl;
		delete this->integerNum;
		delete this->nan;
	}

	//Operator Overloading Functions for Integer Object taking a Integer Object argument

	//operator + overloading for Integer Object taking a Integer Object argument
	Integer & Integer::operator+(const Integer & i)
	{
		return this->add(i);
	}

	//operator - overloading for Integer Object taking a Integer Object argument
	Integer & Integer::operator-(const Integer & i)
	{
		return this->sub(i);
	}

	//operator * overloading for Integer Object taking a Integer Object argument
	Integer & Integer::operator*(const Integer & i)
	{
		return this->mul(i);
	}

	//operator / overloading for Integer Object taking a Integer Object argument
	Integer & Integer::operator/(const Integer & i)
	{
		return this->div(i);
	}

	//operator = overloading for Integer Object taking a Integer Object argument
	Integer& Integer::operator=(const Integer & i)
	{
		this->equals(*i.integerNum);
		return *this;
	}

	//operator == overloading for Integer Object taking a Integer Object argument
	bool Integer::operator==(const Integer & i)
	{
		return (this->toInt() == *i.integerNum);
	}

	//operator != overloading for Integer Object taking a Integer Object argument
	bool Integer::operator!=(const Integer & i)
	{
		return (this->toInt() != *i.integerNum);
	}




	//Operator Overloading Functions for Integer Object taking a primitive integer argument
	//Operator + Overloading for Integer Object taking a primitive integer argument
	Integer & Integer::operator+(const int & num)
	{
		return this->add(num);
	}

	//Operator - Overloading for Integer Object taking a primitive integer argument
	Integer & Integer::operator-(const int & num)
	{
		return this->sub(num);
	}

	//Operator * Overloading for Integer Object taking a primitive integer argument
	Integer & Integer::operator*(const int & num)
	{
		return this->mul(num);
	}

	//Operator / Overloading for Integer Object taking a primitive integer argument
	Integer & Integer::operator/(const int & num)
	{
		return this->div(num);
	}

	//Operator = Overloading for Integer Object taking a primitive integer argument
	Integer& Integer::operator=(const int & num)
	{
		this->equals(num);
		return *this;
	}

	//Operator == Overloading for Integer Object taking a primitive integer argument
	bool Integer::operator==(const int & num)
	{
		return (this->toInt() == num);
	}

	//Operator != Overloading for Integer Object taking a primitive integer argument
	bool Integer::operator!=(const int & num)
	{
		return (this->toInt() != num);
	}

	//Assignment 6 Functions
	string Integer::toString()
	{
		return std::to_string(*this->integerNum);
	}

	void Integer::equals(const string s)
	{
		isNaN(s); //checking to see if the number is valid & setting the nan bool variable.
		if (*this->nan == false) {
			*this->integerNum = stoi(s);
		}
		else
		{
			*this->integerNum = 0;
		}
	}

	bool Integer::isNaN()
	{
		return *this->nan;
	}

	Integer & Integer::operator=(const string s)
	{
		this->equals(s);
		return *this;
	}

	Integer::Integer(string s)
	{
		this->create();
		this->equals(s);
	}

	void Integer::assignment10PrintFunc(string s)
	{
		//this print function solely created so I can print private nan variable.
		cout << "string = " << "\"" << s << "\"";
		cout << boolalpha;
		cout << "  Integer->nan = " << *this->nan << "   " << "i.integerNum = " << *this->integerNum << endl;
	}

	void Integer::isNaN(string s)
	{
		recursiveNaN(s);
		
	}

	void Integer::recursiveNaN(string s)
	{
		//to start with, we consider the string is a valid integer.
		//we made it static so that the recursiveness we can retain any changes to the nanFlag. 
		static bool nanFlag = false;
		if (((isdigit(s.at(0))) && (nanFlag == false)) && (s.length() > 1))		//if there is a digit and nanFlag is false and there is more to the string after
		{
			//calling recursive with a string from index 1 to end.
			recursiveNaN(s.substr(1));
		
		}
		if (!isdigit(s.at(0)))
		{
			nanFlag = true; //if it is not a digit set the flag to true
		}

		if (nanFlag == true || s.length() == 1) {							//if nanFlag is true or the string length is 1.
			*this->nan = nanFlag;
			nanFlag = false; //reset the flag to false since it is static
		}
		
	}

	//memory allocation for integerNum and nan
	void Integer::create()
	{

		try {
			this->integerNum = new int;
			this->nan = new bool;
		}
		catch (const bad_alloc& e) {
			cout << "Error allocating memory - integerNum or nan from Integer class " << e.what() << endl;
			exit(EXIT_FAILURE);
		}
	}
}