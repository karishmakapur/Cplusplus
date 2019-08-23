/*
Class: CSIS-123A-3738
Name: Karishma Kapur
ID: 0558326
Assignment #1: Creating a Menu
*/
#include <iostream>
#include <cstdlib>
#include "Menu.h"
#include <conio.h>

using namespace std;

void Menu::runSelection()
{
	int select;
	cin >> select;
	if (select <= count) {
		this->mi[select - 1].func();
	}
}

Menu::Menu()
	:count(0)
{
}

void Menu::runMenu()
{
	for (;;) {
		system("CLS");
		for (int i = 0; i < count; i++) {
			cout << mi[i].descript << endl;
		}
		runSelection();
	}
}

void Menu::addMenuItem(string description, void(*f)(void))
{
	if (count < MAXCOUNT)
	{
		this->mi[count].func = f;
		this->mi[count].descript = description;
		this->count++;
	}
}
void Menu::waitKey()
{

	cout << "Press any key to continue" << endl;
	while (!_kbhit()); 

	fflush(stdin);
}
