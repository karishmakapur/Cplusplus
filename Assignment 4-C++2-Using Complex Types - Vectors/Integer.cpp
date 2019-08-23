/*
Karishma Kapur
CSIS 123A
ID: 0558326
9/12/18
Assignment 5 Operator Overloading
Integer.cpp file
Contains Implementation of Integer class methods and constructors
*/
#include "Integer.h"

//Create a class called Integer. This class should have separate header and.cpp file

void Integer::equals(int num)
{
	this->integerNum = num;

}

Integer& Integer::add(const Integer &i)
{
	
	Integer tmp;
	tmp.integerNum = this->integerNum + i.integerNum;
	return tmp;
}

Integer& Integer::sub(const Integer &i)
{
	Integer tmp;
	tmp.integerNum = this->integerNum - i.integerNum;
	return tmp;
}

Integer& Integer::mul(const Integer &i)
{
	Integer tmp;
	tmp.integerNum = this->integerNum * i.integerNum;
	return tmp;
}

Integer& Integer::div(const Integer &i)
{
	Integer tmp;
	tmp.integerNum = this->integerNum / i.integerNum;
	return tmp;
}

int Integer::toInt()
{

	return this->integerNum;
}

Integer& Integer::add(const int &num)
{
	Integer tmp;
	tmp.integerNum = this->integerNum + num;
	return tmp;
}

Integer& Integer::sub(const int &num)
{
	Integer tmp;
	tmp.integerNum = this->integerNum - num;
	return tmp;
}

Integer& Integer::mul(const int &num)
{
	Integer tmp;
	tmp.integerNum = this->integerNum * num;
	return tmp;
}

Integer& Integer::div(const int &num)
{
	Integer tmp;
	tmp.integerNum = this->integerNum / num;
	return tmp;
}

//Default Constructor
Integer::Integer()
{
	this->equals(0);
}

//Overloaded Constructor
Integer::Integer(Integer& i)
{
	this->equals(i.toInt());
}

//Overloaded Constructor
Integer::Integer(int num)
{
	this->equals(num);
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
void Integer::operator=(const Integer & i)
{
	this->equals(i.integerNum);
}

//operator == overloading for Integer Object taking a Integer Object argument
bool Integer::operator==(const Integer & i)
{
	return (this->toInt() == i.integerNum);
}

//operator != overloading for Integer Object taking a Integer Object argument
bool Integer::operator!=(const Integer & i)
{
	return (this->toInt() != i.integerNum);
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
void Integer::operator=(const int & num)
{
	this->equals(num);
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

