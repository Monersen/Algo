#include <iostream>

using namespace std;

void printArray(int* array, const size_t arr_lenght) {
	for (size_t i = 0; i < arr_lenght; ++i) {
		if (i < arr_lenght - 1) {
			cout << array[i] << ", ";
		}
		else {
			cout << array[i] << '.';
		}
	}
}

void qsortRecursive(int* array, const size_t arr_lenght) {
	const int array_start = 0;
	const int array_end = (arr_lenght - 1);

	int left_index = array_start;
	int right_index = array_end;

	int pivot_value = array[arr_lenght / 2];

	while (left_index <= right_index) {
		while (array[left_index] < pivot_value) {
			++left_index;
		}
		while (array[right_index] > pivot_value) {
			--right_index;
		}
		if (left_index <= right_index) {
			swap(array[left_index], array[right_index]);
			++left_index;
			--right_index;
		}
	}

	if (right_index > array_start) {
		qsortRecursive(&array[array_start], (right_index + 1));
	}
	if (left_index < arr_lenght) {
		qsortRecursive(&array[left_index], (arr_lenght - left_index));
	}
}

int main(int argc, char** argv) {

	int arr[18] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
	size_t arr_lenght = sizeof(arr) / sizeof(arr[0]);

	cout << "Initial array:\t";
	printArray(arr, arr_lenght);
	cout << endl;
	qsortRecursive(arr, arr_lenght);
	cout << "Sorted array:\t";
	printArray(arr, arr_lenght);
	cout << endl;

	return 0;
}