/*
Class: CSIS-123A-3738
Name: Karishma Kapur
ID: 0558326
Assignment #1: Creating a Menu
*/
#include <iostream>
#include <cstdlib>
#include "Menu.h"


using namespace std;
	void func1();
	void func2();
	void func3();
	void Exit();
	


Menu m;
int main() {
	
	
	m.addMenuItem("1. Function 1 " , func1);
	m.addMenuItem("2. Function 2 ", func2);
	m.addMenuItem("3. Function 3 ", func3);
	m.addMenuItem("4. Exit", Exit);

	m.runMenu();
}

void func1()
{
	
	cout << "This is func1" << endl;
	m.waitKey();


}
void func2()
{
	
	cout << "This is func2" << endl;
	m.waitKey();

}
void func3()
{
	
	cout << "This is func3" << endl;
	m.waitKey();
}
void Exit() 
{
	
	cout << "GoodBye" << endl;
	exit(0);
}

