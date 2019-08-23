//Karishma Kapur
//Client2.cpp
//May 3, 2019
//Extra Credit Problem #19 on Final

#include <iostream>
#include "Trie.h"

using namespace std;

int main()
{
	Trie vocabulary;
	cout << "Type a word ('q' for quit): ";
	string word;
	cin >> word;
	while (word != "q") {
		vocabulary.add(word);
		cout << "The longest prefix is: " << vocabulary.longestPrefix(word) << endl;
		cout << "Type a word ('q' for quit): ";
		cin >> word;
	}
	return 0;
}

