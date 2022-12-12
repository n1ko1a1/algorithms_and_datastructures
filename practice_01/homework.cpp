#include <iostream>

void PrintPrimeNums(int* arr, int len)
{
    for( int i = 0; i < len; i++)
    {
        if (arr[i] == 0)
            break;
            
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void FillPrimeNums(int* arr, int len)
{
    int x;

    for (int i = 2, index = 0; i < len; i++){
        x = 0;
        for (int j = 2; j < i; j++){
            if (i % j == 0){
                x = 1;
                break;
            }
        }
        if (x == 0){
            arr[index++] = i;
        }
    }
}


int main() {
    int n;
    std::cin >> n;
    int* numbers = new int[n];

    FillPrimeNums(numbers, n);
    PrintPrimeNums(numbers, n);


    return 0;
}
