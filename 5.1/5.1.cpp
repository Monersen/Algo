#include <iostream>
#include <cmath>

using namespace std;

void printArr(int* arr, size_t length) {
	for (size_t i = 0; i < length; ++i) {
		cout << arr[i] << ' ';
	}
	return;
}

void printLine(int* arr, int i) {
	cout << (int)log2(i + 1) << ' '
		<< ((i % 2 != 0) ? "left (" : "right (")
		<< arr[(i - 1) / 2] << ") "
		<< arr[i];
	return;
}

void printPyramid(int* arr, size_t length) {
	for (size_t i = 0; i < length; ++i) {
		if (i == 0) {
			cout << 0 << ' ' << "root " << arr[i] << endl;
		}
		else {
			printLine(arr, i);
			cout << endl;
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

	return EXIT_SUCCESS;
}