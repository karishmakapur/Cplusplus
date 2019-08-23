/*
Karishma Kapur
CSIS 123A
ID: 0558326
Date: 12/13/18
Final Project
Project.cpp
Player class implementation
*/

#include "Player.h"
#include <iostream>
#include <iomanip>


//adding player to highest or lowest stack and setting lowest or highest batting average
void Player::addPlayer(string playerName, double batAvg)
{
	//When you read the first name and average at that time it is both the highest and lowest.  
	//You will store the average in variables that keep track of the highest and lowest average. 
	if (HighestNameStack.empty() && LowestNameStack.empty()) {
		this->highestAvg = this->lowestAvg = batAvg;
		this->HighestNameStack.push(playerName);
		this->LowestNameStack.push(playerName);
	}

	//The new average is greater than the highest stored
	else if (batAvg > this->highestAvg) {
		highestAvg = batAvg;
		while (!HighestNameStack.empty()) {
			this->HighestNameStack.pop();
		}
		this->HighestNameStack.push(playerName);
	}

	//The new average is smaller than the highest average
	//then you check to see if it is less than the lowest average found
	else if (batAvg < this->lowestAvg) {
		lowestAvg = batAvg;
		while (!LowestNameStack.empty()) {
			this->LowestNameStack.pop();
		}
		this->LowestNameStack.push(playerName);
		}

	//The new average is equal to the highest average 
	else if (batAvg == this->highestAvg){
		this->HighestNameStack.push(playerName);
	}

	//The average is equal to the lowest average so far
	else if (batAvg == this->lowestAvg) {
		this->LowestNameStack.push(playerName);
	}
}

//printing highest players and batting average
void Player::printHigh()
{
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "The highest batting average is " << this->highestAvg << std::endl;
	std::cout << "\tThe following players have the highest batting average: " << std::endl;
	while (!HighestNameStack.empty()) {
		std::cout << "\t\t" << HighestNameStack.peek(HighestNameStack.size() -1) << std::endl;
		HighestNameStack.pop();
	}
}

//printing lowest player and batting average
void Player::printLow()
{
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "The lowest batting average is " << this->lowestAvg << std::endl;
	std::cout << "\tThe following players have the lowest batting average: " << std::endl;
	while (!LowestNameStack.empty()) {
		std::cout << "\t\t" << LowestNameStack.peek(LowestNameStack.size() -1) << std::endl;
		LowestNameStack.pop();
	}
}
