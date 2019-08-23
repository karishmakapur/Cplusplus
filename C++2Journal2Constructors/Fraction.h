/*Karishma Kapur
ID: 0558326
Journal 2
Constructors
8/29/18
*/
#ifndef FRACTION
#define FRACTION
#include <string>

using std::string;

class Fraction {
private:
	int num;
	int den;

public:
	void setFraction(int n, int d);
	Fraction add(const Fraction &f);
	Fraction sub(const Fraction &f);
	Fraction mul(const Fraction &f);
	Fraction div(const Fraction &f);
	int getnum() const;
	int getDen() const;
	void printFraction();

	//Constructors
	Fraction();
	Fraction(int num, int den);
	Fraction(string s);

	//Operator Overloads
	Fraction operator +(const Fraction &f);
	Fraction operator -(const Fraction &f);
	Fraction operator / (const Fraction &f);
	Fraction operator * (const Fraction &f);
	Fraction& operator = (const Fraction &f);
};


#endif