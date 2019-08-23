// ====================================================
//HW#: HW8 Hash
//Your name: Karishma Kapur
//Complier:  g++
//File type: hash header file
//=====================================================

#ifndef HASH_H
#define HASH_H

#include <string>

using namespace std;

class Entry 
{
	string name;
	string phone;
	float salary;
public:
	//entry construtor to set the name, phone, and salary
	Entry(string name, string phone, float salary) 
	{
		this->name = name;
		this->phone = phone;
		this->salary = salary;
	}
	string getKey() { return name; } //get the key
	string getPhone() { return phone; } //get the phone number
	float getSalary() { return salary; } //get the salary
	void setKey(string str) { name = str; } //set the key
};

class HashMap 
{
public:
	class Overflow {};
	HashMap(int size);
	~HashMap();
	unsigned long hash(string str);
	void put(Entry *e);
	Entry* get(string key);
	Entry* remove(string key);
protected:
	Entry **table;
	int size;
};
#endif