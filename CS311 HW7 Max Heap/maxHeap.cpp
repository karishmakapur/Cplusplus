// ====================================================
//HW#: HW7 MaxHeap
//Your name: Karishma Kapur
//Complier:  g++
//File type: MaxHeap implementation file
//=====================================================

#include "maxHeap.h"


//PURPOSE: constructor
//ALGORITHM: intialize variables, create array
//PARAMETERS: cap, the size of the array
MaxHeap::MaxHeap(int cap)
{
	size = 0; //initalize size to 0
	capacity = cap; //initalize capacity to the number defined by the client
	arr = new int[capacity]; //create an array with the size of the capacity
}

//PURPOSE: return the parent node
//ALGORITHM: (node - 1) / 2 
//PARAMETERS: the index of the current node you are at, i
int MaxHeap::parent(int i)
{
	return ((i - 1) / 2);
}

//PURPOSE: return the left child
//ALGORITHM: (2 * node + 1)
//PARAMETERS: the index of the current node you are at, i
int MaxHeap::left(int i)
{
	return (2* i + 1);
}

//PURPOSE: return the right child
//ALGORITHM: (2*node + 2)
//PARAMETERS: the index of the current node you are at, i
int MaxHeap::right(int i)
{
	return (2 * i + 2);
}

//PURPOSE: determine if the current node you are it is a leaf or not
//ALGORITHM: if the current node you are at is greater the size, 
//which represents the amount of nodes, divided by 2, then the node is
//a leaf. else if it is smaller than, then it is not a leaf.
//PARAMETERS: the index of the current node you are at, i
bool MaxHeap::isLeaf(int i)
{
	return (i > size/ 2) ? true : false;
}

//PURPOSE: used after inserting or deleting a node. Set's the heap into 
//max order, meaning every parent node is greater than all of it's children.
//ALGORITHM: while loop with condition to ensure that the current node (index) is 
//greater than 0 (meaning it's not the root node) && that the value of the current
//node's parent is less than the the value of the current node.
//if these two conditions are true, then enter while loop and swap the two nodes,
//so the bigger value is the parent, and the smaller becomes the child
//and change the index of i, to the parents index.
//PARAMETERS: the index of the current node you are at, i
void MaxHeap::siftup(int i)
{
	//while loop to ensure that swaping only happens when the current node 
	//is not the root node, and the parent of the current node has a value smaller
	//than the current node.
	while (i > 0 && arr[parent(i)] < arr[i])
	{
		swap(&arr[i], &arr[parent(i)]); //swap the parent and the current node.
		i = parent(i); //change the index to the parent.
	}
}

//PURPOSE: used after deleting a node. Set's the heap into 
//max order, meaning every parent node is greater than all of it's children.
//ALGORITHM: whole loop condition to ensure the the current node you are is
//not a leaf. As long as it is not a leaf, store the index of the left child into
//a variable, store the index of the right child into a variable, and store 
//the left child's index into another variable called greater.
//if the right child's index is less than the size of the heap,
//then store the greater node, left child or right child, into the variable greater.
//if the value of the current node is greater than or equal to the greater node,
//then break the loop.
//If still in loop, then swap the current node and the greater node,
//and update the index to the greater node's index.
//PARAMETERS: the index of the current node you are at, i
void MaxHeap::siftdown(int i)
{
	//whole loop condition to ensure the the current node you are is not a leaf
	while (!isLeaf(i)) 
	{
		//store the index of the left child into a variable
		int l = left(i);
		//store the index of the right child into a variable
		int r = right(i);
		//store the left child's index into another variable called greater.
		int greater = l;

		//if the right child's index is less than the size of the heap
		if (r < getSize())
		{
			//store the greater node, left child or right child, into the variable greater.
			greater = (arr[l] > arr[r]) ? l : r;
		}

		///if the value of the current node is greater than or equal to the greater node
		if (arr[i] >= arr[greater])
		{
			//then break the loop.
			break;
		}
		//swap the current node and the greater node
		swap(&arr[i], &arr[greater]);

		//update the index to the greater node's index.
		i = greater;
	}
}

