/*
Karishma Kapur
CSIS 123A
ID: 0558326
9/28/18
Assignment 7 Dynamic Memory
Integer.cpp file
Contains Implementation of Integer class methods and constructors
*/
#include "Integer.h"
#include <string>
#include <ctype.h> //for isdigit()

using std::string;

//Create a class called Integer. This class should have separate header and.cpp file



void Integer::equals(int num)
{
	*this->integerNum = num;
	*this->nan = false;

}

Integer& Integer::add(const Integer &i)
{

	Integer *tmp = new Integer;
	*(*tmp).integerNum = *this->integerNum + *i.integerNum;
	*(*tmp).nan = false;
	return *tmp;
}

Integer& Integer::sub(const Integer &i)
{
	Integer *tmp = new Integer;
	*(*tmp).integerNum = *this->integerNum - *i.integerNum;
	*(*tmp).nan = false;
	return *tmp;
}

Integer& Integer::mul(const Integer &i)
{
	Integer *tmp = new Integer;
	*(*tmp).integerNum = *this->integerNum * *i.integerNum;
	*(*tmp).nan = false;
	return *tmp;
}

Integer& Integer::div(const Integer &i)
{
	Integer *tmp = new Integer;
	*(*tmp).integerNum = *this->integerNum / *i.integerNum;
	*(*tmp).nan = false;
	return *tmp;
}

int Integer::toInt() const
{

	return *this->integerNum;
}

Integer& Integer::add(const int &num)
{
	Integer *tmp = new Integer;
	*(*tmp).integerNum = *this->integerNum + num;
	*(*tmp).nan = false;
	return *tmp;
}

Integer& Integer::sub(const int &num)
{
	Integer *tmp = new Integer;
	*(*tmp).integerNum = *this->integerNum - num;
	*(*tmp).nan = false;
	return *tmp;
}

Integer& Integer::mul(const int &num)
{
	Integer *tmp = new Integer;
	*(*tmp).integerNum = *this->integerNum * num;
	*(*tmp).nan = false;
	return *tmp;
}

Integer& Integer::div(const int &num)
{
	Integer *tmp = new Integer;
	*(*tmp).integerNum = *this->integerNum / num;
	*(*tmp).nan = false;
	return *tmp;
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
	for (int i = 0; i < s.length(); i++) {
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
	this->integerNum = new int;
	this->nan = new bool;
}
