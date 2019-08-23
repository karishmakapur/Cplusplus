#include <iostream>
#include <string>

using namespace std;
string getID(int id);
enum class food {
		IceCream,
		Cake,
		Brownies,
		
	};
int main() {
	

	int id;
	cout << "Enter an ID (0 - 2)" << endl;
	cin >> id;

	string idString = getID(id);

	cout << "You are craving " << idString << endl;


	return 0;
}

string getID(int id) {
	switch (id) {
	case (int)food::IceCream:
		return "IceCream";
		break;
	case (int)food::Brownies:
		return "Brownies";
		break;
	case (int)food::Cake:
		return "Cake";
		break;
	}

	}
