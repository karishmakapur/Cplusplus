/*
Class: CSIS-123A-3738
Name: Karishma Kapur
ID: 0558326
11/11/18
Assignment 12 - Polymorphism
Menu.cpp file
creating the definitions for the methods in the class "Menu"
*/
#include <iostream>
#include <cstdlib>
#include "Menu.h"
#include <conio.h>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::bad_alloc;

namespace Karishma {
	Menu* Menu::mInstance = 0;

	void Menu::runSelection()
	{

		int select;
		cin >> select;

		if (select <= count) {

			this->mi.at(select - 1).func();

		}

	}

	Menu::Menu()
		:count(0)
	{
		/*if (mInstance == 0) {
			mInstance = this;
		}
		*/
	}

	void Menu::runMenu()
	{

		for (;;) {
			system("CLS");
			std::vector<MenuItem>::iterator menuIter;
			for (menuIter = this->mi.begin(); menuIter < this->mi.end(); menuIter++) {
				cout << (*menuIter).descript << endl;
			}
			runSelection();
		}
	}

	void Menu::addMenuItem(string description, void(*f)(void))
	{
		MenuItem temp;
		temp.descript = description;
		temp.func = f;
		this->mi.push_back(temp);
		this->count++;


	}
	void Menu::waitKey()
	{

		cout << "Press any key to continue" << endl;
		while (!_kbhit());

		fflush(stdin);
	}

	Menu * Menu::Instance()
	{
		try {
			if (mInstance == 0) {
				mInstance = new Menu;
			}
			return mInstance;
		}
		catch (const bad_alloc& e) {
			cout << "Menu instance - cannot allocate memory " << e.what() << endl;
			exit(EXIT_FAILURE);
		}
	}
}