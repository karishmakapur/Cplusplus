/*
Karishma Kapur
CSIS 123A
ID: 0558326
8/30/18
Assignment 3: Overloaded Constructors
Integer.cpp file
Contains Implementation of Integer class methods and constructors
*/
#include "Integer.h"
//Create a class called Integer. This class should have separate header and.cpp file

void Integer::equals(int num)
{
	this->integerNum = num;

}

Integer Integer::add(Integer i)
{
	Integer tmp;
	tmp.integerNum = this->integerNum + i.integerNum;
	return tmp;
}

Integer Integer::sub(Integer i)
{
	Integer tmp;
	tmp.integerNum = this->integerNum - i.integerNum;
	return tmp;
}

Integer Integer::mul(Integer i)
{
	Integer tmp;
	tmp.integerNum = this->integerNum * i.integerNum;
	return tmp;
}

Integer Integer::div(Integer i)
{
	Integer tmp;
	tmp.integerNum = this->integerNum / i.integerNum;
	return tmp;
}

int Integer::toInt()
{

	return this->integerNum;
}

Integer Integer::add(int num)
{
	return (this->integerNum + num);
}

Integer Integer::sub(int num)
{
	return (this->integerNum - num);
}

Integer Integer::mul(int num)
{
	return (this->integerNum * num);
}

Integer Integer::div(int num)
{
	return (this->integerNum / num);
}

Integer::Integer()
{
	this->equals(0);
}

Integer::Integer(Integer& i)
{
	this->equals(i.toInt());
}

Integer::Integer(int num)
{
	this->equals(num);
}

