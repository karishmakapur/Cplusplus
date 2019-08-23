/*
Karishma Kapur
CSIS 123A
ID: 0558326
10/8/18
Midterm
Random.cpp file
Contains Implementation of Random class methods and constructors
*/
#include "Random.h"
#include <ctime>
#include <iostream>
#include <cstdlib> 
#include <algorithm> //for random_shuffle

using std::iterator;

void Random::fillVect(double min, double max)
{
	//std::cout << std::boolalpha; //print bool variable, seedFlag, with true or false, as alphabet instead of 0 or 1.
	this->RandVector.clear(); //clearing vector before filling it.
	/*std::cout << "in fillVect -> clear and filling vector: min = " << this->min << " max = " << this->max <<" seedFlag = " 
		<< seedFlag << " seedValue = " << this->seedValue << std::endl;*/
	//if seed value is zero then we will use time(NULL). 
	//else we will use the seed value
	(this->seedFlag == false) ? srand(time(NULL)) : srand(this->seedValue);

	//filling the vector with const int MAX_RANDOM_NUMBERS
	for (int i = 0; i < this->MAX_RANDOM_NUMBERS; i++) {
		//when used in default constructor RAND_MAX is same as max and min is 0
		//if you look carefully we are first dividing my RAND_MAX and then multipying it by RAND_MAX
		//so the result will always be the starting number produced by rand(), which is an integer
		double r = (((double)rand() / (double)RAND_MAX) * (max - min)) + min;
		this->RandVector.push_back(r);
	}
	//after vector is filled, always shuffle the vector
	this->shuffle();
	/*std::cout << "FILLVECT SHUFFLING " << std::endl;*/
}

void Random::shuffle()
{
	random_shuffle(RandVector.begin(), RandVector.end());
}

Random::Random()
{
	this->SHUFFLE_AT = (int)(MAX_RANDOM_NUMBERS * RESHUFFLE_AT);
	this->seedValue = 0;
	this->seedFlag = false;
	//this->setRange(0, RAND_MAX);
	
}

//Since the signatures were provided for Random(double min, double max), I am using the same signatures
//but I would have prefered to references for formal parameters.
Random::Random(double min, double max)
{
	this->SHUFFLE_AT = (int)(MAX_RANDOM_NUMBERS * RESHUFFLE_AT);
	this->seedValue = 0;
	this->seedFlag = false;
	this->setRange(min, max);
}

//Since the signatures were provided for Random(Double min, Double max), I am using the same signatures
//but I would have prefered to references for formal parameters.
Random::Random(Double min, Double max)
{
	this->SHUFFLE_AT = (int)(MAX_RANDOM_NUMBERS * RESHUFFLE_AT);
	this->seedValue = 0;
	this->seedFlag = false;
	this->setRange(min, max);
}

//Since the signatures were provided for Random(int seed), I am using the same signatures
//but I would have prefered to references for formal parameters.
Random::Random(int seed)
{
	this->SHUFFLE_AT = (int)(MAX_RANDOM_NUMBERS * RESHUFFLE_AT);
	//this->min = 0;
	//this->max = RAND_MAX;
	this->seedValue = seed;
	this->seedFlag = true;
	//this->fillVect(0, RAND_MAX);
	this->setRange(0,RAND_MAX);
}

//Since the signatures were provided for nextInt(), I am using the same signatures
//but I would have prefered to use pointers and/or references for return types and
//formal parameters.
int Random::nextInt()
{
	return (static_cast<int>(this->nextDbl()));

}

//Since the signatures were provided for nextInteger(), I am using the same signatures
//but I would have prefered to use pointers and/or references for return types and
//formal parameters.
Integer Random::nextInteger()
{
	return (Integer(this->nextDbl()));
}

//Since the signatures were provided for nextDbl(), I am using the same signatures
//but I would have prefered to use pointers and/or references for return types and
//formal parameters.
double Random::nextDbl()
{
	
	if (this->count >= this->SHUFFLE_AT) {
		this->count = 0;
		//as per discussion board, a question asked by Stefan, when we reach 90%,
		//we should clear, refill, and shuffle with the same process as we did when 
		//filling vector for the first time.
		/*std::cout << "CLEAR, REFILL, AND SHUFFLING WITH SAME MIN AND MAX AT " << RESHUFFLE_AT * 100 << "%" <<  std::endl;*/
		this->fillVect(this->min,this->max);
		
	}
	return RandVector.at(this->count++);
}

//Since the signatures were provided for nextDouble(), I am using the same signatures
//but I would have prefered to use pointers and/or references for return types and
//formal parameters.
Double Random::nextDouble()
{
	return (Double(this->nextDbl()));
}

//Since the signatures were provided for setRange(), I am using the same signatures
//but I would have prefered to use pointers and/or references for formal parameters.
//Sets the range and recreates the random numbers.
void Random::setRange(double min, double max)
{
	//this->RandVector.clear(); //clearing vector before setting the range and (re)filling it.
	//clear will always happen in fillVect
	this->min = min;
	this->max = max;
	this->fillVect(this->min, this->max);
}

//Since the signatures were provided for setRange(), I am using the same signatures
//but I would have prefered to use pointers and/or references for formal parameters.
//Sets the range and recreates the random numbers.
void Random::setRange(Double min, Double max)
{
	//this->RandVector.clear(); //clearing vector before setting the range and (re)filling it.
	//clear will always happen in fillVect
	this->min = min.toDouble();
	this->max = max.toDouble();
	this->fillVect(this->min,this->max);
}


