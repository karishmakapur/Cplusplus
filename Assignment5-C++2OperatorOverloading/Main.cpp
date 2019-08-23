/*
Class: CSIS-123A-3738
Name: Karishma Kapur
ID: 0558326
9/12/18
Assignment 5 Operator Overloading
Main.cpp file
Creating a menu that allows you test the add, sub, mul, div functions for instances of both classes
*/
#include <iostream>
#include <cstdlib>
#include "Menu.h"
#include "Integer.h"
#include "Double.h"


using namespace std;
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

void Exit();



Menu m;
int main() {

	//Object Doubles
	m.addMenuItem("1.  Doubles Object - Add ", DoubleAdd);
	m.addMenuItem("2.  Doubles Object - Subtract ", DoubleSub);
	m.addMenuItem("3.  Doubles Object - Multiply ", DoubleMul);
	m.addMenuItem("4.  Doubles Object - Divide ", DoubleDiv);

	//Primitive doubles
	m.addMenuItem("5.  Doubles primitive - Add  ", doubleAdd);
	m.addMenuItem("6.  Doubles primitive - Subtract ", doubleSub);
	m.addMenuItem("7.  Doubles primitive - Multiply ", doubleMul);
	m.addMenuItem("8.  Doubles primitive - Divide ", doubleDiv);


	//Object Integers
	m.addMenuItem("9.  Integers Object - Add   ", IntegerAdd);
	m.addMenuItem("10. Integers Object - Subtract ", IntegerSub);
	m.addMenuItem("11. Integers Object - Multiply ", IntegerMul);
	m.addMenuItem("12. Integers Object - Divide ", IntegerDiv);


	//Primitive Integers
	m.addMenuItem("13. Integers primitive - Add ", integerAdd);
	m.addMenuItem("14. Integers primitive - Subtract ", integerSub);
	m.addMenuItem("15. Integers primitive - Multiply ", integerMul);
	m.addMenuItem("16. Integers primitive - Divide ", integerDiv);

	//comparing two Double Objects
	m.addMenuItem("17. Compare two Double Objects using Equal operator ", DoubleEqualCompare);
	m.addMenuItem("18. Compare two Double Objects using Not Equal operator", DoubleNotEqualCompare);

	//comparing 1 Double Object and 1 primitive double
	m.addMenuItem("19. Compare 1 Double Object and 1 primitive double using Equal Operator ", doubleEqualCompare);
	m.addMenuItem("20. Compare 1 Double Object and 1 primitive double using Not Equal Operator ", doubleNotEqualCompare);

	//comparing two Integer Objects
	m.addMenuItem("21. Compare 2 Integer Objects using Equal Operator ", IntegerEqualCompare);
	m.addMenuItem("22. Compare 2 Integer Objects using Not Equal Operator ", IntegerNotEqualCompare);

	//comparing 1 integer object and 1 primitive int
	m.addMenuItem("23. Compare 1 Integer Object and 1 primitive int using Equal Operator ", intEqualCompare);
	m.addMenuItem("24. Compare 1 Integer Object and 1 primitive int using Not Equal Operator ", intNotEqualCompare);

	//Exit
	m.addMenuItem("25.  Exit", Exit);

	m.runMenu();
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
	Double d1, d2, d3; //instantiating 3 Double objects; d1, d2 for input and d3 for storing result
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	d1 = di1; //setting the d1 Object with di1 value
	d2 = di2; //setting d2 Object with di2 value
	d3 = d1 + d2;
	cout << "adding two Double objects: " << d1.toDouble() << " + " << d2.toDouble() << " = " << d3.toDouble() << endl << endl;

	m.waitKey();

}

//subtracting two Double objects
void DoubleSub()
{
	double di1, di2;//instantiating two primitive doubles for input
	Double d1, d2, d3; //instantiating 3 Double objects; d1, d2 for input and d3 for storing result
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	d1 = di1; //setting the d1 Object with di1 value
	d2 = di2; //setting d2 Object with di2 value
	d3 = d1 - d2; //subtracting two Double objects and storing result in d3

	cout << "subtracting two Double objects: " << d1.toDouble() << " - " << d2.toDouble() << " = " << d3.toDouble() << endl << endl;

	m.waitKey();
}

