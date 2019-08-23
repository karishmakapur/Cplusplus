// ====================================================
//HW#: HW8 Hash
//Your name: Karishma Kapur
//Complier:  g++
//File type: hash implementation file
//=====================================================

#include "hash.h"

//PURPOSE: constructor for HashMap class
//ALGORITHM: set the size, create the table, and fill all spots with null
//PARAMETERS: size of how many elements can be stored in array
HashMap::HashMap(int size) 
{
	this->size = size;
	table = new Entry *[size];
	for (int i = 0; i < size; i++)
	{
		table[i] = NULL;
	}
}

//PURPOSE: destructor
//ALGORITHM: loop through each index of array and delete
//PARAMETERS: no parameters
HashMap::~HashMap() 
{
	for (int i = 0; i < size; i++)
	{
		if (table[i] != NULL)
		{
			delete table[i];
		}
	}
	delete[] table;

}

//PURPOSE: converts the name (the key) to an unsigned long
//ALGORITHM: used DJB2
//PARAMETERS: string, which is the key to be looped through and 
//given a unsigned long value
unsigned long HashMap::hash(string str)
{
	const char* cstr = str.c_str();
	unsigned long hash = 5381;
	int c;
	while (c = *cstr++)
	{
		hash = c * 33 + hash;
	}
	return hash;

}

//PURPOSE: inserting a new record
//ALGORITHM: get the key of the entry, find the hash value,
//modulus the hash value by the size of the array (creates index)
//then go to index if there is anything at that index AND that slot
//holds another record that is not the current key trying to be inserted
//AND that slot does not contain "empty" (meaning a record was deleted from there), 
//then increment the index by one, and insert at the next NULL or "empty" slot.
//if during the while loop your index goes back to the index you started at,
//then overflow because array is full.
//PARAMETERS: the entry to be inserted
void HashMap::put(Entry * e)
{
	string key = e->getKey();
	int index = hash(key) % size;
	int startIndex = index;

	while ((table[index] != NULL) && (table[index]->getKey() != key) && (table[index]->getKey() != "empty"))
	{
		index = (index + 1) % size;
		if (index == startIndex)
		{
			throw Overflow();
		}
	
	}	
	
	table[index] = e;
}

//PURPOSE: getting a record
//ALGORITHM: calculate the hash value, modulus it by the size,
//this returns the index
//store the index into a variable for later reference purposes
//if the current index in the array holds a value, and that value
//is not the value of the key, then increment the index.
//if this new index is equal to the start index then return NULL, because
//the key was not found.
//else loop again.
//if the record stored at the index happens to be the key, then return it.
//PARAMETERS: key to find
Entry * HashMap::get(string key)
{
	int index = hash(key) % size;
	int startIndex = index;
	while (table[index] != NULL && table[index]->getKey() != key) 
	{
		index = (index + 1) % size;

		if (index == startIndex)
		{
			return NULL;
		}
	}
	return table[index];

}

//PURPOSE: deleting a record
//ALGORITHM: calculate the hash value, modulus it by the size,
//this returns the index
//store the index into a variable for later reference purposes
//if the current index in the array holds a value, and that value
//is not the value of the key, then increment the index.
//if this new index is equal to the start index then return NULL, because
//the key was not found.
//else loop again.
//if the record stored at the index happens to be the key, then delete it
//and return the entry deleted
//PARAMETERS: key to delete
Entry * HashMap::remove(string key)
{
	int index = hash(key) % size;
	int startIndex = index;
	while (table[index] != NULL && table[index]->getKey() != key) 
	{
		index = (index + 1) % size;
		if (index == startIndex)
		{
			return NULL;
		}
	}
	Entry *e = table[index];
	delete e;
	table[index] = new Entry("empty", "0", 0);
	return e;
}

