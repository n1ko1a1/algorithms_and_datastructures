#include <iostream>
using namespace std;
int main()
{
  int chislo;
  cout << "Введите число ";
  cin >> chislo;
  int *a = new int[chislo + 1];
  cout << "Простые числа:";
  std::cout << std::endl;
  for (int i = 0; i < chislo + 1; i++)
    a[i] = i;
  for (int p = 2; p < chislo + 1; p++)
  {
    if (a[p] != 0)
    {
      cout << a[p] << endl;
      for (int j = p*p; j < chislo + 1; j += p)
        a[j] = 0;
    }
  }
  return 0;
}
