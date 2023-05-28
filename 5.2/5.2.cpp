#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void printArr(int* arr, size_t length) {
	for (size_t i = 0; i < length; ++i) {
		cout << arr[i] << ' ';
	}
	return;
}

string printElement(int* arr, const int index) {
	if (index == 0) {
		return to_string((int)log2(index + 1)) + " root " + to_string(arr[index]);
	}
	else {
		return to_string((int)log2(index + 1)) + ' ' + ((index % 2 != 0) ? "left(" : "right(")
			+ to_string(arr[(index - 1) / 2]) + ") " + to_string(arr[index]);
	}
}

void printPyramid(int* arr, size_t length) {
	for (size_t i = 0; i < length; ++i) {
		if (i == 0) {
			cout << 0 << ' ' << "root " << arr[i] << endl;
		}
		else {
			cout << printElement(arr, i) << endl;
		}
	}
	return;
}

int main(int argc, char** argv) {

	int arr[] = { 94, 67, 18, 44, 55, 12, 6, 42 };

	const size_t length = sizeof(arr) / sizeof(arr[0]);

	cout << "Initial array: ";
	printArr(arr, length);

	cout << endl;

	cout << "Pyramide:" << endl;
	printPyramid(arr, length);

	int index = NULL;
	cout << "Initial location: " << printElement(arr, index) << endl;
	string command = "start";
	while (command != "exit") {
		cout << "Input command: ";
		cin >> command;
		if (command == "up") {
			if (index == 0) {
				cout << "Error: no parrent." << endl;
			}
			else if ((index - 1) / 2 >= 0) {
				index = (index - 1) / 2;
				cout << "Ok\n" << "Current location: " << printElement(arr, index) << endl;
			}
		}
		else if (command == "left") {
			if ((2 * index + 1) < length) {
				index = (2 * index + 1);
				cout << "Ok\n" << "Current location: " << printElement(arr, index) << endl;
			}
			else {
				cout << "Error: no LEFT child." << endl;
			}
		}
		else if (command == "right") {
			if ((2 * index + 2) < length) {
				index = (2 * index + 2);
				cout << "Ok\n" << "Current location : " << printElement(arr, index) << endl;
			}
			else {
				cout << "Error: no RIGHT child." << endl;
			}
		}
		else {
			cout << "Error: wrong command." << endl;
		}
	}

	return EXIT_SUCCESS;
}