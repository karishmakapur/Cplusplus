/*
Class: CSIS-123A-3738
Name: Karishma Kapur
ID: 0558326
11/1/18
Assignment 11 Inheritance
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
namespace Karishma {

	struct MenuItem {
		std::string descript;
		void(*func)();
#pragma warning(suppress: 26495)
	};

	class Menu {
	private:
		//replace array with vector
		//MenuItem mi[MAXCOUNT]
		std::vector<MenuItem> mi;
		int count;
		void runSelection();
		static Menu* mInstance;
		Menu();
	public:
		void runMenu();
		void addMenuItem(std::string description, void(*f)(void));
		void waitKey();
		static Menu* Instance();

	};
}
#endif 