//multiplying two Double objects
void DoubleMul()
{
	double di1, di2;//instantiating two primitive doubles for input
	Double d1, d2, d3; //instantiating 3 Double objects; d1, d2 for input and d3 for storing result
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	d1 = di1; //setting the d1 Object with di1 value
	d2 = di2; //setting d2 Object with di2 value
	d3 = d1 * d2; //multiplying two Double objects and storing result in d3
	cout << "multiplying two Double objects: " << d1.toDouble() << " * " << d2.toDouble() << " = " << d3.toDouble() << endl << endl;

	m.waitKey();
}

//dividing two Double objects
void DoubleDiv()
{
	double di1, di2;//instantiating two primitive doubles for input
	Double d1, d2, d3; //instantiating 3 Double objects; d1, d2 for input and d3 for storing result
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	d1 = di1; //setting the d1 Object with di1 value
	d2 = di2; //setting d2 Object with di2 value
	d3 = d1 / d2; //dividing two Double objects and storing result in d3
	cout << "dividing two Double objects: " << d1.toDouble() << " / " << d2.toDouble() << " = " << d3.toDouble() << endl << endl;

	m.waitKey();
}

//adding a Double object & a primitive double
void doubleAdd()
{
	double di1, di2;//instantiating two primitive doubles for input
	Double d1, d2;//instantiating 2 Double objects; d1 for input and d2 for storing result
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	d1 = di1; //setting the d1 Object with di1 value
	d2 = d1 + di2;//adding a Double objects and a primitive double and storing result in d2
	cout << "adding a Double object & a primitive double: " << d1.toDouble() << " + " << di2 << " = " << d2.toDouble() << endl << endl;

	m.waitKey();
}

//subtracting a Double object & a primitive double
void doubleSub()
{
	double di1, di2;//instantiating two primitive doubles for input
	Double d1, d2;//instantiating 2 Double objects; d1 for input and d2 for storing result
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	d1 = di1; //setting the d1 Object with di1 value
	d2 = d1 - di2;//subtracting a Double objects and a primitive double and storing result in d2
	cout << "subtracting a Double object & a primitive double: " << d1.toDouble() << " - " << di2 << " = " << d2.toDouble() << endl << endl;

	m.waitKey();
}

//multiplying a Double object & a primitive double
void doubleMul()
{
	double di1, di2;//instantiating two primitive doubles for input
	Double d1, d2;//instantiating 2 Double objects; d1 for input and d2 for storing result
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	d1 = di1; //setting the d1 Object with di1 value
	d2 = d1 * di2;//multiplying a Double objects and a primitive double and storing result in d2
	cout << "multiplying a Double object & a primitive double: " << d1.toDouble() << " * " << di2 << " = " << d2.toDouble() << endl << endl;

	m.waitKey();
}

//dividing a Double object & a primitive double
void doubleDiv()
{
	double di1, di2;//instantiating two primitive doubles for input
	Double d1, d2;//instantiating 2 Double objects; d1 for input and d2 for storing result
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	d1 = di1; //setting the d1 Object with di1 value
	d2 = d1 / di2;//dividing a Double objects and a primitive double and storing result in d2
	cout << "dividing a Double object & a primitive double: " << d1.toDouble() << " / " << di2 << " = " << d2.toDouble() << endl << endl;

	m.waitKey();
}

//adding two Integer objects
void IntegerAdd()
{
	int Ii1, Ii2;//instantiating two primitive integers for input
	Integer i1, i2, i3; //instantiating 3 Integer objects; i1, i2 for input and i3 for storing result
	inputIntegers(Ii1, Ii2);//calling inputIntegers method to get two primitive ints
	i1 = Ii1; //setting the i1 Object with Ii1 value
	i2 = Ii2; //setting i2 Object with Ii2 value
	i3 = i1 + i2; //adding two Integer objects and storing result in i3
	cout << "adding two Integer objects: " << i1.toInt() << " + " << i2.toInt() << " = " << i3.toInt() << endl << endl;

	m.waitKey();
}

//subtracting two Integer objects
void IntegerSub()
{
	int Ii1, Ii2;//instantiating two primitive integers for input
	Integer i1, i2, i3; //instantiating 3 Integer objects; i1, i2 for input and i3 for storing result
	inputIntegers(Ii1, Ii2);//calling inputIntegers method to get two primitive ints
	i1 = Ii1; //setting the i1 Object with Ii1 value
	i2 = Ii2; //setting i2 Object with Ii2 value
	i3 = i1 - i2; //subtracting two Integer objects and storing result in i3
	cout << "subtracting two Integer objects: " << i1.toInt() << " - " << i2.toInt() << " = " << i3.toInt() << endl << endl;

	m.waitKey();
}

