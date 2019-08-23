//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A

//- Make sure PURPOSE and PARAMETER comments are given
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  control-K cuts and control-Y pastes
//  Esc X replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Karishma Kapur
//Complier:  g++
//File type: llist implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"llist.h" 

//Constructor
//- initialize Front and Rear to be NULL and Count = 0.
//- This does not create any node.The new list is empty.
//PURPOSE: set the front and rear to null, and count to 0. This creates a linked list object
//ALGORITHM: front and rear = NULL and Count  = 0;
//PARAMETERS: no parameters. This is a constructor.
llist::llist()
{
	Front = NULL; //setting Front pointer to NULL
	Rear = NULL; //setting Rear pointer to NULL
	Count = 0; //initializing Count variable to 0.
}

//Destructor
//- while the list is not empty, call deleteFront repeatedly to delete all nodes.
//- Please place a cout in this function "calling the llist desctructor."
//PURPOSE: deletes / destroys all nodes
//ALGORITHM: making a local variable el_t to hold the value that will be deleted from the llist.
//PARAMETERS: no parameters. This is a destructor.
llist::~llist() 
{
	el_t OldNum; //local variable to hold the deleted node
	cout << "Calling the llist destructor" << endl; //cout statement that will tell user we are in the destructor

	//while loop to make sure the linked list is not empty, if it is, then quit while loop. else keep deleting the front node.
	while (!isEmpty()) 
	{
		deleteFront(OldNum); //deleting the Front node.
	}
}

//bool llist::isEmpty()
//- return true if Front and Rear are both pointing to NULL and Count is 0.
//- (all 3 conditions must be checked)
//PURPOSE: see if the linked list is empty, which means the front and rear node pointers are pointing to NULL and count = 0.
//ALGORITHM: if statement to check if conditions are true, if so, return true. else, return false.
//PARAMETERS: no parameters.
bool llist::isEmpty()
{
	//if/ else statement to check to see if condition is true, if yes, then return true. else return false.
	if ((Front == NULL) && (Rear == NULL) && (Count == 0))
	{
		return true; //returning true
	}
	else
	{
		return false; //returning false
	}
}

//void llist::displayAll()
//- Special case: if the list is empty, display[empty] ).
//- Regular:
//displays each element of the list horizontally starting from Front in[].
//PURPOSE: display all the elements in the linked list
//ALGORITHM: check to see if the linked list is empty, if it is, display empty, if it is not, use a local pointer variable that 
//points to the front of the linked list, and increments its way through (by setting it to pointer->Next and displays each node.
//PARAMETERS: no parameters
void llist::displayAll()
{
	if (isEmpty()) //if statement to check if linked list is empty
	{
		cout << "[empty]" << endl; //if yes, then display empty.
	}
	else //if not,
	{
		Node *tempPointer = Front; //local pointer variable to hold current node

		cout << "[ "; //cout statement to bracket the nodes

		//while loop to check if the tempPointer is pointing to NULL. If it is, this means we have reached the end of the linked list, so quit the while loop.
		while (tempPointer != NULL)
		{
			cout << tempPointer->Elem << " "; //cout statement to print out the element the tempPointer is currently pointing to.
			tempPointer = tempPointer->Next; //increasing the tempPointer to the next node, but setting it to the next node manually.
		}
		cout << "]" << endl; //cout statement to bracket the nodes.
	}
}

