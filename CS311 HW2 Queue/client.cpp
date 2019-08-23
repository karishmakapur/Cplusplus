//INSTRUCTION
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 
//except for the trace messages

//=========================================================
//HW#: HW1P1 queue
//Your name: Karishma Kapur
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Queue.h"

//Purpose of the program: remove the front element of the queue, append A, B, and C to 
//the string individually and add all 3 to the queue
//Algorithm: 
int main()
{
	queue letters; //creating an object of the Queue class
	el_t front; //creating a el_t variable to hold strings

	letters.add("A"); //adding a string "A" to queue
	letters.add("B"); //adding a string "B" to queue
	letters.add("C"); //adding a string "C" to queue

	//while loop to continue until the queue is full.
	while (!letters.isFull())
	{
		try //try block
		{   
			//removing the front element and displaying to user.
			letters.remove(front);
			cout << "Element removed is: " << front << endl; 

			//adding "A" , "B", and "C" individually to the element that was removed before
			//and then adding the new 3 elements, that just created, to the Queue
			letters.add(front + "A");
			letters.add(front + "B");
			letters.add(front + "C");

			//displaying what is held in queue
			cout << "The Queue holds: ";
			letters.displayAll();

			//for console output purposes
			cout << "_______________________________________________________________________________" << endl << endl;
		}
		catch(queue::Overflow) //catch for overflow exception
		{
			//print to user that the queue is full
			cerr << "Error has occured. The queue is full." << endl;
			exit(1); //exit the program
		}
		catch (queue::Underflow) //catch for underflow exception
		{
			//print to user that the queue is empty
			cerr << "Error has occured. The queue is empty." << endl;
			//exit the program
			exit(1);
		}
	}
	return 0;
}