//multiplying two Integer objects
void IntegerMul()
{
	int Ii1, Ii2;//instantiating two primitive integers for input
	Integer i1, i2, i3; //instantiating 3 Integer objects; i1, i2 for input and i3 for storing result
	inputIntegers(Ii1, Ii2);//calling inputIntegers method to get two primitive ints
	i1 = Ii1; //setting the i1 Object with Ii1 value
	i2 = Ii2; //setting i2 Object with Ii2 value
	i3 = i1 * i2; //multiplying two Integer objects and storing result in i3
	cout << "multiplying two Integer objects: " << i1.toInt() << " * " << i2.toInt() << " = " << i3.toInt() << endl << endl;

	m.waitKey();
}

//dividing two Integer objects
void IntegerDiv()
{
	int Ii1, Ii2;//instantiating two primitive integers for input
	Integer i1, i2, i3; //instantiating 3 Integer objects; i1, i2 for input and i3 for storing result
	inputIntegers(Ii1, Ii2);//calling inputIntegers method to get two primitive ints
	i1 = Ii1; //setting the i1 Object with Ii1 value
	i2 = Ii2; //setting i2 Object with Ii2 value
	i3 = i1 / i2; //dividing two Integer objects and storing result in i3
	cout << "dividing two Integer objects: " << i1.toInt() << " / " << i2.toInt() << " = " << i3.toInt() << endl << endl;

	m.waitKey();
}

//adding an Integer object and a primitive integer
void integerAdd()
{
	int Ii1, Ii2;//instantiating two primitive integers for input
	Integer i1, i2; //instantiating 2 Integer objects; i1 for input and i2 for storing result
	inputIntegers(Ii1, Ii2);//calling inputIntegers method to get two primitive ints
	i1 = Ii1; //setting the i1 Object with Ii1 value
	i2 = i1 + Ii2; //adding an Integer object and a primitive integer and storing result in i2
	cout << "adding an Integer object and a primitive integer: " << i1.toInt() << " + " << Ii2 << " = " << i2.toInt() << endl << endl;

	m.waitKey();
}

//subtracting an Integer object and a primitive integer
void integerSub()
{
	int Ii1, Ii2;//instantiating two primitive integers for input
	Integer i1, i2; //instantiating 2 Integer objects; i1 for input and i2 for storing result
	inputIntegers(Ii1, Ii2);//calling inputIntegers method to get two primitive ints
	i1 = Ii1; //setting the i1 Object with Ii1 value
	i2 = i1 - Ii2; //subtracting an Integer object and a primitive integer and storing result in i2
	cout << "subtracting an Integer object and a primitive integer: " << i1.toInt() << " - " << Ii2 << " = " << i2.toInt() << endl << endl;

	m.waitKey();
}

//multiplying an Integer object and a primitive integer
void integerMul()
{
	int Ii1, Ii2;//instantiating two primitive integers for input
	Integer i1, i2; //instantiating 2 Integer objects; i1 for input and i2 for storing result
	inputIntegers(Ii1, Ii2);//calling inputIntegers method to get two primitive ints
	i1 = Ii1; //setting the i1 Object with Ii1 value
	i2 = i1 * Ii2; //multiplying an Integer object and a primitive integer and storing result in i2
	cout << "multiplying an Integer object and a primitive integer: " << i1.toInt() << " * " << Ii2 << " = " << i2.toInt() << endl << endl;

	m.waitKey();
}

