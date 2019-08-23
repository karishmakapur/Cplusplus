#pragma once
#include <string>
using std::string;

namespace Karishma {
	class Number : public string {
	public:
		//public member functions
		//A no argument constructor that sets the data section to "0"
		Number();

		//An overloaded constructor that takes a string and sets the data section to the value being passed to it.
		Number(string s);
	};
}