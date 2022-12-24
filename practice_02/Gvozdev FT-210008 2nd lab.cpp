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
  vector<int> v = {5, 2, 3, 1, 4};

  // Сортируем вектор
  sortVector(v);

  // Выводим элементы вектора на экран
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}