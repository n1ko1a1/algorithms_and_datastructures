#include <iostream>


void FillArray(int* arr, int len);
int* EratospheneCheck(int* arr, int len, int k);


int main()
{
	std::cout << "Enter the length of array: ";
	int n;
	std::cin >> n;

	int* arr = new int[n];
	FillArray(arr, n);
	int* res = arr; //результирующий массив 
	res = EratospheneCheck(arr, n, 2);
	
	//вывод в консоль
	for (int i = 0; i < n; i++) {
		if (arr[i] != 0) {
			std::cout << res[i] << std::endl;
		}
	}
   
}

void FillArray(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		arr[i] = i + 1;
	}
}

int* EratospheneCheck(int* arr, int len, int k) {
	if (k == len - 1) {
		return arr;
	}
	for (int i = k; i < len; i++) {
		if (arr[i] % k == 0) {
			arr[i] = 0;
		}
	}
	return EratospheneCheck(arr, len, k + 1);
}
