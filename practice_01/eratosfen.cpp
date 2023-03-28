#include <iostream>
void PrintBoolArray(bool* arr, int len)
{
    for( int i =0; i < len; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void FillBoolArray(bool* arr, int len, bool value)
{
    for( int i =0; i < len; i++)
    {
        arr[i] = value;
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
    bool* numbers = new bool[n];

    FillBoolArray(numbers, n, true);
    PrintBoolArray(numbers, n);


    return 0;
}
