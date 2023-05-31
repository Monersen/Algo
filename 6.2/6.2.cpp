#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int realStringHash(const string& word, const int& p, const int& n) {
	uint64_t sum = 0;
	if (!word.empty()) {
		size_t range = word.size();
		for (size_t i = 0; i < range; ++i) {
			sum += (static_cast<uint64_t>(pow(p, i)) * word[i]);
		}
	}
	else {
		cout << "Empty input!";
	}
	int hash = sum % n;
	return hash;
}

int main(int argc, char** argv) {

	int p = 0; // simple number
	cout << "Enter p: ";
	cin >> p;
	int n = 0; // capacity
	cout << "Enter n: ";
	cin >> n;

	string word = { "hello" };
	do {
		cout << "Enter the word: ";
		cin >> word;
		cout << "The hash of word \"" << word << "\" = ";
		cout << realStringHash(word, p, n) << endl;
	} while (word != "exit");

	return EXIT_SUCCESS;
}