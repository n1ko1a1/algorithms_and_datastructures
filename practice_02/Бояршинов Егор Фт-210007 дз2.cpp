#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void sortVector(vector<T>& v) {
    sort(v.begin(), v.end());
}

int main() {
    // Создаем вектор целых чисел
    vector<int> v = { 5, 4, 3, 2, 1 };

    // Сортируем вектор
    sortVector(v);

    // Выводим элементы вектора на экран
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;

    // Создаем вектор строк
    vector<string> w = { "apple", "cherry", "banana" };

    // Сортируем вектор
    sortVector(w);

    // Выводим элементы вектора на экран
    for (auto x : w) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}