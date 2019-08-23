/*
Karishma Kapur
CSIS 123A
ID: 0558326
8/24/18
Assignment 2: Class Construction
Integer.cpp file 
Contains Implementation of Integer class methods 
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
