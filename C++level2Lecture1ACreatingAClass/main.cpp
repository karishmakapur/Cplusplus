#include <iostream>
#include <string>
#include "strMetric.h"

using namespace std;

int main() {
	strMetric sm;
	sm.setString("This is a test123");
	int vowels = sm.countVowels();
	int digits = sm.countDigits();
	cout << "There are " << vowels << " vowels" << endl;
	cout << "There are " << digits << " digits" << endl;
	return 0;
}