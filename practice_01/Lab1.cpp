#include <iostream>

void SimpleNums(int* arr, int len)
{
    int s;

    for (int i = 2, index = 0; i < len; i++){
        s = 0;
        for (int j = 2; j < i; j++){
            if (i % j == 0){
                s = 1;
                break;
            }
        }

        if (s == 0){
            arr[index++] = i;
        }
    }
}

void PrSimpleNums(int* arr, int len)
{
    for( int i = 0; i < len; i++)
    {
        if (arr[i] == 0)
            break;

        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    int* numbers = new int[n];

    SimpleNums(numbers, n);
    PrSimpleNums(numbers, n);


    return 0;
} 
