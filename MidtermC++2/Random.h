/*
Karishma Kapur
CSIS 123A
ID: 0558326
10/8/18
Midterm
Random.h file
Contains Random class and prototypes for methods and constructors
*/
#ifndef RANDOM
#define RANDOM

#include "Double.h"
#include "Integer.h"
#include <vector>
using std::vector;
using namespace Karishma;

class Random {
private:
	// private data memebers
	vector<double> RandVector;
	int SHUFFLE_AT; //when to shuffle -> calculated in Random constructors using RESHUFFLE_AT
	unsigned int count = 0; //everytime a next random number is requested, count will be incremented.
	double min; //minimum value for random number generation.
	double max; //maximum value for random number generation.
	double seedValue;
	bool seedFlag;
	//private member methods
	void shuffle();
	void fillVect(double min, double max);
	
public:
	//constants
	const int MAX_RANDOM_NUMBERS = 250; //max random numbers is 250
	const double RESHUFFLE_AT = .90; //90%

	//constructors
	Random(); // Default constructor
	Random(double min, double max);  //generates random numbers between min and max.
	Random(Double min, Double max);  //generates random numbers between min and max using class Double
	Random(int seed);   //seed the random number generator

	//methods
	int nextInt(); // Returns the next random number as an int
	Integer nextInteger(); // Returns the next random number as an Integer class
	double nextDbl(); // Returns the next random number as a primitive double
	Double nextDouble(); // Returns the next random number as a Double class
	void setRange(double min, double max); // Sets the range and recreates random numbers
	void setRange(Double min, Double max); // Sets the range and recreates the random numbers.
};
#endif 
