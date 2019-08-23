/*
Class: CSIS-123A-3738
Name: Karishma Kapur
ID: 0558326
11/17/18
Assignment 13 - Exceptions
main.cpp file
Creating a menu that allows you test the add, sub, mul, div functions for instances of both classes
*/
#include <iostream>
#include <cstdlib>
#include "Menu.h"
#include "Integer.h"
#include "Double.h"
#include <string>
#include <fstream>
#include <vector>
#include <string>
#include "Number.h"
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::bad_alloc;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
using std::boolalpha;

using namespace Karishma;


//object Double
void DoubleAdd();
void DoubleSub();
void DoubleMul();
void DoubleDiv();

//object Integer 
void IntegerAdd();
void IntegerSub();
void IntegerMul();
void IntegerDiv();

void inputStringD(string & s1, string & s2);
void inputStringI(string & s1, string & s2);

void Exit();

Menu *m = Menu::Instance();
Menu *k = Menu::Instance();
int main() {


	Menu *m = Menu::Instance();
	//Object Doubles
	m->addMenuItem("1.  Doubles Object - Add ", DoubleAdd);
	m->addMenuItem("2.  Doubles Object - Subtract ", DoubleSub);
	m->addMenuItem("3.  Doubles Object - Multiply ", DoubleMul);
	m->addMenuItem("4.  Doubles Object - Divide ", DoubleDiv);

	//Object Integers
	m->addMenuItem("5.  Integers Object - Add   ", IntegerAdd);
	m->addMenuItem("6.  Integers Object - Subtract ", IntegerSub);
	m->addMenuItem("7.  Integers Object - Multiply ", IntegerMul);
	m->addMenuItem("8.  Integers Object - Divide ", IntegerDiv);

	//Exit
	m->addMenuItem("9.  Exit", Exit);

	m->runMenu();


}



void inputStringD(string & s1, string & s2)
{
	cout << "Enter two strings of type Double separated by a single space" << endl;
	cin >> s1 >> s2;
}
void inputStringI(string & s1, string & s2)
{
	cout << "Enter two strings of type Integer separated by a single space" << endl;
	cin >> s1 >> s2;
}

//adding two double objects
void DoubleAdd()
{
	//double di1, di2;//instantiating two primitive doubles for input
	string di1, di2;
	Menu *m = Menu::Instance();
	//inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	inputStringD(di1, di2);
	//instantiating 3 Double objects; d1, d2 for input and d3 for storing result
	try {
		Double *d1 = new Double(di1); //setting the d1 Object with di1 value
		Double *d2 = new Double(di2); //setting d2 Object with di2 value
		//doing this because instead of creating a temporary object and then assigning it to d3, we only create 1 object so we don't waste memory space on heap.
		Double *d3 = &(*d1 + *d2); //adding two Double objects and storing result in d3
		cout << "adding two Double objects: " << d1->toDouble() << " + " << d2->toDouble() << " = " << d3->toDouble() << endl << endl;
		delete d1;
		delete d2;
		delete d3;
	}
	catch (const bad_alloc& e) {
		cout << "DoubleAdd - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	catch (NumberException& ex) {
		cout << "\nError code = " <<  ex.getCode() << "\n" << ex.getMessage() << "\n\n" << endl;
	}
	m->waitKey();

}

//subtracting two Double objects
void DoubleSub()
{
	//double di1, di2;//instantiating two primitive doubles for input
	string di1, di2;
	Menu *m = Menu::Instance();
	//inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	inputStringD(di1, di2);
	//instantiating 3 Double objects; d1, d2 for input and d3 for storing result
	try {
		Double *d1 = new Double(di1); //setting the d1 Object with di1 value
		Double *d2 = new Double(di2); //setting d2 Object with di2 value
		//doing this because instead of creating a temporary object and then assigning it to d3, we only create 1 object so we don't waste memory space on heap.
		Double *d3 = &(*d1 - *d2); //subtracting two Double objects and storing result in d3

		cout << "subtracting two Double objects: " << d1->toDouble() << " - " << d2->toDouble() << " = " << d3->toDouble() << endl << endl;
		delete d1;
		delete d2;
		delete d3;
	}
	catch (const bad_alloc& e) {
		cout << "DoubleSub - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	catch (NumberException& ex) {
		cout << "\nError code = " << ex.getCode() << "\n" << ex.getMessage() << "\n\n" << endl;
	}
	m->waitKey();
}

