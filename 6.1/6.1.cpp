#include <iostream>
#include <string>

using namespace std;

int simplStringHash(const string& word) {
	int hash = 0;
	if (!word.empty()) {
		for (const auto& chr : word) {
			hash += chr;
		}
	}
	else {
		cout << "Empty input!";
	}
	return hash;
}

int main(int argc, char** argv) {
	string word;
	do {
		cout << "Enter the word: ";
		cin >> word;
		cout << "The naive hash of word \"" << word << "\" = ";
		cout << simplStringHash(word) << endl;
	} while (word != "exit");

	return EXIT_SUCCESS;
}