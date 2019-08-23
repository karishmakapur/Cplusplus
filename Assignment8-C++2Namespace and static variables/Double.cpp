/*
Karishma Kapur
CSIS 123A
ID: 0558326
10/4/18
Assignment 8 Namespace and Static Variables
Double.cpp file
Contains Implementation of Double class methods and constructors
*/
#include "Double.h"
#include <string>
#include <ctype.h> //for isdigit()
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::bad_alloc;

//Create a class called Double. This class should have separate header and.cpp file
namespace Karishma {


	void Double::equals(const double num)
	{
		*this->doubleNum = num;
		*this->nan = false;

	}

	Double &Double::add(const Double &d)
	{
		try {
			Double *tmp = new Double;
			*tmp->doubleNum = *this->doubleNum + *d.doubleNum;
			*tmp->nan = false;
			return *tmp;
		}
		catch (const bad_alloc& e) {
			cout << "Double add - cannot create return object. " << e.what() << endl;
			exit(EXIT_FAILURE);
		}
		
	}

	Double &Double::sub(const Double &d)
	{
		try {
		Double *tmp = new Double;
		*tmp->doubleNum = *this->doubleNum - *d.doubleNum;
		*tmp->nan = false;
		return *tmp;
		}
		catch (const bad_alloc& e) {
			cout << "Double sub - cannot create return object. " << e.what() << endl;
			exit(EXIT_FAILURE);
		}
		
		
		
	}

	Double &Double::mul(const Double &d)
	{
		try {
			Double *tmp = new Double;
			*tmp->doubleNum = *this->doubleNum * *d.doubleNum;
			*tmp->nan = false;
			return *tmp;
		}
		catch (const bad_alloc& e) {
			cout << "Double mul - cannot create return object. " << e.what() << endl;
			exit(EXIT_FAILURE);
		}
		
	}

	Double &Double::div(const Double &d)
	{
		try {
			Double *tmp = new Double;
			*tmp->doubleNum = *this->doubleNum / *d.doubleNum;
			*tmp->nan = false;
			return *tmp;
		}
		catch (const bad_alloc& e) {
			cout << "Double div - cannot create return object. " << e.what() << endl;
			exit(EXIT_FAILURE);
		}
		
	}

	double Double::toDouble() const
	{
		return *this->doubleNum;
	}

	Double& Double::add(const double &num)
	{
		try {
			Double *tmp = new Double;
			*tmp->doubleNum = *this->doubleNum + num;
			*tmp->nan = false;
			return *tmp;
		}
		catch (const bad_alloc& e) {
			cout << "double add - cannot create return object. " << e.what() << endl;
			exit(EXIT_FAILURE);
		}
		
	}

	Double& Double::sub(const double &num)
	{
		try {
			Double *tmp = new Double;
			*tmp->doubleNum = *this->doubleNum - num;
			*tmp->nan = false;
		return *tmp;
		}
		catch (const bad_alloc& e) {
			cout << "double sub - cannot create return object. " << e.what() << endl;
			exit(EXIT_FAILURE);
		}
		
	}

	Double& Double::mul(const double &num)
	{
		try {
			Double *tmp = new Double;
			*tmp->doubleNum = *this->doubleNum * num;
			*tmp->nan = false;
			return *tmp;
		}
		catch (const bad_alloc& e) {
			cout << "double mul - cannot create return object. " << e.what() << endl;
			exit(EXIT_FAILURE);
		}
		
		
	}

	Double& Double::div(const double &num)
	{
		try {
			Double *tmp = new Double;
			*tmp->doubleNum = *this->doubleNum / num;
			*tmp->nan = false;
			return *tmp;
		}
		catch (const bad_alloc& e) {
			cout << "double div - cannot create return object. " << e.what() << endl;
			exit(EXIT_FAILURE);
		}
		
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
	Double& Double::operator=(const Double & d)
	{
		this->equals(*d.doubleNum);
		return *this;
	}

	//operator == overloading for Double Object taking a Double object argument
	bool Double::operator==(const Double & d)
	{
		return (this->toDouble() == *d.doubleNum);
	}

	//operator != overloading for Double Object taking a Double object argument
	bool Double::operator!=(const Double & d)
	{
		return (this->toDouble() != *d.doubleNum);
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
	Double& Double::operator=(const double & num)
	{
		this->equals(num);
		return *this;
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
		this->create();
		this->equals(0.0);

	}

	//Overloaded Constructor
	Double::Double(const Double& d)
	{
		this->create();
		this->equals(d.toDouble());
	}

	//Overloaded Constructor
	Double::Double(double num)
	{
		this->create();
		this->equals(num);
	}

	//Overloaded Constructor
	Double::Double(Integer& i)
	{
		this->create();
		this->equals(i.toInt());
	}

	Double::~Double()
	{
		//std::cout << "In double deconstructor" << std::endl;
		delete this->doubleNum;
		delete this->nan;
	}

	//Assignment 6 Functions
	string Double::toString()
	{
		return std::to_string(*this->doubleNum);
	}

	void Double::equals(const string s)
	{
		isNaN(s); //checking to see if the number is valid & setting the nan bool variable.
		if (*this->nan == false) {
			*this->doubleNum = stod(s);
		}
		else
		{
			*this->doubleNum = 0.0;
		}
	}

	bool Double::isNaN()
	{
		return *this->nan;
	}

	Double& Double::operator=(const string s)
	{
		this->equals(s);
		return *this;
	}

	Double::Double(string s)
	{
		this->create();
		this->equals(s);
	}

	void Double::isNaN(string s)
	{
		int decPtCounter = 0;
		bool notAnum = false;
		//looping through string to validate that it is a double number.
		for (int i = 0; i < (int)s.length(); i++) {
			if (s[i] == '.') {
				decPtCounter++;
				if (decPtCounter > 1) {
					notAnum = true; //not a number
					break;
				}
			}
			else if (!isdigit(s[i]))
			{
				notAnum = true; //not a number
				break;
			}
		}
		*this->nan = notAnum;
	}

	//memory allocation for doubleNum and nan
	void Double::create()
	{
		try {
			this->doubleNum = new double;
			this->nan = new bool;
		}
		catch(const bad_alloc& e){

			cout << "Error allocating memory - doubleNum or nan from Double class " << e.what() << endl;
			exit(EXIT_FAILURE);
		}
		
	}
}
