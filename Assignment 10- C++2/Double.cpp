/*
Karishma Kapur
CSIS 123A
ID: 0558326
10/23/18
Assignment 10 Recursion
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
using std::boolalpha;

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

	void Double::assignment10PrintFunc(string s)
	{
		//this print function solely created so I can print private nan variable.
		cout << "string = " << "\"" << s << "\"";
		cout << boolalpha;
		cout << "  Double->nan = " << *this->nan << "   " << "d.doubleNum = " << *this->doubleNum << endl;
	}

	void Double::isNaN(string s)
	{
		recursiveNaN(s);
		
		
	}
	void Double::recursiveNaN(string s) {
		//to start with, we consider the string is a valid double.
		// we made it static so that the recursiveness we can retain any changes to the nanFlag and decPtCounter.
		static int decPtCounter = 0;
		static bool nanFlag = false;

		//check for decimal point
		//first increment the decimal point counter 
		//check for not a '.' and not a valid digit.
		if ((nanFlag == false) &&									//only execute if nanFlag is false
			(((s.at(0) != '.') && (!isdigit(s.at(0)))) ||			//if there is not a '.' and not a digit
			((s.at(0) == '.') && (++decPtCounter > 1))))			//if there is a '.' but there is more than one '.' I have preincrement operator in condition
		{
			nanFlag = true;
		}

		//check for valid digit and decPtCounter is <= 1.
		if ((nanFlag == false) &&									//only execute if nanFlag is false
			(isdigit(s.at(0)) || (decPtCounter <= 1)) &&			//if there is a digit or there is less than 1 '.'
			(s.length() > 1)) {										//there is more to the string after
			//calling recursive with a string from index 1 to end.
			recursiveNaN(s.substr(1));
		}
		
		//check if nanFlag is set to true and the length is = 1
		//which means we are at the end of the string
		if (nanFlag == true || s.length() == 1) {					//if nanFlag is true or the string length is 1
			*this->nan = nanFlag;									//then I set the object flag to nanFlag.
			//reset decPtCounter to 0 and nanFlag to false since they are static.
			decPtCounter = 0;
			nanFlag = false;
		}
	}
	

	//memory allocation for doubleNum and nan
	void Double::create()
	{
		try {
			this->doubleNum = new double;
			this->nan = new bool;
		}
		catch (const bad_alloc& e) {

			cout << "Error allocating memory - doubleNum or nan from Double class " << e.what() << endl;
			exit(EXIT_FAILURE);
		}

	}
}
