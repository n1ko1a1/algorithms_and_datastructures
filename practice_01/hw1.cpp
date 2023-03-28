#include <iostream>

using namespace std;

void FillBoolArray(bool* arr, int len)
{
    for( int i = 0; i < len; i++)
    {
        arr[i] = true;
    }
}

void resheto(bool* arr, int len)
{
    for (int i = 2; i*i < len; i++){
        if (arr[i] == true){
            for (int j = i*i; j <= len; j = j + i){
                arr[j] = false;
            }
        }
    }
}

void PrintBoolArray(bool* arr, int len)
{
    for( int i = 1; i < len; i++)
    {
       if (arr[i] == true){
        cout << i << " ";
       }
    }
    cout << endl;
}

int main(){
    int n = 100;
    bool* numbers = new bool[n];
    FillBoolArray(numbers, n);
    resheto(numbers, n);
    PrintBoolArray(numbers, n);
    return 0;
}