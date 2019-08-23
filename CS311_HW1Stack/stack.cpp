//INSTRUCTION
//Look for **. (do control-S)
//Update the comments using the HOW TO COMMENT file, 
//  complete exception handling and 
//  finish ClearIt to make this complete - Yoshii (CS311)
// When done, compile stack.cpp to make sure there are no syntax errors.

//=========================================================
//HW#: HW1P1 stack
//Your name: Karishma Kapur
//Complier:  g++
//File type: stack implementation file
//=========================================================

using namespace std;
#include <iostream>
#include "stack.h"

//PURPOSE:  Constructor must initialize top to be -1 to begin with.
//constructor to create an object
stack::stack()
{
	top = -1; //initialiing top variable (private variable) from stack class to -1.
} // indicate an empty stack 

//PURPOSE:  Destructor does not have to do anything since this is a static array.
// destructor  to destroy an object
stack::~stack()
{ }// nothing to do 

//PURPOSE:  checks top and returns true if empty, false otherwise.
// ** In the comment, make sure you define "empty" in terms of top.
//empty = there is nothing in the stack. top = -1.
//ALGORITHM: using if else statement to see if the top variable 
//is equal to -1, meaning the stack is empty
bool stack::isEmpty()
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//PURPOSE: checks top and returns true if full, false otherwise.
//** In the comment, make sure you define "full" in terms of top.
//full = the stack has no more memory left to hold anymore elements
//ALGORITHM: using if else statement to see if top is equal 
//to MAX - 1, meaning the stack is full.
bool stack::isFull()
{
	if (top == MAX - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
//PARAMETER: pass the element (elem) to be pushed 
//ALGORITHM: using if else statement to see if the stack is full,
//if it is full it throws an exception, else pushes
//another element to the stack
void stack::push(el_t elem)
{
	if (isFull())
	{
		throw Overflow();
	}
	else 
	{ 
		top++; 
		el[top] = elem; 
	}
}

//PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
//PARAMETER: provide a holder (elem) for the element popped (pass by ref)
//ALGORITHM: using if else statement to see if the stack is empty,
//if it is empty it throws an exception, else pops
//element from the stack
void stack::pop(el_t& elem)
{
	if (isEmpty())
	{
		throw Underflow();
	}
	else 
	{ 
		elem = el[top];
		top--; 
	}
}

// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
//ALGORITHM: uses if else statement to see if stack is empty, if it is
//it thorws an exception, else it gives back top element from el[].
void stack::topElem(el_t& elem)
{
	if (isEmpty())
	{
		throw Underflow();
	}
	else 
	{ 
		elem = el[top]; 
	}
}

//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//          Otherwise, diplays the elements vertically.
//ALGORITHM: using if else statement to see if stack is empty, if it is
//display to screen [empty], else displays all elements in stack.
void stack::displayAll()
{
	if (isEmpty())
	{
		cout << "[empty]" << endl;
	}
	else
	{
		for (int i = top; i >= 0; i--)
		{
			cout << el[i] << endl;
		}
	}
	cout << "--------------" << endl;
}


//PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
//ALORITHM: using while loop to pop elements one by one from stack to empty it.
void stack::clearIt()
{// ** comment a local variable
	int topElement = top; //local variable topElement, equaled
							//top of stack
	while(!isEmpty())
	{
		pop(el[topElement]); 
	}
}


