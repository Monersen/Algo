#include <iostream>
#include <chrono>

using namespace std;

long long signed fibonachi(int num) {
	if (num == 0) {
		return 0;
	}
	else if (num == 1 || num == -1) {
		return 1;
	}
	else if (num > 0) {
		return (fibonachi(num - 1) + fibonachi(num - 2));
	}
	else {
		return (fibonachi(num + 2) - fibonachi(num + 1));
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