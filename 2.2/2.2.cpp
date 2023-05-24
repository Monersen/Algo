#include <iostream>
#include <chrono>

using namespace std;

static long long signed fibonachi_row[100] = { 0, 1 };

long long signed fibonachi(const int num) {
	if (num == 0) {
		return fibonachi_row[0];
	}
	else if (num == 1) {
		return fibonachi_row[1];
	}
	else if (fibonachi_row[num] != 0) {
		return fibonachi_row[num];
	}
	else {
		fibonachi_row[num] = fibonachi(num - 1) + fibonachi(num - 2);
		return fibonachi_row[num];
	}
}

int main(int argc, char** argv) {
	cout << "Enter the number: ";
	int num = 0;
	cin >> num;
	cout << "The Fibonachi num: ";
	auto start = chrono::high_resolution_clock::now();
	cout << fibonachi(num);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::seconds>(end - start);
	cout << " (took " << duration.count() << " seconds)" << endl;
	return 0;
}