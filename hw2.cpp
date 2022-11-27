#include <iostream>
#include <vector>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	vector <int> numbers{8,6,9,1,5,2,7};
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 6; j++) {
			if (numbers[j] < numbers[j + 1]) {
				swap(numbers[j], numbers[j + 1]);
			}
		}
	}
	for (int i = 0; i < 7; i++) {
		cout << numbers[i];
}
}