//multiplying two Double objects
void DoubleMul()
{
	//double di1, di2;//instantiating two primitive doubles for input
	string di1, di2;
	Menu *m = Menu::Instance();
	//inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	inputStringD(di1, di2);
	//instantiating 3 Double objects; d1, d2 for input and d3 for storing result
	try {
		Double *d1 = new Double(di1); //setting the d1 Object with di1 value
		Double *d2 = new Double(di2); //setting d2 Object with di2 value
		//doing this because instead of creating a temporary object and then assigning it to d3, we only create 1 object so we don't waste memory space on heap.
		Double *d3 = &(*d1 * *d2); //multiplying two Double objects and storing result in d3
		cout << "multiplying two Double objects: " << d1->toDouble() << " * " << d2->toDouble() << " = " << d3->toDouble() << endl << endl;
		delete d1;
		delete d2;
		delete d3;
	}
	catch (const bad_alloc& e) {
		cout << "DoubleMul - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	catch (NumberException& ex) {
		cout << "\nError code = " << ex.getCode() << "\n" << ex.getMessage() << "\n\n" << endl;
	}
	m->waitKey();
}

//dividing two Double objects
void DoubleDiv()
{
	//double di1, di2;//instantiating two primitive doubles for input
	string di1, di2;
	Double *d1, *d2, *d3; //instantiating 3 Double objects; d1, d2 for input and d3 for storing result
	Menu *m = Menu::Instance();
	//inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	inputStringD(di1, di2);
	try {
		d1 = new Double(di1); //setting the d1 Object with di1 value
		d2 = new Double(di2); //setting d2 Object with di2 value
		//doing this because instead of creating a temporary object and then assigning it to d3, we only create 1 object so we don't waste memory space on heap.
		d3 = &(*d1 / *d2); //dividing two Double objects and storing result in d3
		cout << "dividing two Double objects: " << d1->toDouble() << " / " << d2->toDouble() << " = " << d3->toDouble() << endl << endl;
		delete d1;
		delete d2;
		delete d3;
	}
	catch (const bad_alloc& e) {
		cout << "DoubleDiv - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	catch (NumberException& ex) {
		cout << "\nError code = " << ex.getCode() << "\n" << ex.getMessage() << "\n\n" << endl;
	}
	m->waitKey();
}

//adding two Integer objects
void IntegerAdd()
{
	//int Ii1, Ii2;//instantiating two primitive integers for input
	string Ii1, Ii2;
	Menu *m = Menu::Instance();
	//inputIntegers(Ii1, Ii2);//calling inputIntegers method to get two primitive ints
	inputStringI(Ii1, Ii2);
	//instantiating 3 Integer objects; i1, i2 for input and i3 for storing result
	try {
		Integer *i1 = new Integer(Ii1); //setting the i1 Object with Ii1 value
		Integer *i2 = new Integer(Ii2); //setting i2 Object with Ii2 value
		//doing this because instead of creating a temporary object and then assigning it to i3, we only create 1 object so we don't waste memory space on heap.
		Integer *i3 = &(*i1 + *i2); //adding two Integer objects and storing result in i3
		cout << "adding two Integer objects: " << i1->toInt() << " + " << i2->toInt() << " = " << i3->toInt() << endl << endl;
		delete i1;
		delete i2;
		delete i3;
	}
	catch (const bad_alloc& e) {
		cout << "IntegerAdd - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	catch (NumberException& ex) {
		cout << "\nError code = " << ex.getCode() << "\n" << ex.getMessage() << "\n\n" << endl;
	}
	m->waitKey();
}

