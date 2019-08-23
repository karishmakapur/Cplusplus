 /*Karishma Kapur
ID: 0558326
Journal 2
Constructors
8/29/18
*/
#include <iostream>
#include "Fraction.h"
#include <string>

using namespace std;

int main() {
	
	//Callin Overloaded Fraction Constructor that passes two ints.
	Fraction f1(1, 4), f2(1, 2);

	//Calling default constructor.
	Fraction f3, f4, f5, f6;

	//Calling Overloaded Fraction Constructor that passes string agrument. 
	//I am assuming the constructor is called with one space between
	//numerator and denominator, as asked in the journal video.
	//Entered as : "11 12"
	
	/*string s;
	cout << "Enter 2 digits separated by a space" << endl;
	getline(cin, s); //input entered in s.
	Fraction f7(s); //overloaded constructor called with string s.
	cout << "f7 as a fraction is ";
	f7.printFraction(); //printing the f7 object as a fraction.
	*/

	cout << "f1 = ";
	f1.printFraction();
	cout << "f2 = ";
	f2.printFraction();
	//add
	f3 = f1 + f2;
	cout << "f1 + f2 = ";
	f3.printFraction();

	//subtract
	f4 = f1 - f2;
	cout << "f1 - f2 = ";
	f4.printFraction();

	//multiply
	f5 = f1 * f2;
	cout << "f1 * f2 = ";
	f5.printFraction();

	//divide
	f6 = f1 / f2;
	cout << "f1 / f2 = ";
	f6.printFraction();
	
	
	return 0;
	
}