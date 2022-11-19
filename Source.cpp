#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Do kakogo chisla nuzhno najti prostye chisla?: ";
    cin >> n;
    vector <int> numbers(n + 1);
    for (int i = 0; i < n + 1; i++)
        numbers[i] = i;
    for (int i = 2; i < n + 1; i++)
    {
        if (numbers[i] != 0)
        {
            cout << numbers[i] << " ";
            for (int j = i * i; j < n + 1; j += i)
                numbers[j] = 0;
        }
    }
}