/*
Karishma Kapur
CSIS 123A
ID: 0558326
8/24/18
Assignment 2: Class Construction
Double.cpp file 
Contains Implementation of Double class methods
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
