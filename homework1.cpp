#include <iostream>
#include <math.h>
 
using std::cout;
using std::cin;
using std::endl;
 
void del(int * mas, int index, int & size)
{
    for (int i = index; i < size; i++)
    {
        mas[i] = mas[i + 1];
    }
    size--;
}
 
int main()
{
    int limit;
    cout << "Введите число: "; cin >> limit;
    limit--;
    int * arr = new int[limit];
    for (int i = 0; i < limit; i++)
    {
        arr[i] = i + 2;
    }   cout << endl;
    bool work = true;
    auto * p = arr;
    int trash{};
    while (work)
    {
        for (int i = trash + 1; i < limit; i++)
        {
            if (arr[i] % *p == 0)
            {
                del(arr, i, limit);
            }
        }
        if (*p > sqrt(limit))
        {
            work = false;
        }
        p++;
        trash++;
    }
    for (int i = 0; i < limit; i++)
    {
        cout << arr[i] << ' ';
    }
    delete[]arr;
    return 0;
}