//void llist::addRear(el_t NewNum)
//2 cases :
// -Special case: if this is going to be the very first node, you must
//	create a new node and make Front and Rear point to it.Place NewNum and
//	Count is updated.
//	- Regular : adds a new node at the rear and puts NewNum in the Elem field
//	of this new node.Count is updated.
//  Regular case:
//	  Rear->Next = new Node;
//	  Rear = Rear->Next;
//	  Rear->Elem = NewNum;
//	  Rear->Next = NULL;
//PURPOSE: add a node at the rear end of the linked list
//ALGORITHM: create a new node and set Elem to NewNum and it's Next to NULL.
//if this is the first node to be added, meaning Front points to NULL, 
//then make front and rear both point to this new node
//if this is not the first node to be added, then make the rear point to the new node.
//PARAMETERS: el_t NewNum which is the integer to be added to the Elem of the new Node.
void llist::addRear(el_t NewNum)
{
	//creating a new node
	Node *newNode = new Node;
	newNode->Elem = NewNum; //giving it the value passed in parameter
	newNode->Next = NULL; //setting the ->Next to NULL, because this node will be added to the rear of the linked list
	
	if (Front == NULL) //checking to see if the front of the linked list is NULL, because this means there is nothing in the linked list yet, meaning we are adding out first node.
	{
		Front = newNode; //making front point to it, because this will be the first element added to the linked list

	}
	else
	{
		Rear->Next = newNode; //making the next node after rear be the new node created


	}
	Rear = newNode; //making rear point to it because this is the ONLY element in the linked list, 
					//also we wanted to add it to the rear, so we have to set newNode to the rear
					//making it the new rear and set Rear to point at newNode.

	Count++; //incrementing the count variable, which tells you how many nodes are in the linked list.
}

//void llist::addFront(el_t NewNum)
//2 cases:
//	-Special case: if this is going to be the very first node, you must
//		create a new node and make Front and Rear point to it.Place NewNum and
//		Count is updated.
//	- Regular : add a new node to the front of the list and
//		Count is updated.
//	Regular case:
//	  Node *x;
//	  x = new Node;
//	  x->Next = Front;
//	  Front = x;
//	  Front->Elem = NewNum;
//PURPOSE: add a new node at the front of the linked list
//ALGORITHM: create a new node and set Elem to NewNum and it's Next to Front.
//if this is the first node to be added, meaning Front points to NULL, 
//then make front and rear both point to this new node
//if this is not the first node to be added, then make the Front point to the new node.
//PARAMETERS: el_t NewNum which is the integer to be added to the Elem of the new Node.
void llist::addFront(el_t NewNum)
{
	//creating a new node
	Node *newNode = new Node;
	newNode->Elem = NewNum; //making it hold the value passed in parameters of NewNum
	newNode->Next = Front; //making the next element after newNode be the Front node

	if (Front == NULL) //if this is the first element to be added to the linked list,
	{
		Front = newNode; //making Front point to newNode because it is being added to front
		Rear = newNode; //making Rear point to NewNode because this is the only element in the linked list.
	}
	else //if it is not the first element to be added to the linked list,
	{
		Front = newNode; //making Front point to newNode because it is being added to front
	}
	Count++; //increment count. Variable to keep track of amount of nodes in linked list
}

//void llist::deleteFront(el_t& OldNum)
//3 cases:
//  -Error case: if the List is empty, throw Underflow
//  - Special case: if currently only one Node,
//	  give back the front node element through OldNum(pass by reference) and
//	  make sure both Front and Rear become NULL.Count is updated.
//	  - Regular : give back the front node element through OldNum(pass by reference)
//	  and also removes the front node.Count is updated.
//  Regular case:
//	  OldNum = Front->Elem;
//	  Node *Second;
//	  Second = Front->Next;
//	  delete Front;
//	  Front = Second;
//PURPOSE: delete the front node
//ALGORITHM: if the linked list is empty, throw an exception, else if there is only one element
//then get the value, put it in the reference variable, then delete the node and set Front and Rear to null,
//else if there is more than 1 node, get the value of the front node and put it in the reference variable
//then create a temp node that will point to the second node, and then delete the first node
//and make Front point to the temp node created that was set to point to the second node
//PARAMETERS: reference variable to store the value of the element in the front node.
//it gets sent back to caller.
void llist::deleteFront(el_t& OldNum)
{
	if (isEmpty()) //if the linked list is empty,
	{
		throw Underflow(); //you cannot delete anymore elements, so throw underflow exception.
	}
	else if (Count == 1) //if there is only one element in the linked list
	{
		OldNum = Front->Elem; //put the value stored in the front Node into OldNum
		delete Front; //delete the Front node
		Front = NULL; //set the Front pointer to NULL
		Rear = NULL; //set the Rear pointer to NULL
		Count--; //decrease the count variable that stores the number of nodes in the linked list.
	}
	else //else if both other cases are not fit,
	{
		OldNum = Front->Elem; //put the value stored in the front node into OldNum
		Node *Second; //create a new node
		Second = Front->Next; //make the new node point to the element after Front
		delete Front; //delete the front node
		Front = Second; //set the front node to the new node created earlier
		Count--; //decrease the count variable that stores the number of nodes in the linked list.
	}
}

