#include <iostream>
#include "strMetric.h"

using namespace std;

void strMetric::setString(string s)
{
	data = s;
}

int strMetric::countVowels() const
{
	int count = 0;
	for (int i = 0; i < data.length(); i++) {
		switch (toupper(data.at(i))) {
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			count++;
		}
	}
	return count;
}

int strMetric::countDigits() const
{

	int count = 0;
	for (int i = 0; i < data.length(); i++) {
		if (isdigit(data.at(i))) {
			count++;
		}
	}
	return count;
	
}
