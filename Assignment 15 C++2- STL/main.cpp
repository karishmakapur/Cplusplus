/*
Karishma Kapur
CSIS 123A
ID: 0558326
Date: 12/6/18
Assignment #15  STL
main.cpp
*/

#include <iostream>
#include <string>
#include <set>
using namespace std;

//Node class
template <typename tn>
class Node {
private:
	tn Data;
	int pri;
public:
	Node(tn s, int i) : Data(s), pri(i) {} //constructor
	bool operator < (const Node& n) const { return this->pri < n.pri; }
	const tn& getData() const { return this->Data; }
	const int& getID() const { return this->pri; }
};

//priQue class
//In this assignment you are going to create a priority queue class called priQue.
template<typename tn>
class priQue : public multiset<Node<tn>>
{
public:
	//enqueue - Add an element to the queue
	// because of the example
	//que.enqueue("Hello", 3); que.enqueue("Goodbye", 9);
	//I designed this function to not have a return type.
	void enqueue(const tn& data, const int& pri);

	//dequeue - Remove element from the front of the queue
	//because of the example
	//string s = que.dequeue();
	//I designed this funtion to have a tn return type (a template)
	const tn& dequeue();

	//peek - Return value at front of queue do not remove it
	const tn& peek() const;

	// peekpriority - for test purpose only
	const int& peekPriority() const;

	//size - Returns the number of items in the queue.
	const int& size();
};

//Functions code

//Because of the example shown
//que.enqueue("Hello", 3);
//I created the parameters as such:
template<typename tn>
void priQue<tn>::enqueue(const tn& data, const int& pri)
{
	typedef Node<tn> newNode;
	newNode n(data, pri);
	//this will return us an iterator
	//but since my return type is void,
	//I am not storing the iterator
	//for the newly inserted node.
	this->insert(n);
}

template<typename tn>
const tn& priQue<tn>::dequeue()
{
	//this will return us an iterator
	//but since my return type is a template,
	//I am not storing the iterator
	//to the element that follows
	//the last element removed
	this->erase(this->begin());
	tn temp{}; //instantiating variable
	return ((this->size() > 0) ? this->peek() : temp);
}

template<typename tn>
const tn&  priQue<tn>::peek() const
{
	return this->begin()->getData();
}

template<typename tn>
const int & priQue<tn>::peekPriority() const
{
	return this->begin()->getID();
}

template<typename tn>
const int & priQue<tn>::size()
{
	return this->multiset<Node<tn>>::size();
}


//============MAIN FUNCTIONS=================
void testStrPriQue();
void testIntPriQue();
void testDoublePriQue();



//main function codes
void testStrPriQue()
{
	typedef priQue <string> strPriQue;
	strPriQue stringPQ;
	strPriQue::iterator it;

	//filling string pri queue
	stringPQ.enqueue(" is ", 3);
	stringPQ.enqueue(" code. ", 9);
	stringPQ.enqueue(" Hi ", 1);
	stringPQ.enqueue(" This ", 8);
	stringPQ.enqueue(" karishma. ", 3);
	stringPQ.enqueue(" Goodbye. ", 9);
	stringPQ.enqueue(" my name ", 1);
	stringPQ.enqueue(" is my  ", 8);

	//testing string pri queue

	cout << "\nTesting string Priority Queue:... " << endl;
	cout << " \nQueue holds follwing data(priorities) : " << endl;
	for (it = stringPQ.begin(); it != stringPQ.end(); it++)
	{
		cout << it->getData() << "(" << it->getID() << ") ";
	}
	while (stringPQ.size() > 1)
	{
		//displaying size
		//the reason for the to_string() was because when complied on x64 without to_string() the output is altered.
		cout << "\n\tCurrent size of string Priority Queue = " << to_string(stringPQ.size()) << endl;
		//peeking element at the front of the que and the priority of the element. 
		cout << "\tData in front of queue = " << stringPQ.peek()
			<< " (" << stringPQ.peekPriority() << ")" << endl;
		//removing the element from the front of the que and returns the new front element in the que.
		cout << "\tAfter removing, new front of queue = " << stringPQ.dequeue() << endl << endl;
	}





}

void testIntPriQue()
{
	typedef priQue <int> intPriQue;
	intPriQue intPQ;
	intPriQue::iterator it;

	//filling integer pri queue
	intPQ.enqueue(3, 3);
	intPQ.enqueue(7, 9);
	intPQ.enqueue(1, 1);
	intPQ.enqueue(5, 8);
	intPQ.enqueue(4, 3);
	intPQ.enqueue(8, 9);
	intPQ.enqueue(2, 1);
	intPQ.enqueue(6, 8);

	//testing integer pri que

	cout << "\nTesting integer Priority Queue:..." << endl;
	cout << " \nQueue holds follwing data(priorities) : " << endl;
	for (it = intPQ.begin(); it != intPQ.end(); it++)
	{
		cout << it->getData() << "(" << it->getID() << ") ";
	}
	while (intPQ.size() > 1)
	{
		//displaying size
		//the reason for the to_string() was because when complied on x64 without to_string() the output is altered.
		cout << "\n\tCurrent size of integer Priority Queue = " << to_string(intPQ.size()) << endl;
		//peeking element at the front of the que and the priority of the element. 
		cout << "\tData in front of queue = " << intPQ.peek()
			<< " (" << intPQ.peekPriority() << ")" << endl;
		//removing the element from the front of the que and returns the new front element in the que.
		cout << "\tAfter removing, new front of queue = " << intPQ.dequeue() << endl << endl;

	}
}

void testDoublePriQue()
{
	typedef priQue <double> doublePriQue;
	doublePriQue doublePQ;
	doublePriQue::iterator it;

	//filling double pri queue
	doublePQ.enqueue(3.1, 3);
	doublePQ.enqueue(7.1, 9);
	doublePQ.enqueue(1.1, 1);
	doublePQ.enqueue(5.1, 8);
	doublePQ.enqueue(4.1, 3);
	doublePQ.enqueue(8.1, 9);
	doublePQ.enqueue(2.1, 1);
	doublePQ.enqueue(6.1, 8);

	//testing double pri queue
	cout << "\nTesting double Priority Queue:..." << endl;
	cout << "\nQueue holds follwing data(priorities) : " << endl;
	for (it = doublePQ.begin(); it != doublePQ.end(); it++)
	{
		cout << it->getData() << "(" << it->getID() << ") ";
	}
	while (doublePQ.size() > 1)
	{
		//displaying size
		//the reason for the to_string() was because when complied on x64 without to_string() the output is altered.
		cout << "\n\tCurrent size of double Priority Queue = " << to_string(doublePQ.size()) << endl;
		//peeking element at the front of the que and the priority of the element. 
		cout << "\tData in front of queue = " << doublePQ.peek()
			<< " (" << doublePQ.peekPriority() << ")" << endl;
		//removing the element from the front of the que and returns the new front element in the que.
		cout << "\tAfter removing, new front of queue = " << doublePQ.dequeue() << endl << endl;
	}
}

//MAIN CODE
int main()
{
	testStrPriQue();
	testIntPriQue();
	testDoublePriQue();
	return 0;
}