// void llist::deleteRear(el_t& OldNum)
//3 cases:
//	-Error case: if empty, throw Underflow
//	- Special case: if currently only one node,
//		 give back the rear node element through OldNum(pass by reference) and
//		 make sure both Front and Rear become NULL.Count is updated.
//	- Regular : give back the rear node element through OldNum(pass by reference)
//		and also remove the rear node.Count is updated.
//	Regular case:
//		 OldNum = Rear->Elem;
//		 Node *p;
//		Make p go to the one right before rear(using while)
//		delete Rear;
//		Rear = p;
//PURPOSE: delete the rear node
//ALGORITHM: if the linked list is empty, throw an exception, else if there is only one element
//then get the value, put it in the reference variable, then delete the node and set Front and Rear to null,
//else if there is more than 1 node, get the value of the rear node and put it in the reference variable
//then create a temp node that will point to the second to last node, and then delete the rear node
//and make rear point to the temp node created that was set to point to the second to last node
//PARAMETERS: reference variable to store the value of the element in the front node.
//it gets sent back to caller.
void llist::deleteRear(el_t& OldNum)
{
	if (isEmpty()) //if the linked list is empty,
	{
		throw Underflow(); //you cannot delete anymore elements, so throw underflow exception.
	}
	else if (Count == 1) //if there is only one element in the linked list
	{
		OldNum = Rear->Elem; //put the value stored in the rear Node into OldNum
		delete Rear; //delete the rear node
		Front = NULL; //set the front pointer to NULL
		Rear = NULL; //set the Rear pointer to NULL
		Count--; //decrease the count variable that stores the number of nodes in the linked list.
	}
	else //else if both other cases are not fit,
	{
		OldNum = Rear->Elem; //put the value stored in the rear Node into OldNum
		Node *p = Front; // node to use in while loop, to determine the node 1 before the rear element.
		
		//looping through the nodes to find the element before rear.
		while (p->Next != Rear)
		{
			p = p->Next; //once found, set p to the node found.
		}

		delete Rear; //deleting the rear node
		Rear = p; //set rear to the node, which contains the node 1 before the previous rear, making it the new rear
		Rear->Next = NULL;
		Count--; //decrease the count variable that stores the number of nodes in the linked list.
	}
}