//dividing an Integer object and a primitive integer
void integerDiv()
{
	int Ii1, Ii2;//instantiating two primitive integers for input
	Integer i1, i2; //instantiating 2 Integer objects; i1 for input and i2 for storing result
	inputIntegers(Ii1, Ii2);//calling inputIntegers method to get two primitive ints
	i1 = Ii1; //setting the i1 Object with Ii1 value
	i2 = i1 / Ii2; //dividing an Integer object and a primitive integer and storing result in i2
	cout << "dividing an Integer object and a primitive integer: " << i1.toInt() << " / " << Ii2 << " = " << i2.toInt() << endl << endl;

	m.waitKey();
}
void DoubleEqualCompare()
{
	double di1, di2;//instantiating two primitive doubles for input
	Double d1, d2; //instantiating 2 Double objects; d1 and d2 for input
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	d1 = di1; //setting the d1 Object with di1 value
	d2 = di2; //setting d2 Object with di2 value
	cout << "comparing two Double objects: " << d1.toDouble() << " == " << d2.toDouble() << (d1 == d2 ? " -> Equal" : " -> Not Equal") << endl << endl;

	m.waitKey();
}
void DoubleNotEqualCompare()
{
	double di1, di2;//instantiating two primitive doubles for input
	Double d1, d2; //instantiating 2 Double objects; d1 and d2 for input
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	d1 = di1; //setting the d1 Object with di1 value
	d2 = di2; //setting d2 Object with di2 value
	cout << "comparing two Double objects: " << d1.toDouble() << " != " << d2.toDouble() << (d1 != d2 ? " -> Not Equal" : " -> Equal") << endl << endl;

	m.waitKey();
}
void doubleEqualCompare()
{
	double di1, di2;//instantiating two primitive doubles for input
	Double d1; //instantiating 1 Double object for input
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	d1 = di1; //setting the d1 Object with di1 value
	cout << "comparing two Double objects: " << d1.toDouble() << " == " << di2 << (d1 == di2 ? " -> Equal" : " -> Not Equal") << endl << endl;

	m.waitKey();
}
void doubleNotEqualCompare()
{

	double di1, di2;//instantiating two primitive doubles for input
	Double d1; //instantiating 1 Double object for input
	inputDouble(di1, di2);//calling inputDouble method to get two primitive doubles
	d1 = di1; //setting the d1 Object with di1 value
	cout << "comparing two Double objects: " << d1.toDouble() << " != " << di2 << (d1 != di2 ? " -> Not Equal" : " -> Equal") << endl << endl;

	m.waitKey();
}
void IntegerEqualCompare()
{
	int Ii1, Ii2;//instantiating two primitive int for input
	Integer i1, i2; //instantiating 2 Integer objects; i1 and i2 for input
	inputIntegers(Ii1, Ii2);//calling inputInteger method to get two primitive ints
	i1 = Ii1; //setting the i1 Object with Ii1 value
	i2 = Ii2; //setting i2 Object with Ii2 value
	cout << "comparing two Integer objects: " << i1.toInt() << " == " << i2.toInt() << (i1 == i2 ? " -> Equal" : " -> Not Equal") << endl << endl;

	m.waitKey();
}
void IntegerNotEqualCompare()
{
	int Ii1, Ii2;//instantiating two primitive int for input
	Integer i1, i2; //instantiating 2 Integer objects; i1 and i2 for input
	inputIntegers(Ii1, Ii2);//calling inputInteger method to get two primitive ints
	i1 = Ii1; //setting the i1 Object with Ii1 value
	i2 = Ii2; //setting i2 Object with Ii2 value
	cout << "comparing two Integer objects: " << i1.toInt() << " != " << i2.toInt() << (i1 != i2 ? " -> Not Equal" : " -> Equal") << endl << endl;

	m.waitKey();
}
void intEqualCompare()
{
	int Ii1, Ii2;//instantiating two primitive int for input
	Integer i1; //instantiating 1 Integer objects for input
	inputIntegers(Ii1, Ii2);//calling inputInteger method to get two primitive ints
	i1 = Ii1; //setting the i1 Object with Ii1 value
	cout << "comparing 1 Integer object and a primitive integer: " << i1.toInt() << " == " << Ii2 << (i1 == Ii2 ? " -> Equal" : " -> Not Equal") << endl << endl;

	m.waitKey();
}
void intNotEqualCompare()
{
	int Ii1, Ii2;//instantiating two primitive int for input
	Integer i1; //instantiating 1 Integer objects for input
	inputIntegers(Ii1, Ii2);//calling inputInteger method to get two primitive ints
	i1 = Ii1; //setting the i1 Object with Ii1 value
	cout << "comparing 1 Integer object and a primitive integer: " << i1.toInt() << " != " << Ii2 << (i1 != Ii2 ? " -> Not Equal" : " -> Equal") << endl << endl;

	m.waitKey();
}
void Exit()
{

	cout << "GoodBye" << endl;
	exit(0);
}

