/*
Karishma Kapur
CSIS 123A
ID: 0558326
Date: 12/13/18
Final Project
main.cpp
main and main functions
*/
#include <iostream>
#include <fstream>
#include "Player.h"
#include "Stack.h"

using namespace std;

void openFile(ifstream & infile);
void readFile(ifstream & infile, string & name, double & avg);

int main()
{
	ifstream infile; //open file for reading
	string name = " ";
	double avg = 0.0;
	Player p;

	openFile(infile); //opening file, if error then quit program

	//while file is not at the end, then keep reading from file
	while (!infile.eof()) {
		readFile(infile, name, avg);
		p.addPlayer(name, avg);
	}

	p.printHigh(); //printing high averages
	p.printLow(); //printing low averages

	infile.close(); //closing file

	return 0;
}

//opening file
void openFile(ifstream & infile)
{	
	infile.open("avgs.txt");
	if (!infile) { //if the file cannot open, then display message to console and exit program.
		cout << "Unable to open file" << endl;
		exit(0);
	}
}

//reading file and splitting line that is read into 2 varaibles: name and avg.
void readFile(ifstream & infile, string & name, double & avg)
{
	string line;
	getline(infile, line);
	name = line.substr(0, line.find(' '));
	avg = stod(line.substr(line.find(' ') + 1));
}
