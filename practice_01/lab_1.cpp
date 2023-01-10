#include <iostream>
using namespace std;
void PrintBoolArray(int* arr, int len)
{
    for (int i = 2; i < len + 1; i++)
    {
        if (arr[i])
        {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    int* numbers = new int[n];

    for (int i = 0; i <= n; i++)
        numbers[i] = i;

    for (int i = 2; i * i <= n; i++)
    {
        if (numbers[i])
            for (int j = i * i; j <= n; j += i)
                numbers[j] = 0;
    }
    PrintBoolArray(numbers, n);


    return 0;
}