//Karishma Kapur
//Trie.h
//May 3, 2019
//Extra Credit Problem #18 & 19 on Final
#ifndef TRIE_H
#define TRIE_H

#include <string>

#define MAX_CHAR 256

using std::string;

class Node
{
private:
	Node *children[MAX_CHAR];
	bool bisEnd;
public:
	Node();
	bool isEnd();
	void insert(string suffix);
	Node* search(string pat);
};

class Trie
{
private:
	Node root;
public:
	void add(string word);
	bool contains(string pat);
	bool isPrefix(string pat);
	string longestPrefix(string word);
};
#endif