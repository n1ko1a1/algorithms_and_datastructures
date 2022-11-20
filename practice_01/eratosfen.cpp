#include <iostream>

using namespace std;

void PrintPrimeNums(int* arr, int len)
{
    for (int i = 2; i < len + 1; i++)
    {
        if (arr[i] != 0)
        {
            cout << arr[i] << " ";
            for (int j = i * i; j < len + 1; j += i)
                arr[j] = 0;
        }
    }
}

void FillArray(int* arr, int len)
{
    for (int i = 0; i < len + 1; i++)
    {
        arr[i] = i;
    }
}


int main() {
    setlocale(LC_ALL, "ru");

    int n;
    std::cout << "Введите число: ";
    std::cin >> n;
    int* numbers = new int[n + 1];

    FillArray(numbers, n);
    std::cout << "Все простые числа до " << n << ": ";
    PrintPrimeNums(numbers, n);

    return 0;
}