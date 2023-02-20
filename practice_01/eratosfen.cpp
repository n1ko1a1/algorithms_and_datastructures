#include <iostream>

void PrintNumbersArray(int* arr, int len)
{
    for (int i = 2; i < len + 1; i++) {
        if (arr[i] != 0) {
            std::cout << arr[i] << " ";
            for (int j = i * i; j < len + 1; j += i)
                arr[j] = 0;
        }
    }
}


void FillNumbersArray(int* arr, int len)
{
    for (int i = 0; i < len + 1; i++) {
        arr[i] = i;
    }
}


int main() {
    setlocale(LC_ALL, "Russian");

    int n;

    std::cout << "Введите число: ";
    std::cin >> n;

    int* numbers = new int[n + 1];
    FillNumbersArray(numbers, n);
    PrintNumbersArray(numbers, n);

    return 0;
}
