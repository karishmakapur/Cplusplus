/*
Class: CSIS-123A-3738
Name: Karishma Kapur
ID: 0558326
9/28/18
Assignment 7 Dynamic Memory
Menu.h file
creating a struct "MenuItem" and a class "Menu"
replacing the array with a vector
*/
#pragma once
#ifndef MENU
#define MENU
#include <string>
#include <vector>

//const int MAXCOUNT = 20;

struct MenuItem {
	std::string descript;
	void(*func)();

};

class Menu {
private:
	//replace array with vector
	//MenuItem mi[MAXCOUNT]
	std::vector<MenuItem> mi;
	int count;
	void runSelection();
public:
	Menu();
	void runMenu();
	void addMenuItem(std::string description, void(*f)(void));
	void waitKey();
};
#endif 
