#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comparisonFunction(int a, int b)
{
    return a < b;
}

int main()
{
	setlocale(LC_ALL, "Russian");
    vector<int> vec = {1, 9, 6, 2, 0, 4, 10, 18, 5};
    vector<int>::iterator index;
    cout << "Вектор до сортировки: ";
    for (index = vec.begin(); index != vec.end(); index++)
    {
        cout << *index << " ";
    }
    sort(vec.begin(), vec.end(), comparisonFunction);

    cout << "\nОтсортированный вектор: ";
    for (index = vec.begin(); index != vec.end(); index++)
    {
        cout << *index << " ";
    }

    return 0;
}