//subtracting two Integer objects
void IntegerSub()
{
	//int Ii1, Ii2;//instantiating two primitive integers for input
	string Ii1, Ii2;
	Menu *m = Menu::Instance();
	//inputIntegers(Ii1, Ii2);//calling inputIntegers method to get two primitive ints
	inputStringI(Ii1, Ii2);
	//instantiating 3 Integer objects; i1, i2 for input and i3 for storing result
	try {
		Integer *i1 = new Integer(Ii1); //setting the i1 Object with Ii1 value
		Integer *i2 = new Integer(Ii2); //setting i2 Object with Ii2 value
		//doing this because instead of creating a temporary object and then assigning it to i3, we only create 1 object so we don't waste memory space on heap.
		Integer *i3 = &(*i1 - *i2); //subtracting two Integer objects and storing result in i3
		cout << "subtracting two Integer objects: " << i1->toInt() << " - " << i2->toInt() << " = " << i3->toInt() << endl << endl;
		delete i1;
		delete i2;
		delete i3;
	}
	catch (const bad_alloc& e) {
		cout << "IntegerSub - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	catch (NumberException& ex) {
		cout << "\nError code = " << ex.getCode() << "\n" << ex.getMessage() << "\n\n" << endl;
	}
	m->waitKey();
}

//multiplying two Integer objects
void IntegerMul()
{
	//int Ii1, Ii2;//instantiating two primitive integers for input
	string Ii1, Ii2;
	Menu *m = Menu::Instance();
	//inputIntegers(Ii1, Ii2);//calling inputIntegers method to get two primitive ints
	inputStringI(Ii1, Ii2);
	//instantiating 3 Integer objects; i1, i2 for input and i3 for storing result
	try {
		Integer *i1 = new Integer(Ii1); //setting the i1 Object with Ii1 value
		Integer *i2 = new Integer(Ii2); //setting i2 Object with Ii2 value
		//doing this because instead of creating a temporary object and then assigning it to i3, we only create 1 object so we don't waste memory space on heap.
		Integer *i3 = &(*i1 * *i2); //multiplying two Integer objects and storing result in i3
		cout << "multiplying two Integer objects: " << i1->toInt() << " * " << i2->toInt() << " = " << i3->toInt() << endl << endl;
		delete i1;
		delete i2;
		delete i3;
	}
	catch (const bad_alloc& e) {
		cout << "IntegerMul - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	catch (NumberException& ex) {
		cout << "\nError code = " << ex.getCode() << "\n" << ex.getMessage() << "\n\n" << endl;
	}
	m->waitKey();
}

//dividing two Integer objects
void IntegerDiv()
{
	//int Ii1, Ii2;//instantiating two primitive integers for input
	string Ii1, Ii2;
	Menu *m = Menu::Instance();
	//inputIntegers(Ii1, Ii2);//calling inputIntegers method to get two primitive ints
	inputStringI(Ii1, Ii2);
	//instantiating 3 Integer objects; i1, i2 for input and i3 for storing result
	try {
		Integer *i1 = new Integer(Ii1); //setting the i1 Object with Ii1 value
		Integer *i2 = new Integer(Ii2); //setting i2 Object with Ii2 value
		//doing this because instead of creating a temporary object and then assigning it to i3, we only create 1 object so we don't waste memory space on heap.
		Integer *i3 = &(*i1 / *i2); //dividing two Integer objects and storing result in i3
		cout << "dividing two Integer objects: " << i1->toInt() << " / " << i2->toInt() << " = " << i3->toInt() << endl << endl;
		delete i1;
		delete i2;
		delete i3;
	}
	catch (const bad_alloc& e) {
		cout << "IntegerDiv - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	catch (NumberException& ex) {
		cout << "\nError code = " << ex.getCode() << "\n" << ex.getMessage() << "\n\n" << endl;
	}
	m->waitKey();
}



void Exit()
{

	cout << "GoodBye" << endl;
	exit(0);
}

