//INSTRUCTION
//Look for ** to complete this program 
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack
//Your name: Karishma Kapur
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "stack.h"
#include <stdlib.h>

//Purpose of the program: determine the mathematical answer to a postfix expression using the stack class.
//Algorithm: A user enters a postfix expression which will be held in a string.
//Using stack, each operand will be pushed onto the stack, and popped off the stack when an operator is found,
//to determine the answer to the expression. To go through the string, the first character of the string will be held 
//into a char, which will loop through the string and evaluate the postfix expression.
int main()
{
	stack postfixstack;  // integer stack
	string expression;   // user entered expression

	cout << "type a postfix expression: ";
	cin >> expression;

	int i = 0;  // character position within expression
	char item;  // one char out of the expression

	int box1;  // receive things from pop
	int box2;  // receive things from pop
	int result; //to hold new value from mathematical operations, and then to be pushed on stack
	int lastItem; //receive the last element in the stack for later displaying purposes.

	while (expression[i] != '\0')
	{
		try
		{
			item = expression[i];  // current char

			//2.  if it is an operand (number), 
			//    push it (you might get Overflow exception)
			if (isdigit(item))
			{
				postfixstack.push(((int)item) - 48);
			}

			//3.  else if it is an operator,
			//    pop the two operands (you might get Underflow exception), and
			//	apply the operator to the two operands, and
			//    push the result.
			else if ((item == '+') || (item == '-') || (item == '*'))
			{
				postfixstack.pop(box1);
				postfixstack.pop(box2);

				//cases for different operators follow:
				if (item == '-')
				{
					result = box2 - box1;
				}
				// also do the + and * cases 
				else if (item == '+')
				{
					result = box2 + box1;
				}
				else if (item == '*')
				{
					result = box2 * box1;
				}
				// Finally push the result
				postfixstack.push(result);
			}
			else
			{
				throw "Invalid item";
			}
		}// this closes try
		
		// Catch exceptions and report problems and quit the program now. 
		// Error messages describe what is wrong with the expression.
		catch (stack::Overflow)
		{
			cerr << "Error has occured: Stack is full. Expression is too long" << endl;
			exit(1);
		}
		catch (stack::Underflow) // for too few operands
		{
			cerr << "Error has occured: Too few operands" << endl;
			exit(1);
		}
		catch (char const* errorcode) // for invalid item
		{
			cerr << "Error has occured: " << errorcode << endl;
			exit(1);
		}
		// go back to the loop after incrementing i
		i++;
	}// end of while

	// After the loop successfully completes: 
	// The result will be at the top of the stack. Pop it and show it.
	postfixstack.pop(lastItem);
	
	// If anything is left on the stack, an incomplete expression was found.
	// Inform the user.
	if (!postfixstack.isEmpty())
	{
		cout << "Error has occured: Incomplete expression. The following is still on the stack:" << endl;
		postfixstack.displayAll();
	}
	else
	{
		cout << "Your expressions answer is " << lastItem << endl;
	}

	

}// end of the program
