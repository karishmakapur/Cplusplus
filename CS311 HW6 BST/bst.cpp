// ====================================================
//HW#: HW6 BST
//Your name: Karishma Kapur
//Complier:  g++
//File type: bst implementation file
//=====================================================

#include <iostream>
#include "bst.h"

using namespace std;

//constructor. 
//PURPOSE: Initialize root node to NULL. (means tree is empty)
//ALGORITHM: this->root = NULL
//PARAMETERS: no parameters. this is a constructor.
BST::BST()
{
	this->root = NULL;
}

//Destructor.
//PURPOSE: delete the all nodes from tree
//ALGORITHM: if the tree is not empty, delete all subtrees (left and right)
//PARAMETERS: no parameters. This is a destructor.
BST::~BST()
{
	//local variable to hold the root node and all its components.
	Node *node = root;

	//if the node is not null, then delete all the elements on the left subtree and right subtree.
	if (node != NULL)
	{
		//while the left subtree is not NULL, keep deleting the nodes
		while (node->left != NULL)
		{
			remove(node->left->key);
		}
		//while the right subtree is not NULL, keep deleting the nodes.
		while (node->right != NULL)
		{
			remove(node->right->key);
		}
	}
	//remove the root node after all the other subtree nodes are deleted.
	remove(node->key);
}

//PURPOSE: insert a node into tree
//ALGORITHM: call overloaded insert function
//PARAMETERS: int data, holds the "key" of the node to be added
void BST::insert(int data) 
{
	//if the root is NULL, then add the node to the root
	if (root == NULL)
	{
		this->root = insert(this->root, data);
	}
	else //if the root is not null, add it to the subtree, not the root.
	{
		insert(this->root, data);
	}
}

//PURPOSE: insert the node into the BST
//ALGORITHM: if the tree is NULL, add the new node as the root node, 
//else if it is less than add to left subtree
//else if it is greater than add to the right subtree.
//PARAMETERS: node = current node you are at in BST and "key" of new node to be added.
Node* BST::insert(Node* node, int data) 
{
	//if the tree is NULL, add the new Node as the root Node.
	if (node == NULL)
	{
		node = new Node(data);
	}
	//else if the key if less than the new node to be added,
	//then add the new Node to the left subtree
	else if (node->key > data)
	{
		node->left = insert(node->left, data);
	}
	//else if the key is greater than the root, add the new Node to the right subtree.
	else if (data > node->key)
	{
		node->right = insert(node->right, data);
	}

	//return the node
	return node;
}

//PURPOSE: search and find a node
//ALGORITHM: call overloaded search function
//PARAMETERS: "key" of node to search for.
Node* BST::search(int key) 
{
	return search(this->root, key);
}

//PURPOSE: search for the node
//ALGORITHM: if the tree is NULL this means there is no element OR the root node is the node to search for, return the current node.
//if the key of the current node is smaller than the key to search for, then go to the right subtree
//if the key of the current node is greater than the key to search for, then go to the left subtree.
//PARAMETERS: node = current node you are at in BST, and key = value of node to search for ("key" of node).
Node* BST::search(Node* node, int key)
{
	//if the tree is NULL, then the key does not exist in the tree.
	//otherwise if the key = the root, then we found it, and return the node.
	if (node == NULL || node->key == key)
	{
		return node;
	}
	//else if the key is greater than the value of the root, then search right subtree.
	else if (node->key < key)
	{
		return search(node->right, key);
	}
	//else if the key is smaller than the value of the root, then search left subtree.
	else if (node->key > key)
	{
		return search(node->left, key);
	}
}

//PURPOSE: print out nodes in BST inorder traversal
//ALGORITHM: call overloaded function inorder
//PARAMETERS: no parameters.
void BST::inorder() 
{
	inorder(this->root);
}

//PURPOSE: print out nodes in BST inorder traversal
//ALGORITHM: check if the current node is empty.
//traverse the left subtree by recursively calling the inorder function
//display the data part of the root (or current node)
//traverse the right subtree by recursively calling the inorder function
//PARAMETERS: current node
void BST::inorder(Node* node) 
{
	//if the current node is not empty, then:
	if (node != NULL)
	{
		//recursively call inorder to traverse the left subtree 
		inorder(node->left);
		
		//display current node
		cout << node->key << " ";

		//recursively call inorder to traverse the left subtree 
		inorder(node->right);
	}
}

//PURPOSE: to delete a node
//ALGORITHM: call overloaded function removre
//PARAMETERS: key of node to delete
void BST::remove(int key)
{
	this->root = remove(this->root, key);
}

//PURPOSE: delete a node from BST
//ALGORITHM: if the tree is empty, then return the current node,
//else if the key to be deleted is greater than the key, go to the left subtree and call remove again
//else if the key to be deleted is smaller than the key, go to the right subtree and call remove again.
//else if the key to be deleted is equal to the key of the current node, 
//make sure it has no children, 
//if it has 1 child, copy it over to the current node, then delete the node copied
//if it has 2 children, then find the leftmost node and copy its contents to the current node 
//and then delete the leftmost node.
//PARAMETERS: current node and "key" (value of node) to be deleted
Node* BST::remove(Node* node, int key)
{
	//if the tree is empty, then return node.
	if (node == NULL)
	{
		return node;
	}
	//if the key to be deleted is smaller than the key of the current node, then go to left node and recursively call remove function.
	if (node->key > key)
	{
		node->left = remove(node->left, key);
	}
	//if the key to be deleted is greater than the key of the current node, then go to right node and recursively call remove function.
	else if (key > node->key)
	{
		node->right = remove(node->right, key);
	}
	else
	{
		//if the node to be deleted is a leaf, then delete the leaf
		//or if the node to be deleted has 1 child, copy the child to 
		//the node and delete child
		if (node->left == NULL)
		{
			Node *temp = node->right;
			delete node;
			return temp;
		}
		else if (node->right == NULL)
		{
			Node *temp = node->left;
			delete node;
			return temp;
		}
		//if the node to be deleted has 2 children, then find the left most node and copy its contents 
		//to the current node and then delete the leftmost node.
		Node *temp = leftmostNode(node->left);
		node->key = temp->key;
		node->left = remove(node->left, temp->key);
		
	}
	return node;

	
}

//PURPOSE: find the leftmost node in the BST
//ALGORITHM: loop to find the left most leaf
//(largest node on the left subtree)
//PARAMETERS: current node
Node* BST::leftmostNode(Node* node)
{
	Node *current = node;

	//loop until you fhind the leftmost leaf.
	while (current->right != NULL)
	{
		current = current->right;
	}
	return current;
}
