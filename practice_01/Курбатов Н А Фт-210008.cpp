#include <iostream>
using namespace std;
int main()
{
  setlocale(LC_ALL, "Russian");
  int N;
  cout << "Количество элементов в массиве равно: ";
  cin >> N;
  int *a = new int[N + 1];//выделяем память для будущего массива из n элементов + '0'
  for (int i = 0; i < N + 1; i++)//заполняем массив
    a[i] = i;
  for (int k = 2; k < N + 1; k++)//заменяем нулями все не простые числа и выводим на экран все числа не равные 0
  {
    if (a[k] != 0)
    {
      cout << a[k] << endl;
      for (int j = k*k; j < N + 1; j += k)
        a[j] = 0;
    }
  }
  return 0;
}