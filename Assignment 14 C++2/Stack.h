/*
Karishma Kapur
CSIS 123A
ID: 0558326
Date: 11/21/18
Assignment #14 Templates
Stack.h
Stack class definition
*/

#ifndef STACK
#define STACK
#include <vector>

using std::vector;
using std::size_t;

template <typename T>
class Stack : public vector<T>{
private:
	
public:
	void push(const T& t); //Add element at the end in the Stack
	void pop(); //Delete last element in the Stack
	T& peek(size_t n); //Access element in the Stack
};


template<typename T>
void Stack<T>::push(const T & t)
{
	this->push_back(t);
}

template<typename T>
void Stack<T>::pop()
{
	this->pop_back();
}

template<typename T>
T & Stack<T>::peek(size_t n)
{
	return this->at(n);
}




#endif 