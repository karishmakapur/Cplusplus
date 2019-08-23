/* 
Karishma Kapur
ID: 0558326
Assignment 8
Using a while loop write a simple coin flip game.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main()

{	
	// random
	srand(time(0));

	// variables
	double bank = 10.00, playCost = 1.00, correctGuess = 2.00;
	char playAnswer, headTails, guessChar;
	int guessNum, min = 0, max = 1;
	string firstMessage, lastMessage;

	// welcome statement
	cout << "Welcome to the coin flip game. It cost a dollar to play. " << endl;
	cout << "If you guess correctly you win $2.00." << endl;

	// prime loop
	cout << "Do you want to play (y/n)?" << endl;
	cin >> playAnswer;
	playAnswer = toupper(playAnswer);

	while (playAnswer == 'Y')
	{
		cout << "Your bank is $" << bank << "." << endl;
		cout << "Enter heads or tails (h/t)" << endl;
		cin >> headTails;
		bank -= 1;
		guessNum = rand() % ((max - min) + 1) + min;


		if (guessNum == 0)
		{
			guessChar = 'h';
			lastMessage = " Heads ";
		}
		else
		{
			guessChar = 't';
			lastMessage = " Tails ";
		}

		if (headTails == guessChar)
		{
			bank += 2;
			firstMessage = "Winner, the ";
		}
		else
		{
			firstMessage = "Sorry, you lose. The ";
		}
		cout << firstMessage << " coin flip came out" << lastMessage << endl;

		cout << "Do you want to play again (y/n)?" << endl;
		cin >> playAnswer;
		playAnswer = toupper(playAnswer);
	}
	cout << "Thanks for playing, your bank is $" << bank << endl;
	cout << "Please come again" << endl;
	return 0;
}
