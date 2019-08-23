#pragma once
#ifndef STRMETRIC
#define STRMETRIC
#include <string>

using std::string;

class strMetric {
private: 
	string data;
public:
	void setString(string s);
	int countVowels() const;
	int countDigits() const;

};

#endif