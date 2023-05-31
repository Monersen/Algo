#include <iostream>
#include <string>
#include <cmath>

using namespace std;

uint64_t simpleStringHash(const string& word) {
	uint64_t hash = 0;
	if (!word.empty()) {
		for (const char& chr : word) {
			hash += chr;
		}
	}
	else {
		cout << "Empty input!";
	}
	return hash;
}

int64_t simpleRabinKarpToFindSubstring(const string& line, const string& word) {
	int64_t index = 0;

	const uint64_t word_hash = simpleStringHash(word);
	uint64_t subline_hash = 0;

	const size_t word_range = word.size();
	const size_t line_range = line.size();

	for (index = 0; index < (line_range - word_range + 1); ++index) {
		if (index == 0) {
			for (size_t i = index; i < word_range; ++i) {
				subline_hash += line[i];
			}
		}
		else {
			char sub_chr = line[index - 1];
			char add_chr = line[index + word_range - 1];
			subline_hash = (add_chr + subline_hash - sub_chr);
		}
		if (word_hash != subline_hash) {
			continue;
		}
		else {
			for (int j = 0; j < word_range; ++j) {
				if (line[index + j != word[j]]) {
					continue;
				}
			}
			return index;
		}
	}
	return -1;
}

int main(int argc, char** argv) {

	cout << "Enter the line where to search: ";
	string line = { "hellohellomydearfriend" };

	string word = {};
	cin >> line;

	do {
		cout << "Enter the word to search: ";
		cin >> word;
		if (simpleRabinKarpToFindSubstring(line, word) >= 0) {
			cout << "The word \"" << word << "\" found at index: ";
			cout << simpleRabinKarpToFindSubstring(line, word) << endl;
		}
		else {
			cout << "The word \"" << word << "\" is not found." << endl;
		}

	} while (word != "exit");

	return EXIT_SUCCESS;
}