//INSTRUCTION
//Look for **
//Fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P1 queue
//Your name: Karishma Kapur
//Complier:  g++
//File type: queue.cpp (implementation file for queue class)
//===========================================================

using namespace std;
#include <iostream>
#include "Queue.h"  

// constructor 
//PURPOSE: constructor to create an object 
queue::queue()
{
	rear = -1; //initializing rear variable to -1
	front = 0; //initializing front variable to 0 
	count = 0; //initializing count variable to 0
}

//destructor 
//PURPOSE: destructor to destroy an object
queue::~queue(){}

// PURPOSE: returns true if queue is empty, otherwise false
//PARAMETERS: none needed.
//ALGORITHM: if else statement to determine with the use of the
//count variable if the queue is empty. If it is, return true.
//else return false.
bool queue::isEmpty()
{
	if (count == 0) //checking to see if the count (amount of elements in the queue) is == 0.
	{
		return true; //return true
	}
	else //else if the count is not equal to 0, then the queue is not empty
	{
		return false; //return false
	}
}

// PURPOSE: returns true if queue is full, otherwise false
// PARAMETERS: none needed
//ALGORITHM: if else statement to determine if the queue is full
//based on if the count variable is equal to the MAX_SIZE of the queue
//if the queue is full, return true. Else return false.
bool queue::isFull()
{
	if (count == MAX_SIZE) //checking to see if the queue count (amount of element in queue) is equal to the MAX_SIZE that can be in the queue
	{
		return true; //return true
	}
	else //else if the queue is not full, meaning count != MAX_SIZE
	{
		return false; //return false
	}
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PARAMETER: provide the element (newElem) to be added
//ALGORITHM: if else statement to first see if the queue is full.
//if the queue is full, then you cannot add an element and the
//queue is at overflowed.
//else if the queue is not full, add an element to the rear
//of the queue and increase the count on the elements in the queue
void queue::add(el_t newElem)
{
	if (isFull()) //checking to see if the queue is full
	{
		throw Overflow(); //throw exception
	}
	else
	{
		rear = (rear + 1) % MAX_SIZE; //readjust the rear variable 
		el[rear] = newElem; //add element to the rear of the queue
		count++; //increment the count by 1
	}

}

// PURPOSE: if empty, calls an emergency exit routine
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
//ALGORITHM: if else statement to determine if the queue is empty
//if the queue is empty, then you cannot remove anything
//from the queue, which will throw an underflow exception
//else if the queue is not empty, remove the front element
//and decrease the count of the elements in the queue
void queue::remove(el_t& removedElem)
{
	if (isEmpty()) //checking to see if the queue is empty
	{
		throw Underflow(); //throw exception
	}
	else //else if queue is not empty
	{
		removedElem = el[front]; //remove the front element
		front = (front + 1) % MAX_SIZE; //readjust the front variable
		count--; //decrease the count by 1.
	}
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
//ALGORITHM: if else statement to determine if the queue is
//empty. If queue is empty, throw underflow exception because
//there is nothing in the queue to get.
//if the queue is not empty, put the front element of the queue
//(but do not delete the front element)
//into a variable of the type el_t
void queue::frontElem(el_t& theElem)
{
	if (isEmpty()) //checking to see if the queue is empty
	{
		throw Underflow(); //throw exception
	}
	else //if queue is not empty
	{
		theElem = el[front]; //get the front element and put into variable

	}

}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
// PARAMETERS: none are needed
//ALGORITHM: return the count of the elements in the queue
int queue::getSize()
{
	return count; //returning the amount of elements in the queue
}

// PURPOSE: display everything in the queue horizontally from front to rear
// enclosed in []
// if empty, displays [ empty ]
// PARAMETERS: none are needed
//ALGORITHM: if else statement to see if the queue is empty
//display to the user that the queue is empty.
//else if the queue only has one element, display that 1 element.
//else if the queue is not empty, display the front element 
//of the queue one at a time in a line
void queue::displayAll()
{
	if (isEmpty()) //checking to see if queue is empty
	{
		cout << "[ empty ]" << endl; //displaying that the queue is empty
	}
	else if (count == 1) //checking to see if the queue has only 1 element
	{
		cout << "[" << el[front] << "]"; //displaying the 1 element that is in the queue
	}
	else //if queue has more than 1 element
	{
		int frontElem = front; //local variable to make sure that the front variable defined in queue's header file doesn't change
		cout << "[ "; //putting outside the for loop to ensure it only prints once
		
		//looping through all elements in the queue and printing out one at a time
		for (int i = frontElem, j = 0; j < count; ++j, i = (i + 1) % MAX_SIZE)
		{
			cout << " " << el[i]; //printing the element in the queue

		}
		cout << " ]" << endl; //putting outside the for loop to ensure it only prints once
	}
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//doing remove followed by add.
// PARAMETERS: none needed
//ALGORITHM: if/else if/else statement to see if the queue 
//is empty then throw underflow exception
//else if the queue has 1 element in it, then do nothing
//ellse remove the front element and add the element to the rear of the queue
void queue::goToBack()
{// ** comment a local variable
	el_t element = el[front];
	if (isEmpty()) //checking to see if the queue is empty
	{
		throw Underflow(); //throwing exception
	}
	else if (count == 1) //checking to see if the queue has 1 element
	{
		//does nothing
	}
	else //if the queue has more than one element
	{
		remove(element); //remove the front element
		add(element); //add the element that we just removed to the rear end of the queue
	}
}




