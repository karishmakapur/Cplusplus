/*Karishma Kapur
ID: 0558326
Journal 2
Constructors
8/29/18
*/
#include <iostream>
#include <cmath>
#include "Fraction.h"
#include <string>

using namespace std;

Fraction::Fraction()
{
	this->setFraction(1, 1);
}
Fraction::Fraction(int num, int den)
{
	this->setFraction(num, den);
}
Fraction::Fraction(string s) 
{
	//I am parsing the string to extract the num and den.
	int temp; //temp contains the position where the space is found between the num and den in the string.
	int num; //temporary local variable to hold the extracted numerator from the string
	int den; //temporary local variable to hold the extracted denominator from the string 
	temp = s.find(" ");
	string stringnum = s.substr(0,temp++);
	string stringden = s.substr(temp);

	//converting the string into an int.
	num = stoi(stringnum);
	den = stoi(stringden);

	//setting the object numerator and denominator.
	this->setFraction(num, den);
}
Fraction Fraction::operator+(const Fraction & f)
{
	return this->add(f);
}
Fraction Fraction::operator-(const Fraction & f)
{
	return this->sub(f);
}
Fraction Fraction::operator/(const Fraction & f)
{
	return this->div(f);
}
Fraction Fraction::operator*(const Fraction & f)
{
	return this->mul(f);
}
Fraction &Fraction::operator=(const Fraction & f)
{
	this->setFraction(f.num, f.den);
	return *this;
}
void Fraction::setFraction(int n, int d) {
	this->num = n;
	this->den = d;
}
Fraction Fraction::add(const Fraction &f) {
	Fraction tmp;
	tmp.num = (this->num * f.den) + (f.num * this->den);
	tmp.den = f.den * this->den;
	return tmp;
}
Fraction Fraction::sub(const Fraction &f) {
	Fraction tmp;
	tmp.num = (this->num * f.den) - (f.num * this->den);
	tmp.den = f.den * this->den;
	return tmp;
}
Fraction Fraction::mul(const Fraction & f)
{
	Fraction tmp;
	tmp.num = this->num * f.num;
	tmp.den = this->den * f.den;
	return tmp;
}
Fraction Fraction::div(const Fraction & f)
{
	Fraction tmp;

	tmp.num = this->num * f.den;
	tmp.den = this->den * f.num;

	return tmp;
}
int Fraction::getnum() const
{
	return this->num;
}
int Fraction::getDen() const
{
	return this->den;
}
void Fraction::printFraction() {
	int sign = 1;
	if (this->num < 0) {
		sign *= -1;
	}
	if (this->den < 0) {
		sign *= -1;
	}

	cout << sign * abs(this->num) << "/" << abs(this->den) << endl;
}