// void llist::deleteIth(int I, el_t& OldNum)
//  4 cases:
//-Error case:
// If I is an illegal value(i.e. > Count or < 1) throw OutOfRange.
//  - Special cases : this should simply call deleteFront when I is 1 or
//  deleteRear when I is Count
//  - Regular : delete the Ith node(I starts out at 1).Count is updated.
//  < see the template loops in the notes to move 2 pointers to the right nodes;
// and make sure you indicate the purposes of these local pointers >
//PURPOSE: delete an element based on index
//ALGORITHM: if the Ith value is the same value as Count OR less than 1, then it is an invalid number, then throw an exception
// else if the Ith value is equal to 1, this means delete the front element
// else if the Ith value is equal to Count, this means delete the rear element
//else find the Ith element, create a node to point at the Ith element, and use another node to point the element before the Ith element to the element after the Ith element.
//delete the node that is pointing at the Ith element, which is delete the Ith element.
//PARAMETERS: int I for index of where to delete node, and el_t& OldNum reference variable to hold value of node deleted.
void llist::deleteIth(int I, el_t& OldNum)
{
	if ((I > Count) || (I < 1)) //if the Ith value is the same value as Count OR less than 1, then it is an invalid number.
	{
		throw OutOfRange(); //throw exception
	}
	else if (I == 1) //if the Ith value is equal to 1, this means delete the front element
	{
		deleteFront(OldNum); //delete the front element
	}
	else if (I == Count) //if the Ith value is equal to Count, this means delete the rear element
	{
		deleteRear(OldNum); //delete the rear element
	}
	else //else if the Ith value is valid number that is not 1 or the rear element, then
	{
		Node *p1 = Front; //create a node that will point to the front.
		Node *p2 = Front->Next; //create a node that will point to the element after the front element

		for (int k = 1; k < I - 1; k++) // Move p1 to (I-1)th node            
		{
			p1 = p1->Next; //once at the (I-1)th node, make it point to the next element (which is the Ith element).
			p2 = p2->Next; //once at Ith node, make it point to the element after the Ith node
		}

		p1->Next = p2->Next; //make p1->Next point to 2 elements after the Ith element.
		OldNum = p2->Elem; //put the value stored in the front node into OldNum
		delete p2; //delete p2, which holds the Ith element.
		Count--; //decrease the count, which is a variable that holds the number of nodes in the linked list.

	}
}


//  void llist::addbeforeIth(int I, el_t newNum)
//  4 cases :
//-Error case:
// If I is an illegal value(i.e. > Count + 1 or < 1) throw OutOfRange.
//  - Special cases : this should simply call addFront when I is 1 or addRear when
//  I is Count + 1
//  - Regular : add right before the Ith node.Cout if updated.
//  <see the template loops in the notes to move 2 pointers to the right nodes
//  and make sure you indicate the purposes of these local pointers>
//PURPOSE: add an element based on index
//ALGORITHM: if the Ith value is the 1 + Count OR less than 1, then it is an invalid number, then throw an exception
// else if the Ith value is equal to 1, this means add to the front
// else if the Ith value is equal to Count, this means add to the rear
//else find the Ith element, create a node to point at the Ith element, and use another node to point the element before the Ith element.
//create a third node that will be the node added to the linked list.
//loop through and find the Ith - 1 position, and add the node.
//PARAMETERS: int I for index of where to add node, and el_t& OldNum reference variable to hold value of node added.
void llist::addbeforeIth(int I, el_t newNum)
{
	if ((I > Count + 1) || (I < 1)) //if the Ith value is the 1 + the Count OR less than 1, then it is an invalid number.
	{
		throw OutOfRange(); //throw exception
	}
	else if (I == 1) //if the Ith value is equal to 1, this means add to the front
	{
		addFront(newNum); //add to the front 
	}
	else if (I == Count + 1) //if the Ith value is equal to Count, this means add to the rear
	{
		addRear(newNum); //add to the rear 
	}
	else //else if the Ith value is valid number that is not 1 or the rear element, then
	{
		Node *p1 = Front; //create a node that will point to the (I - 1)th node
		
		Node *p = new Node(); //create a new node, this node will be the node that is added
		p->Elem = newNum; //set the value of the node using ->Elem
		

		//loop through 
		for (int k = 1; k < I - 1; k++) // Move p1 to (I-1)th node            
		{
			p1 = p1->Next; //once at the (I-1)th node, make it point to the next element (which is the Ith element).
		}

		Node *p2 = p1->Next; //point p2 to kth node
		p1->Next = p; //(k-1)th node points to the adding node p
		p->Next = p2; //the adding node p points to p2.
		Count++; //increase the count, which is a variable that holds the number of nodes in the linked list.

	}
}
