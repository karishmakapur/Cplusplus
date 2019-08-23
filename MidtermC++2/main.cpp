/*
Karishma Kapur
CSIS 123A
ID: 0558326
10/8/18
Midterm
main.cpp file
Contains objects from Random, Integer, and Double classes and tests their functionality
*/
#include <iostream>
#include "Double.h"
#include "Integer.h"
#include "Random.h"

using namespace std;
using namespace Karishma;

int main()
{
	//default constructor
	cout << "================Default Random constructor and calling nextDbl()==================" << endl;
	Random r1;
	r1.setRange(0, RAND_MAX);
	cout << showpoint;
	for (int i = 0; i < r1.MAX_RANDOM_NUMBERS; i++) {
		cout << r1.nextDbl() << endl;
	}
	
	//overloaded Random constructor that takes primitive doubles
	cout << "=======Overloaded Random constructor that takes primitive doubles and calling nextDbl()======" << endl;
	Random r2(5.6, 23.9);
	//calling nextDbl()
	for (int i = 0; i < r2.MAX_RANDOM_NUMBERS; i++) {
		cout << r2.nextDbl() << endl;
	}

	//overloaded Random constructor that takes Double class
	cout << "=======Overloaded Random constructor that takes Double class and calling NextDouble().toDouble()======" << endl;
	Double min(4.5), max(28.9);
	Random r3(min, max);
	//calling NextDouble().toDouble()
	for (int i = 0;i < r3.MAX_RANDOM_NUMBERS; i++) {
		cout << r3.nextDouble().toDouble() << endl;
	}

	//overloaded Random constructor that takes int seed
	cout << "=====overloaded Random constructor that takes int seed and calling nextDbl()======" << endl;
	Random r4(0);
	for (int i = 0; i < r4.MAX_RANDOM_NUMBERS; i++) {
		cout << r4.nextDbl() << endl;
	}

	//overloaded Random constructor that takes primitive doubles
	//demonstrating nextInt() method
	cout << "=======Overloaded Random constructor that takes primitive doubles and calling nextInt()======" << endl;
	Random r5(2.4, 67.5);
	//calling nextInt()
	for (int i = 0; i < r5.MAX_RANDOM_NUMBERS; i++) {
		cout << r5.nextInt() << endl;
	}

	//overloaded Random constructor that takes primitive doubles
	//demonstrating nextInteger() method
	cout << "=======Overloaded Random constructor that takes primitive double and calling nextInteger().toInt()======" << endl;
	Random r6(3.5, 78.7);
	//calling nextInteger().toInt()
	for (int i = 0; i < r6.MAX_RANDOM_NUMBERS; i++) {
		cout << r6.nextInteger().toInt() << endl;
	}
	
	////showing that once random number vector is filled that it does not matter which NEXT function you use
	////example: nextInt(), nextInteger(), nextDbl(), nextDouble()
	////count will show the correct value and reshuffle will work properly also.
	//cout << "================Default Random constructor and calling all next methods==================" << endl;
	//Random r7;
	//cout << showpoint;
	//for (int i = 0; i < (int)(r7.MAX_RANDOM_NUMBERS/4); i++) {
	//	cout << "nextDbl() = " << r7.nextDbl() << endl;
	//	cout << "nextDouble().toDouble() = " <<  r7.nextDouble().toDouble() << endl;
	//	cout << "nextInt() = " << r7.nextInt() << endl;
	//	cout << "nextInteger().toInt() = " << r7.nextInteger().toInt() << endl;
	//}
}