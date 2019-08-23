/*
Karishma Kapur
CSIS 123A
ID: 0558326
Date: 12/13/18
Final Project
Project.h
Player class definition
*/
#ifndef PLAYER
#define PLAYER
#include <string>
#include "Stack.h"
using std::string;

class Player {
private:
	//variables
	double battingAverage;
	string playerName;
	double highestAvg;
	double lowestAvg;
	
	//stacks
	Stack<string> HighestNameStack;
	Stack<string> LowestNameStack;
public:
	//constructors
	Player()
		: battingAverage(0.0), playerName(""){};

	//member functions
	void addPlayer(string playerName, double batAvg);
	void printHigh();
	void printLow();
};

#endif // !PLAYER