#include <iostream>

using namespace std;

int function(int* array, int point, int array_length) {
	int first_index = 0;
	int last_index = (array_length - 1);
	int middle_index = last_index / 2;

	while (array[middle_index] != point) {
		if (array[middle_index] > point) {
			last_index = (middle_index - 1);
			middle_index = (first_index + last_index) / 2;
		}
		else if (array[middle_index] < point) {
			first_index = (middle_index + 1);
			middle_index = (first_index + last_index) / 2;
		}
	}

	int answer = ((array_length - 1) - middle_index);

	return answer;
}

int main(int argc, char** argv) {

	setlocale(LC_ALL, "Russian");

	int point = 0;
	cout << "Введите точку отсчёта: ";
	cin >> point;
	int array[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };

	cout << "Количество элементов в массиве больших, чем " << point << ": " << function(array, point, (sizeof(array) / sizeof(array[0]))) << endl;

	return 0;
}