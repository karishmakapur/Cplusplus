//INSTRUCTION:
//Llist class - header file template (by Yoshii) based on Notes-6A
//You must complete the ** parts and then complete llist.cpp
// Don't forget PURPOSE and PARAMETERS 
// =======================================================
// HW#: HW3P1 llist
// Your name: Karishma Kapur
// Compiler:  g++ 
// File type: headher file 
//=======================================================

//----- Globally setting up the alias and struct  ----------------
typedef int el_t;  // elements will be integers

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space
struct Node
{
	el_t Elem;   // elem is the element stored
	Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{

private:
	Node *Front;       // pointer to the front node
	Node *Rear;        // pointer to the rear node
	int  Count;        // counter for the number of nodes

public:

	// Exception handling classes 
	class Underflow {};
	class OutOfRange {};  // thrown when the specified Node is out of range

	llist();     // constructor to create a list object
	~llist();     // destructor to destroy all nodes

	//PURPOSE: see if the linked list is empty, which means the front and rear node pointers are pointing to NULL and count = 0.
	//PARAMETERS: no parameters.
	bool isEmpty();

	//PURPOSE: display all the elements in the linked list
	//PARAMETERS: no parameters
	void displayAll();

	//PURPOSE: add a new node at the front of the linked list
	//PARAMETERS: el_t NewNum which is the integer to be added to the Elem of the new Node.
	void addFront(el_t);

	//PURPOSE: add a node at the rear end of the linked list
	//PARAMETERS: el_t NewNum which is the integer to be added to the Elem of the new Node.
	void addRear(el_t);

	//PURPOSE: delete the front node
	//PARAMETERS: reference variable to store the value of the element in the front node.
	//it gets sent back to caller.
	void deleteFront(el_t&);

	//PURPOSE: delete the rear node
	//PARAMETERS: reference variable to store the value of the element in the front node.
	//it gets sent back to caller.
	void deleteRear(el_t&);

	//PURPOSE: delete an element based on index
	//PARAMETERS: int I for index of where to delete node, and el_t& OldNum reference variable to hold value of node deleted.
	void deleteIth(int, el_t&);

	//PURPOSE: add an element based on index
	//PARAMETERS: int I for index of where to add node, and el_t& OldNum reference variable to hold value of node added.   
	void addbeforeIth(int, el_t);

};
