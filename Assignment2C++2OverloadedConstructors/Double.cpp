/*
Karishma Kapur
CSIS 123A
ID: 0558326
8/30/18
Assignment 3: Overloaded Constructors
Double.cpp file
Contains Implementation of Double class methods and constructors
*/
#include "Double.h"


//Create a class called Double. This class should have separate header and.cpp file

void Double::equals(double num)
{
	this->doubleNum = num;

}

Double Double::add(Double d)
{
	Double tmp;
	tmp.doubleNum = this->doubleNum + d.doubleNum;
	return tmp;
}

Double Double::sub(Double d)
{
	Double tmp;
	tmp.doubleNum = this->doubleNum - d.doubleNum;
	return tmp;
}

Double Double::mul(Double d)
{
	Double tmp;
	tmp.doubleNum = this->doubleNum * d.doubleNum;
	return tmp;
}

Double Double::div(Double d)
{
	Double tmp;
	tmp.doubleNum = this->doubleNum / d.doubleNum;
	return tmp;
}

double Double::toDouble()
{
	return this->doubleNum;
}

Double Double::add(double num)
{
	return (this->doubleNum + num);
}

Double Double::sub(double num)
{
	return (this->doubleNum - num);
}

Double Double::mul(double num)
{
	return (this->doubleNum * num);
}

Double Double::div(double num)
{
	return (this->doubleNum / num);
}

Double::Double()
{
	this->equals(0.0);
}

Double::Double(Double& d)
{
	this->equals(d.toDouble());
}

Double::Double(double num)
{
	this->equals(num);
}

Double::Double(Integer& i)
{
	this->equals(i.toInt());
}
