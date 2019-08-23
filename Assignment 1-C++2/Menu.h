/*
Class: CSIS-123A-3738
Name: Karishma Kapur
ID: 0558326
Assignment #1: Creating a Menu
*/
#pragma once
#ifndef MENU
#define MENU
#include <string>

const int MAXCOUNT = 20;

struct MenuItem {
    std::string descript;
	void(*func)();

};

class Menu {
private:
	MenuItem mi[MAXCOUNT];
	int count;
	void runSelection();
public:
	Menu();
	void runMenu();
	void addMenuItem(std::string description, void(*f)(void));
	void waitKey();
};
#endif 
