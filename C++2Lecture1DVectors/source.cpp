#include <iostream>
#include <vector>

using namespace std;

void initFib(vector<int> &f);
void createFib(vector<int> &f, int size);
void printFib(vector<int> f);

int main()
{
	vector<int> fib;
	int input;

	cout << "Enter a number greater than 1 " << endl;
	cin >> input;

	cout << "Here is your Fibbonacci sequence " << endl;
	initFib(fib);
	createFib(fib, input);
	printFib(fib);

	return 0;
}

void initFib(vector<int>& f)
{
	f.push_back(0);
	f.push_back(1);

}

void createFib(vector<int>& f, int size)
{
	for (int i = 2; i < size; i++) {
		f.push_back(f[i - 2] + f[i - 1]);
	}
}

void printFib(vector<int> f)
{
	for (int i = 0; i < f.size(); i++) {
		cout << f[i] << " ";
	}
	cout << endl;
}
