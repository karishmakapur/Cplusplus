/*
Karishma Kapur
CSIS 123A
ID: 0558326
10/8/18
Midterm
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

	void Integer::isNaN(string s)
	{
		int decPtCounter = 0;
		bool notAnum = false;
		//looping through string to validate that it is an integer number.
		for (int i = 0; i < (int)s.length(); i++) {
			if (!isdigit(s[i]))
			{
				notAnum = true; //not a number
				break;
			}
		}
		*this->nan = notAnum;
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