//Karishma Kapur
//Trie implementation
//May 3, 2019
//Extra Credit Problem #18 & 19 on Final

#include <iostream>
#include <string>
#include "Trie.h"

using namespace std;

//PURPOSE: Node Conctructor
//ALGORITHM: loop through the private defined array and set each 
//index to null. This initialize the array of nodes.
//Initialize private bool variable to false.
//PARAMETERS: No parameters.
Node::Node()
{
	//loop through each index of the array and initalize it with NULL
	for (int i = 0; i < MAX_CHAR; i++)
	{
		children[i] = NULL;
	}

	//initalize private bool variable to false.
	bisEnd = false;
}

//PURPOSE: determine if the node is a leaf (the end)
//ALGORITHM: return the private bool variable
//PARAMETERS: no parameters
bool Node::isEnd()
{
	return bisEnd;
}

//PURPOSE: insert a word into the dictionary
//ALGORITHM: multiple if statements and an else statement 
// to ensure that the word (string) being added to 
//the dictionary is longer than 1 character.
//And that nodes are created accordingly
//to add the word to the dictionary
//PARAMETERS: the word to add to the dictionary
void Node::insert(string suffix)
{
	//if the string is empty, or has a length less than zero
	//don't add to dictionary. Return out of function.
	if (suffix.length() <= 0)
	{
		return;
	}

	//get the first character of the string
	char c = suffix.at(0);

	//if at position ascii value of first character is NULL
	//then that means no node was created with that value,
	//so we have to create a new node at that position.
	if (children[c] == NULL)
	{
		//create a new node at children[ascii value of first char]
		children[c] = new Node();
	}

	//if the length of the string is = 1,
	//then set the bool variable, on the current node,
	//named bisEnd to true, because that means
	//the node is a leaf.
	if (suffix.length() == 1)
	{
		children[c]->bisEnd = true;
	}
	//else if the string has a length greater than 1,
	//then recursively call insert with a new substring
	//that removes the first char already added to the
	//dictionary.
	else
	{
		//creating a substring starting from position
		//of the current string, so the next letter that
		//can be added to the dictionary is the following
		//character
		string newString = suffix.substr(1);

		//recursively calling insert on the start node
		//so the word is added to the dictionary
		//accordingly. (next character becomes a 
		//child node of this current char)
		children[c]->insert(newString);
	}
}

//PURPOSE: search to see if a word is in the dictionary
//ALGORITHM: recursively call this function to search each character
//against according nodes to see if the word exists in the dictionary.
//If it does, return the node. If it doesn't return the NULL.
//PARAMETERS: the word to search for
Node * Node::search(string pat)
{
	//if the length of the string passed is 0
	//then return the current node
	if (pat.length() == 0)
	{
		return this;
	}

	//get the first character of the string
	char c = pat.at(0);

	//if at position ascii value of first character is NULL
	//then that means no node was created with that value,
	//so return NULL, meaning the word doesn't exist in the
	//dictionary
	if (children[c] == NULL)
	{
		return NULL;
	}

	//return the node
	string str = pat.substr(1);
	return children[c]->search(str);
}

//PURPOSE: add a word to the dictionary
//ALGORITHM: call insert from the node class
//PARAMETERS: the string to be added
void Trie::add(string word)
{
	root.insert(word);
}

//PURPOSE: check to see if a word exists in the dictionary.
//ALGORITHM: create a node and call function search to see if the
//word to look for exists in the dictionary.
//depending on the returned value from search, return true or false.
//PARAMETERS: the word to search for
bool Trie::contains(string pat)
{
	//create a node and initialize it with the node that is returned
	//from the function search.
	Node* node = root.search(pat);

	//if that node is NULL and it is a leaf (bisEnd = true)
	//then return true
	if (node != NULL && node->isEnd())
	{
		return true;
	}

	//else return false, meaning the word doesn't exist in the dictionary
	return false;
}

//PURPOSE: check to see if the prefix exists in the dictionary
//ALGORITHM: create a node and call function search to see if the
//word to look for exists in the dictionary.
//depending on the returned value from search, return true or false.
//PARAMETERS: prefix to search for
bool Trie::isPrefix(string pat)
{
	//create a node and initialize it with the node that is returned
	//from the function search.
	Node* node = root.search(pat);

	//if the node holds value NULL, then return false,
	//meaning that the prefix does not exist
	if (node == NULL)
	{
		return false;
	}

	//else if the node doesn't hold value NULL, then return true,
	//meaning that the prefix does exist.
	return true;
}

//PURPOSE: find the longest prefix for given word. This prefix has
//to exist in the dictionary. If not, then it's not a prefix.
//ALGORITHM: if the string has a length of 1 or less, then this word doesn't
//have a prefix because it is aready at it's minimum.
//create a string that holds the current word, and each time
//you check the character of the string, reinitalize the string
//with the substring going from index 1 to the end of the current
//string.
//check the new string (prefix) against the dictionary.
//if prefix exists in the dictionary return prefix.
//else loop again
//PARAMETERS: word to search for a prefix of
string Trie::longestPrefix(string word)
{
	//if the string passed has a length of 1
	//or less, then return an empty string, 
	//because there is no prefix
	if (word.length() <= 1)
	{
		return "NO PREFIX IN DICTIONARY";
	}

	//create a string to hold the prefix
	string prefix = word;

	//loop through the string passed through the parameters
	//and create a substring to ensure that you are checking
	//each character of the string.
	for (int i = 0; i < word.length(); i++)
	{
		prefix = word.substr(0, prefix.length() - 1);

		//check the new string (prefix) against the dictionary.
		//if prefix exists in the dictionary return prefix.
		//else loop again
		if(contains(prefix))
		{
			return prefix;
		}
	}

	//if you go through the whole string and aren't able
	//to find a matching prefix in the dictionary
	//then return the following.
	return "NO PREFIX IN DICTIONARY";
}
