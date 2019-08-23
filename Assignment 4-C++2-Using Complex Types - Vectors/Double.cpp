/*
Karishma Kapur
CSIS 123A
ID: 0558326
9/12/18
Assignment 5 Operator Overloading
Double.cpp file
Contains Implementation of Double class methods and constructors
*/
#include "Double.h"


//Create a class called Double. This class should have separate header and.cpp file

void Double::equals(const double num)
{
	this->doubleNum = num;

}

Double &Double::add(const Double &d)
{
	Double tmp;
	tmp.doubleNum = this->doubleNum + d.doubleNum;
	return tmp;
}

Double &Double::sub(const Double &d)
{

	Double tmp;
	tmp.doubleNum = this->doubleNum - d.doubleNum;
	return tmp;
}

Double &Double::mul(const Double &d)
{

	Double tmp;
	tmp.doubleNum = this->doubleNum * d.doubleNum;
	return tmp;
}

Double &Double::div(const Double &d)
{

	Double tmp;
	tmp.doubleNum = this->doubleNum / d.doubleNum;
	return tmp;
}

double Double::toDouble()
{
	return this->doubleNum;
}

Double& Double::add(const double &num)
{

	Double tmp;
	tmp.doubleNum = this->doubleNum + num;
	return tmp;
}

Double& Double::sub(const double &num)
{

	Double tmp;
	tmp.doubleNum = this->doubleNum - num;
	return tmp;
}

Double& Double::mul(const double &num)
{

	Double tmp;
	tmp.doubleNum = this->doubleNum * num;
	return tmp;
}

Double& Double::div(const double &num)
{

	Double tmp;
	tmp.doubleNum = this->doubleNum / num;
	return tmp;
}

//Operator Overloading Functions for Double Object taking a Double object argument

//operator + overloading for Double Object taking a Double object argument
Double &Double::operator+(const Double &d) 
{

	return this->add(d);
}

//operator - overloading for Double Object taking a Double object argument
Double& Double::operator-(const Double & d)
{

	return this->sub(d);
}

//operator * overloading for Double Object taking a Double object argument
Double & Double::operator*(const Double & d)
{

	return this->mul(d);
}

//operator / overloading for Double Object taking a Double object argument
Double & Double::operator/(const Double & d)
{

	return this->div(d);
}

//operator = overloading for Double Object taking a Double object argument
void Double::operator=(const Double & d)
{
	this->equals(d.doubleNum);
}

//operator == overloading for Double Object taking a Double object argument
bool Double::operator==(const Double & d)
{
	return (this->toDouble() == d.doubleNum);
}

//operator != overloading for Double Object taking a Double object argument
bool Double::operator!=(const Double & d)
{
	return (this->toDouble() != d.doubleNum);
}

//Operator Overloading Functions for Double Object taking a primitive double argument.

//operator + overloading for Double Object taking a primitive double argument.
Double &Double::operator+(const double & num)
{

	return this->add(num);
}

//operator - overloading for Double Object taking a primitive double argument.
Double & Double::operator-(const double & num)
{

	return this->sub(num);
}

//operator * overloading for Double Object taking a primitive double argument.
Double & Double::operator*(const double & num)
{

	return this->mul(num);
}

//operator / overloading for Double Object taking a primitive double argument.
Double & Double::operator/(const double & num)
{

	return this->div(num);
}

//operator = overloading for Double Object taking a primitive double argument.
void Double::operator=(const double & num)
{
	this->equals(num);
}

//operator == overloading for Double Object taking a primitive double argument.
bool Double::operator==(const double & num)
{
	return (this->toDouble() == num);
}

//operator != overloading for Double Object taking a primitive double argument.
bool Double::operator!=(const double & num)
{
	return (this->toDouble() != num);
}

//Default Constructor
Double::Double()
{
	this->equals(0.0);
}

//Overloaded Constructor
Double::Double(Double& d)
{
	this->equals(d.toDouble());
}

//Overloaded Constructor
Double::Double(double num)
{
	this->equals(num);
}

//Overloaded Constructor
Double::Double(Integer& i)
{
	this->equals(i.toInt());
}