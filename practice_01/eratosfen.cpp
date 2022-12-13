#include <iostream>
#include <fstream>

int main() {
    int n;
    std::ofstream cout("output.txt");

    std::cout << "Enter the number up to which to search for prime numbers: ";
    std::cin >> n;

    int *a = new int[n + 1];

    for (int i = 0; i < n + 1; i++)
        a[i] = i;
    for (int p = 2; p < n + 1; p++)
    {
        if (a[p] != 0)
        {
            cout << a[p] << std::endl;
            for (int j = p*p; j < n + 1; j += p) a[j] = 0;
        }
    }

    system("pause");

    return 0;
