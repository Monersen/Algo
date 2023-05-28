#include <iostream>
#include <exception>

using namespace std;

int* setDynamicArray(int logical_size, int actual_size) {
	int* arr = new int[actual_size];
	for (int i = 0; i < actual_size; ++i) {
		if (i < logical_size) {
			cout << "Enter arr[" << i << "]: ";
			cin >> arr[i];
		}
		else {
			arr[i] = 0;
		}
	}
	return arr;
}

void printDynamicArray(int* arr, int logical_size, int actual_size) {
	for (int i = 0; i < actual_size; ++i) {
		if (i < logical_size) {
			cout << arr[i] << ' ';
		}
		else {
			cout << "_ ";
		}
	}
	return;
}

int main(int argc, char** argv) {
	int actual_size = 0;
	int logical_size = 0;

	try {
		cout << "Enter the actual array's size: ";
		cin >> actual_size;
		if (actual_size == 0) {
			throw exception("Array's size must be greater then zero!");
		}

		cout << "Enter the logical array's size: ";
		cin >> logical_size;
		if (logical_size == 0) {
			throw exception("Logical size must be greater then zero!");
		}

		if (logical_size > actual_size) {
			throw exception("Actual size must be greater than the logical size!");
		}
	}
	catch (const exception& error) {
		cerr << "Error: " << error.what();
		return EXIT_FAILURE;
	}

	int* arr = setDynamicArray(logical_size, actual_size);
	cout << "Initial array: ";
	printDynamicArray(arr, logical_size, actual_size);

	delete[] arr;

	return EXIT_SUCCESS;
}