//PURPOSE: get the size of the heap
//ALGORITHM: return the size
//PARAMETERS: no parameters
int MaxHeap::getSize()
{
	return this->size;
}

//PURPOSE: return the root node, the max node.
//ALGORITHM: return the first index of the array
//PARAMETERS: no parameters
int MaxHeap::getMax()
{
	return arr[0];
}

//PURPOSE: insert a new node
//ALGORITHM: if the size of the heap is greater than or equal to it's capacity, then throw overflow
//get the size of the heap, store it into a variable.
//using the size variable as an index, put the value passed through the function
//into a new node, siftup, and increment the size.
//PARAMETERS: value of node to insert
void MaxHeap::insert(int k)
{
	//if the size of the heap is greater than or equal to it's capacity
	if (getSize() >= capacity)
	{
		//then throw overflow
		throw Overflow();
	}

	//store size of heap into a variable
	int sizeOfHeap = getSize();

	//use size as an index, and place the value that user wants to insert at that position of the array
	arr[sizeOfHeap] = k;

	//siftup to readjust and ensure that the heap is still a MaxHeap
	siftup(sizeOfHeap);

	//increment size
	size++;

}

//PURPOSE: swap 2 nodes
//ALGORITHM: temp variable to hold first node,
//and reassign the first node with the second node,
//and second node with the temp variable
//PARAMETERS: the two nodes to swap, *x and *y.
void MaxHeap::swap(int * x, int * y)
{
	//temp variable to hold first node
	int temp = *x;

	//reassigning first node to second node
	*x = *y;
	
	//reassigning second node to temp variable
	*y = temp;

}

//PURPOSE: get the max from the heap and delete it from the heap
//ALGORITHM: if the size is <= 0, throw underflow
//if the size is equal to 1, return the only node
//else store root node into a variable,
//copy the last node to the root node
//and siftdown.
//return the deleted node
//PARAMETERS:  no parameters
int MaxHeap::extractMax()
{
	//if the size is <= 0
	if (getSize() <= 0)
	{
		//then throw underflow
		throw Underflow();
	}

	//if the size is equal to 1
	if (getSize() == 1)
	{
		//return the only node
		return arr[--size];
	}

	//store root node into a variable
	int result = arr[0];

	//copy the last node to the root node
	arr[0] = arr[--size];

	//perform siftdown on the root node.
	siftdown(0);

	//return the deleted node
	return result;

}

//PURPOSE: used for deleting a node
//ALGORITHM: copy the last node to the current node, delete
//the last node. If the last node is smaller than the current node,
//then sift down the current node
//else if the last node is greater than the current node, then 
//sift up the current node.
//PARAMETERS: the index of the current node you are at, i
int MaxHeap::removeAt(int i)
{
	//if the current nodes index is less than 0 OR
	//the size of the heap is <=1, then throw underflow
	if (i < 0 || getSize() <= i)
	{
		throw Underflow();
	}

	//if the size of the heap is = 1, then return the node,
	//(size - 1).
	if (getSize() == 1)
	{
		return arr[--size];
	}
	
	//copy the nodes value into a variable
	int result = arr[i];

	//copy the last node to the current node
	arr[i] = arr[--size];
	
	//if the last node is snaller than the current node, then sift down
	//the current node
	if (arr[i] < result)
	{
		siftdown(i);
	}
	//else if the last node is greater than the current node then sift up
	//the current node
	else 
	{ 
		siftup(i); 
	}

	//return the value of the node that was deleted.
	return result;

}

//PURPOSE: build a heap from an array
//ALGORITHM: start from the last internal node and perform sift down 
//on every internal node.
//PARAMETERS: pointer to the array and the length of the array
void MaxHeap::heapify(int * array, int len)
{
	//causes the array from the class to point to the same memory location
	//that the first index of the array created by the client points to.
	arr = array;

	//make capacity and size equal length
	capacity = size = len;

	int half = getSize() / 2 - 1;	//the index of the last internal node
	
	//for loop to perform sift down on every internal node
	for (int i = half; i >= 0; i--)
	{
		siftdown(i);
	}

}
