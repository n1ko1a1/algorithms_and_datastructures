#include <iostream>

using namespace std;

void PrintPrimeNums(int* arr, int len)
{
    for (int i = 2; i < len + 1; i++)
    {
        if (arr[i] != 0)
        {
            cout << arr[i] << endl;
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

//inpit n
//asdasd
int main() {
    //0 1 2 3 4 5 6
    //- - + + - 5
    //p = 2 [2] = false
    int n;
    std::cin >> n;
    int* numbers = new int[n + 1];

    FillArray(numbers, n);
    PrintPrimeNums(numbers, n);

    return 0;
}