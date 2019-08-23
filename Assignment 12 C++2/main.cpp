/*
Class: CSIS-123A-3738
Name: Karishma Kapur
ID: 0558326
11/11/18
Assignment 12 - Polymorphism
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

//getting user input
void inputDouble(double& d1, double& d2);
void inputIntegers(int& i1, int& i2);

//object Double
void DoubleAdd();
void DoubleSub();
void DoubleMul();
void DoubleDiv();


//Double Object using primitive double
void doubleAdd();
void doubleSub();
void doubleMul();
void doubleDiv();

//object Integer 
void IntegerAdd();
void IntegerSub();
void IntegerMul();
void IntegerDiv();

//Integer Object using primitive int
void integerAdd();
void integerSub();
void integerMul();
void integerDiv();

//compare object(s) with another Object or primitive type
void DoubleEqualCompare(); //compare 2 double objects to check if they are Equal
void DoubleNotEqualCompare(); //compare 2 double objects to check if they are Not Equal
void doubleEqualCompare(); //compare a double object and a primitive double to check if they are Equal
void doubleNotEqualCompare();//compare a double object and a primitive double to check if they are Not Equal
void IntegerEqualCompare(); //compare 2 Integer objects to check if they are Equal
void IntegerNotEqualCompare(); //compare 2 Integer objects to check if they are Not Equal
void intEqualCompare(); //compare a Integer object and a primitive int to check if they are Equal
void intNotEqualCompare();//compare a Integer object and a primitive int to check if they are Not Equal

//toString method of Double Class and Integer Class && string constructor from Double and Integer Class
void toStringDoubleInteger();

//overloaded equals function from Double and Integer Class which calls isNaN
void equalsDoubleInteger();

//An overloaded = operator that takes a string from Double and Integer Class which calls isNaN
void operatorEqualsDoubleInteger();

//parse
void parseFile();

//writing the files
void writeNumbers(vector<Integer*> iNumbers);
void writeNumbers(vector<Double*> dNumbers);

void assignment12();

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

	//Primitive doubles
	m->addMenuItem("5.  Doubles primitive - Add  ", doubleAdd);
	m->addMenuItem("6.  Doubles primitive - Subtract ", doubleSub);
	m->addMenuItem("7.  Doubles primitive - Multiply ", doubleMul);
	m->addMenuItem("8.  Doubles primitive - Divide ", doubleDiv);


	//Object Integers
	m->addMenuItem("9.  Integers Object - Add   ", IntegerAdd);
	m->addMenuItem("10. Integers Object - Subtract ", IntegerSub);
	m->addMenuItem("11. Integers Object - Multiply ", IntegerMul);
	m->addMenuItem("12. Integers Object - Divide ", IntegerDiv);


	//Primitive Integers
	m->addMenuItem("13. Integers primitive - Add ", integerAdd);
	m->addMenuItem("14. Integers primitive - Subtract ", integerSub);
	m->addMenuItem("15. Integers primitive - Multiply ", integerMul);
	m->addMenuItem("16. Integers primitive - Divide ", integerDiv);

	//comparing two Double Objects
	m->addMenuItem("17. Compare two Double Objects using Equal operator ", DoubleEqualCompare);
	m->addMenuItem("18. Compare two Double Objects using Not Equal operator", DoubleNotEqualCompare);

	//comparing 1 Double Object and 1 primitive double
	m->addMenuItem("19. Compare 1 Double Object and 1 primitive double using Equal Operator ", doubleEqualCompare);
	m->addMenuItem("20. Compare 1 Double Object and 1 primitive double using Not Equal Operator ", doubleNotEqualCompare);

	//comparing two Integer Objects
	m->addMenuItem("21. Compare 2 Integer Objects using Equal Operator ", IntegerEqualCompare);
	m->addMenuItem("22. Compare 2 Integer Objects using Not Equal Operator ", IntegerNotEqualCompare);

	//comparing 1 integer object and 1 primitive int
	m->addMenuItem("23. Compare 1 Integer Object and 1 primitive int using Equal Operator ", intEqualCompare);
	m->addMenuItem("24. Compare 1 Integer Object and 1 primitive int using Not Equal Operator ", intNotEqualCompare);

	//toString method of Double Class and Integer Class
	m->addMenuItem("25. toString() method & string constructor from Double and Integer Class", toStringDoubleInteger);

	//overloaded equals function from Double and Integer Class which calls isNaN
	m->addMenuItem("26. equals() function of Integer Class and Double Class, which called isNaN", equalsDoubleInteger);

	//An overloaded = operator that takes a string from Double and Integer Class which calls isNaN
	m->addMenuItem("27. An overloaded = operator that takes a string from Double and Integer Class which calls isNaN", operatorEqualsDoubleInteger);

	//parseFile()
	m->addMenuItem("28. Parse numbers.txt into integer.txt and double.txt files", parseFile);

	//assignment10
	m->addMenuItem("29. Assignment 12", assignment12);

	//Exit
	m->addMenuItem("30.  Exit", Exit);

	m->runMenu();


}

void inputDouble(double & d1, double & d2)
{
	cout << "Enter two double type numbers separated by a single space" << endl;
	cin >> d1 >> d2;
}

void inputIntegers(int & i1, int & i2)
{
	cout << "Enter two integer type numbers separated by a single space" << endl;
	cin >> i1 >> i2;
}

//adding two double objects
void DoubleAdd()
{
	double di1, di2;//instantiating two primitive doubles for input
	Menu *m = Menu::Instance();
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
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
	m->waitKey();

}

//subtracting two Double objects
void DoubleSub()
{
	double di1, di2;//instantiating two primitive doubles for input
	Menu *m = Menu::Instance();
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
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
	m->waitKey();
}

//multiplying two Double objects
void DoubleMul()
{
	double di1, di2;//instantiating two primitive doubles for input
	Menu *m = Menu::Instance();
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
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
	m->waitKey();
}

//dividing two Double objects
void DoubleDiv()
{
	double di1, di2;//instantiating two primitive doubles for input
	Double *d1, *d2, *d3; //instantiating 3 Double objects; d1, d2 for input and d3 for storing result
	Menu *m = Menu::Instance();
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
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
	m->waitKey();
}

//adding a Double object & a primitive double
void doubleAdd()
{
	double di1, di2;//instantiating two primitive doubles for input
	Menu *m = Menu::Instance();
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	//instantiating 2 Double objects; d1 for input and d2 for storing result
	try {
		Double *d1 = new Double(di1); //setting the d1 Object with di1 value
		//doing this because instead of creating a temporary object and then assigning it to d2, we only create 1 object so we don't waste memory space on heap.
		Double *d2 = &(*d1 + di2);//adding a Double objects and a primitive double and storing result in d2
		cout << "adding a Double object & a primitive double: " << d1->toDouble() << " + " << di2 << " = " << d2->toDouble() << endl << endl;
		delete d1;
		delete d2;
	}
	catch (const bad_alloc& e) {
		cout << "doubleAdd - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	m->waitKey();
}

//subtracting a Double object & a primitive double
void doubleSub()
{
	double di1, di2;//instantiating two primitive doubles for input
	Menu *m = Menu::Instance();
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	//instantiating 2 Double objects; d1 for input and d2 for storing result
	try {
		Double *d1 = new Double(di1); //setting the d1 Object with di1 value
		//doing this because instead of creating a temporary object and then assigning it to d2, we only create 1 object so we don't waste memory space on heap.
		Double *d2 = &(*d1 - di2);//subtracting a Double objects and a primitive double and storing result in d2
		cout << "subtracting a Double object & a primitive double: " << d1->toDouble() << " - " << di2 << " = " << d2->toDouble() << endl << endl;
		delete d1;
		delete d2;
	}
	catch (const bad_alloc& e) {
		cout << "doubleSub - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	m->waitKey();
}

//multiplying a Double object & a primitive double
void doubleMul()
{
	double di1, di2;//instantiating two primitive doubles for input
	Menu *m = Menu::Instance();
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	//instantiating 2 Double objects; d1 for input and d2 for storing result
	try {
		Double *d1 = new Double(di1); //setting the d1 Object with di1 value
		//doing this because instead of creating a temporary object and then assigning it to d2, we only create 1 object so we don't waste memory space on heap.
		Double *d2 = &(*d1 * di2);//multiplying a Double objects and a primitive double and storing result in d2
		cout << "multiplying a Double object & a primitive double: " << d1->toDouble() << " * " << di2 << " = " << d2->toDouble() << endl << endl;
		delete d1;
		delete d2;
	}
	catch (const bad_alloc& e) {
		cout << "doubleMul - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	m->waitKey();
}

//dividing a Double object & a primitive double
void doubleDiv()
{
	double di1, di2;//instantiating two primitive doubles for input
	Menu *m = Menu::Instance();
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	//instantiating 2 Double objects; d1 for input and d2 for storing result
	try {
		Double *d1 = new Double(di1); //setting the d1 Object with di1 value
		//doing this because instead of creating a temporary object and then assigning it to d2, we only create 1 object so we don't waste memory space on heap.
		Double *d2 = &(*d1 / di2);//dividing a Double objects and a primitive double and storing result in d2
		cout << "dividing a Double object & a primitive double: " << d1->toDouble() << " / " << di2 << " = " << d2->toDouble() << endl << endl;
		delete d1;
		delete d2;
	}
	catch (const bad_alloc& e) {
		cout << "doubleDiv - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	m->waitKey();
}

//adding two Integer objects
void IntegerAdd()
{
	int Ii1, Ii2;//instantiating two primitive integers for input
	Menu *m = Menu::Instance();
	inputIntegers(Ii1, Ii2);//calling inputIntegers method to get two primitive ints
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
	m->waitKey();
}

//subtracting two Integer objects
void IntegerSub()
{
	int Ii1, Ii2;//instantiating two primitive integers for input
	Menu *m = Menu::Instance();
	inputIntegers(Ii1, Ii2);//calling inputIntegers method to get two primitive ints
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
	m->waitKey();
}

//multiplying two Integer objects
void IntegerMul()
{
	int Ii1, Ii2;//instantiating two primitive integers for input
	Menu *m = Menu::Instance();
	inputIntegers(Ii1, Ii2);//calling inputIntegers method to get two primitive ints
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
	m->waitKey();
}

//dividing two Integer objects
void IntegerDiv()
{
	int Ii1, Ii2;//instantiating two primitive integers for input
	Menu *m = Menu::Instance();
	inputIntegers(Ii1, Ii2);//calling inputIntegers method to get two primitive ints
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
	m->waitKey();
}

//adding an Integer object and a primitive integer
void integerAdd()
{
	int Ii1, Ii2;//instantiating two primitive integers for input
	Menu *m = Menu::Instance();
	inputIntegers(Ii1, Ii2);//calling inputIntegers method to get two primitive ints
	//instantiating 2 Integer objects; i1 for input and i2 for storing result
	try {
		Integer *i1 = new Integer(Ii1); //setting the i1 Object with Ii1 value
		//doing this because instead of creating a temporary object and then assigning it to i2, we only create 1 object so we don't waste memory space on heap.
		Integer *i2 = &(*i1 + Ii2); //adding an Integer object and a primitive integer and storing result in i2
		cout << "adding an Integer object and a primitive integer: " << i1->toInt() << " + " << Ii2 << " = " << i2->toInt() << endl << endl;
		delete i1;
		delete i2;
	}
	catch (const bad_alloc& e) {
		cout << "integerAdd - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	m->waitKey();
}

//subtracting an Integer object and a primitive integer
void integerSub()
{
	int Ii1, Ii2;//instantiating two primitive integers for input
	Menu *m = Menu::Instance();
	inputIntegers(Ii1, Ii2);//calling inputIntegers method to get two primitive ints
	//instantiating 2 Integer objects; i1 for input and i2 for storing result
	try {
		Integer *i1 = new Integer(Ii1); //setting the i1 Object with Ii1 value
		//doing this because instead of creating a temporary object and then assigning it to i2, we only create 1 object so we don't waste memory space on heap.
		Integer *i2 = &(*i1 - Ii2); //subtracting an Integer object and a primitive integer and storing result in i2
		cout << "subtracting an Integer object and a primitive integer: " << i1->toInt() << " - " << Ii2 << " = " << i2->toInt() << endl << endl;
		delete i1;
		delete i2;
	}
	catch (const bad_alloc& e) {
		cout << "integerSub - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	m->waitKey();
}

//multiplying an Integer object and a primitive integer
void integerMul()
{
	int Ii1, Ii2;//instantiating two primitive integers for input
	Menu *m = Menu::Instance();
	inputIntegers(Ii1, Ii2);//calling inputIntegers method to get two primitive ints
	//instantiating 2 Integer objects; i1 for input and i2 for storing result
	try {
		Integer *i1 = new Integer(Ii1); //setting the i1 Object with Ii1 value
		//doing this because instead of creating a temporary object and then assigning it to i2, we only create 1 object so we don't waste memory space on heap.
		Integer *i2 = &(*i1 * Ii2); //multiplying an Integer object and a primitive integer and storing result in i2
		cout << "multiplying an Integer object and a primitive integer: " << i1->toInt() << " * " << Ii2 << " = " << i2->toInt() << endl << endl;
		delete i1;
		delete i2;
	}
	catch (const bad_alloc& e) {
		cout << "integerMul - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	m->waitKey();
}

//dividing an Integer object and a primitive integer
void integerDiv()
{
	int Ii1, Ii2;//instantiating two primitive integers for input
	Menu *m = Menu::Instance();
	inputIntegers(Ii1, Ii2);//calling inputIntegers method to get two primitive ints
	//instantiating 2 Integer objects; i1 for input and i2 for storing result
	try {
		Integer *i1 = new Integer(Ii1); //setting the i1 Object with Ii1 value
		//doing this because instead of creating a temporary object and then assigning it to i2, we only create 1 object so we don't waste memory space on heap.
		Integer *i2 = &(*i1 / Ii2); //dividing an Integer object and a primitive integer and storing result in i2
		cout << "dividing an Integer object and a primitive integer: " << i1->toInt() << " / " << Ii2 << " = " << i2->toInt() << endl << endl;
		delete i1;
		delete i2;
	}
	catch (const bad_alloc& e) {
		cout << "integerDiv - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	m->waitKey();
}
void DoubleEqualCompare()
{
	double di1, di2;//instantiating two primitive doubles for input
	Menu *m = Menu::Instance();
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	//instantiating 2 Double objects; d1 and d2 for input
	try {
		Double *d1 = new Double(di1); //setting the d1 Object with di1 value
		Double *d2 = new Double(di2); //setting d2 Object with di2 value
		cout << "comparing two Double objects: " << d1->toDouble() << " == " << d2->toDouble() << (*d1 == *d2 ? " -> Equal" : " -> Not Equal") << endl << endl;
		delete d1;
		delete d2;
	}
	catch (const bad_alloc& e) {
		cout << "DoubleEqualCompare - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	m->waitKey();
}
void DoubleNotEqualCompare()
{
	double di1, di2;//instantiating two primitive doubles for input
	Menu *m = Menu::Instance();
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	//instantiating 2 Double objects; d1 and d2 for input
	try {
		Double *d1 = new Double(di1); //setting the d1 Object with di1 value
		Double *d2 = new Double(di2); //setting d2 Object with di2 value
		cout << "comparing two Double objects: " << d1->toDouble() << " != " << d2->toDouble() << (*d1 != *d2 ? " -> Not Equal" : " -> Equal") << endl << endl;
		delete d1;
		delete d2;
	}
	catch (const bad_alloc& e) {
		cout << "DoubleNotEqualCompare - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	m->waitKey();
}
void doubleEqualCompare()
{
	double di1, di2;//instantiating two primitive doubles for input
	Menu *m = Menu::Instance();
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	//instantiating 1 Double object for input
	try {
		Double *d1 = new Double(di1); //setting the d1 Object with di1 value
		cout << "comparing two Double objects: " << d1->toDouble() << " == " << di2 << (*d1 == di2 ? " -> Equal" : " -> Not Equal") << endl << endl;
		delete d1;
	}
	catch (const bad_alloc& e) {
		cout << "doubleEqualCompare - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	m->waitKey();
}
void doubleNotEqualCompare()
{

	double di1, di2;//instantiating two primitive doubles for input
	Menu *m = Menu::Instance();
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	//instantiating 1 Double object for input
	try {
		Double *d1 = new Double(di1); //setting the d1 Object with di1 value
		cout << "comparing two Double objects: " << d1->toDouble() << " != " << di2 << (*d1 != di2 ? " -> Not Equal" : " -> Equal") << endl << endl;
		delete d1;
	}
	catch (const bad_alloc& e) {
		cout << "doubleNotEqualCompare - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	m->waitKey();
}
void IntegerEqualCompare()
{
	int Ii1, Ii2;//instantiating two primitive int for input
	Menu *m = Menu::Instance();
	inputIntegers(Ii1, Ii2);//calling inputInteger method to get two primitive ints
	//instantiating 2 Integer objects; i1 and i2 for input
	try {
		Integer *i1 = new Integer(Ii1); //setting the i1 Object with Ii1 value
		Integer *i2 = new Integer(Ii2); //setting i2 Object with Ii2 value
		cout << "comparing two Integer objects: " << i1->toInt() << " == " << i2->toInt() << (*i1 == *i2 ? " -> Equal" : " -> Not Equal") << endl << endl;
		delete i1;
		delete i2;
	}
	catch (const bad_alloc& e) {
		cout << "IntegerEqualCompare - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	m->waitKey();
}
void IntegerNotEqualCompare()
{
	int Ii1, Ii2;//instantiating two primitive int for input
	Menu *m = Menu::Instance();
	inputIntegers(Ii1, Ii2);//calling inputInteger method to get two primitive ints
	//instantiating 2 Integer objects; i1 and i2 for input
	try {
		Integer *i1 = new Integer(Ii1); //setting the i1 Object with Ii1 value
		Integer *i2 = new Integer(Ii2); //setting i2 Object with Ii2 value
		cout << "comparing two Integer objects: " << i1->toInt() << " != " << i2->toInt() << (*i1 != *i2 ? " -> Not Equal" : " -> Equal") << endl << endl;
		delete i1;
		delete i2;
	}
	catch (const bad_alloc& e) {
		cout << "IntegerNotEqualCompare - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	m->waitKey();
}
void intEqualCompare()
{
	int Ii1, Ii2;//instantiating two primitive int for input
	Menu *m = Menu::Instance();
	inputIntegers(Ii1, Ii2);//calling inputInteger method to get two primitive ints
	//instantiating 1 Integer objects for input
	try {
		Integer *i1 = new Integer(Ii1); //setting the i1 Object with Ii1 value
		cout << "comparing 1 Integer object and a primitive integer: " << i1->toInt() << " == " << Ii2 << (*i1 == Ii2 ? " -> Equal" : " -> Not Equal") << endl << endl;
		delete i1;
	}
	catch (const bad_alloc& e) {
		cout << "intEqualCompare - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	m->waitKey();
}
void intNotEqualCompare()
{
	int Ii1, Ii2;//instantiating two primitive int for input
	Menu *m = Menu::Instance();
	inputIntegers(Ii1, Ii2);//calling inputInteger method toget two primitive ints
	//instantiating 1 Integer objects for input
	try {
		Integer *i1 = new Integer(Ii1); //setting the i1 Object with Ii1 value
		cout << "comparing 1 Integer object and a primitive integer: " << i1->toInt() << " != " << Ii2 << (*i1 != Ii2 ? " -> Not Equal" : " -> Equal") << endl << endl;
		delete i1;
	}
	catch (const bad_alloc& e) {
		cout << "intNotEqualCompare - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	m->waitKey();
}
void toStringDoubleInteger()
{
	Menu *m = Menu::Instance();
	try {
		Integer *i = new Integer("12");
		Double *d = new Double("12.34");
		string s1, s2;

		s1 = (*i).toString();
		s2 = (*d).toString();
		cout << "Integer toString function (using 12 as number): " << s1 << endl;
		cout << "Double toString function (using 12.34 as number): " << s2 << endl;
		delete i;
		delete d;

	}
	catch (const bad_alloc& e) {
		cout << "toStringDoubleInteger - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	m->waitKey();

}
void equalsDoubleInteger()
{
	Menu *m = Menu::Instance();
	try {
		Integer *i1 = new Integer("12");
		Integer *i2 = new Integer("12x");
		Double *d1 = new Double("12.34");
		Double *d2 = new Double("12.34.34");

		cout << "Integer isNaN value (0 = false, 1 = true): " << i1->isNaN() << " & Value =  " << i1->toInt() << endl;
		cout << "Integer isNaN value (0 = false, 1 = true): " << i2->isNaN() << " & Value =  " << i2->toInt() << endl;
		cout << "Double isNaN value (0 = false, 1 = true): " << d1->isNaN() << " & Value =  " << d1->toDouble() << endl;
		cout << "Double isNaN value (0 = false, 1 = true): " << d2->isNaN() << " & Value =  " << d2->toDouble() << endl;
		delete i1;
		delete i2;
		delete d1;
		delete d2;
	}
	catch (const bad_alloc& e) {
		cout << "equalsDoubleInteger - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	m->waitKey();
}
void operatorEqualsDoubleInteger()
{
	Menu *m = Menu::Instance();
	try {
		Integer *i1 = new Integer("12");
		Integer *i2 = new Integer("12x");
		Double *d1 = new Double("12.34");
		Double *d2 = new Double("12.34.34");

		cout << "Integer isNaN value (0 = false, 1 = true): " << i1->isNaN() << " & Value =  " << i1->toInt() << endl;
		cout << "Integer isNaN value (0 = false, 1 = true): " << i2->isNaN() << " & Value =  " << i2->toInt() << endl;
		cout << "Double isNaN value (0 = false, 1 = true): " << d1->isNaN() << " & Value =  " << d1->toDouble() << endl;
		cout << "Double isNaN value (0 = false, 1 = true): " << d2->isNaN() << " & Value =  " << d2->toDouble() << endl;
		delete i1;
		delete i2;
		delete d1;
		delete d2;
	}
	catch (const bad_alloc& e) {
		cout << "operatorEqualsDoubleInteger - cannot allocate memory " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	m->waitKey();
}

void parseFile()
{
	Menu *m = Menu::Instance();
	ifstream infile("numbers.txt"); //opens numbers file which contains the integers and doubles.
	if (!infile) {
		cout << "Unable to open numbers.txt for read" << endl;
		exit(1);
	}

	vector<Integer*> iNumbers; //vector containing pointers to Integer class 
	vector<Double*> dNumbers; //vector containing pointers to Double class
	string input;
	while (infile >> input)
	{
		//cout << input << endl;
		//decimal point means double 
		//else it is an integer
		std::size_t found = input.find(".");
		if (found != std::string::npos) {
			//cout << input << " is an double" << endl;
			// When you add a value to one of the vectors you should use new and call the constructor that takes a string.
			dNumbers.push_back(new Double(input));
		}
		else {
			//cout << input << " is a integer" << endl;
			//When you add a value to one of the vectors you should use new and call the constructor that takes a string.
			iNumbers.push_back(new Integer(input));
		}

	}
	//Once you have the file parsed create an overloaded writeNumbers function.
	//One of these functions should take a vector of pointers to the Integer class, 
	//the other should take a vector of pointers to the Double class. 
	writeNumbers(iNumbers);
	writeNumbers(dNumbers);
	cout << "numbers.txt file is parsed, open integer.txt and double.txt." << endl;
	m->waitKey();
}

void writeNumbers(vector<Integer*> iNumbers)
{
	//file containing integers
	ofstream outfileInteger("integer.txt");
	if (!outfileInteger) {
		cout << "Unable to create integer.txt for write" << endl;
	}
	//looping through the vector containing pointers to Integer Class
	//and writing integer values to integer.txt file.
	vector<Integer*>::iterator p;
	for (p = iNumbers.begin(); p != iNumbers.end(); p++) {
		//You created a toString function and added to your classes. 
		//You should use this function to write the string to the text file.
		outfileInteger << (*p)->toString() << endl;
	}
	outfileInteger.close(); //closing file
}

void writeNumbers(vector<Double*> dNumbers)
{
	//file containing doubles
	ofstream outfileDouble("double.txt");
	if (!outfileDouble) {
		cout << "Unable to create double.txt for write" << endl;
	}
	//looping through the vector containing pointers to Double Class
	//and writing double values to double.txt file.
	vector<Double*>::iterator p;
	for (p = dNumbers.begin(); p != dNumbers.end(); p++) {
		//You created a toString function and added to your classes. 
		//You should use this function to write the string to the text file.
		outfileDouble << (*p)->toString() << endl;
	}
	outfileDouble.close(); //closing file
}

void assignment12()
{
	Menu *m = Menu::Instance();
	vector <Number*> vInteger;
	cout << boolalpha;

	cout << "========Testing for all functionality of Integer class===========" << endl;
	vInteger.push_back(new Integer);
	vInteger.push_back(new Integer("5"));
	vInteger.push_back(new Integer("3"));
	vInteger.push_back(new Integer("4.5"));
	vInteger.push_back(new Integer("p"));
	Integer i1("5");
	Integer i2("3");
	vInteger.push_back(new Integer(i1 + i2));
	vInteger.push_back(new Integer(i1 - i2));
	vInteger.push_back(new Integer(i1 * i2));
	vInteger.push_back(new Integer(i1 / i2));
	int y = 2;
	vInteger.push_back(new Integer(i1 + y));
	vInteger.push_back(new Integer(i1 - y));
	vInteger.push_back(new Integer(i1 * y));
	vInteger.push_back(new Integer(i1 / y));
	vInteger.push_back(new Integer(i1));
	vInteger.push_back(new Integer(5));
	vInteger.push_back(new Integer(923.5));
	Integer x = 623;
	vInteger.push_back(new Integer(623));
	
	//vector printing
	vector <Number*>::iterator p;
	for (p = vInteger.begin(); p != vInteger.end(); p++) {
		cout << (*p)->toString() << " " << (*p)->isNaN() << endl;
	}
	
	cout << "===========Testing for all functionality of Double class============" << endl;
	vector <Number*> vDouble;
	vDouble.push_back(new Double);
	vDouble.push_back(new Double("5..0"));
	vDouble.push_back(new Double("3"));
	vDouble.push_back(new Double("4.5"));
	vDouble.push_back(new Double("p"));
	Double d1("4.5");
	Double d2("3");
	vDouble.push_back(new Double(d1 + d2));
	vDouble.push_back(new Double(d1 - d2));
	vDouble.push_back(new Double(d1 * d2));
	vDouble.push_back(new Double(d1 / d2));
	double y1 = 2.3;
	vDouble.push_back(new Double(d1 + y1));
	vDouble.push_back(new Double(d1 - y1));
	vDouble.push_back(new Double(d1 * y1));
	vDouble.push_back(new Double(d1 / y1));
	vDouble.push_back(new Double(d1));
	vDouble.push_back(new Double("51.0.8."));
	vDouble.push_back(new Double(5));
	vDouble.push_back(new Double(923.5));
	vDouble.push_back(new Double(34.57));

	//vector printing
	vector <Number*>::iterator p1;
	for (p1 = vDouble.begin(); p1 != vDouble.end(); p1++) {
		cout << (*p1)->toString() << " " << (*p1)->isNaN() << endl;
	}
	m->waitKey();
}

void Exit()
{

	cout << "GoodBye" << endl;
	exit(0);
}

