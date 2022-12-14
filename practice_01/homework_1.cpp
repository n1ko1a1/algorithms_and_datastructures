#include <iostream>

using namespace std;

int main () {
  std::cout << "Введите число n" << std::endl;
  int n, i, p;
  cin >> n;
  int a[n + 1];

  for (i = 2; i <= n; ++i) 
      a[i] = i;

  std::cout << "Все простые числа до n " << std::endl;

  for(i = 2; i <= n; ++i)
  {
      if(a[i] != 0)
      {
          std::cout << a[i] << std::endl; 
          for(p = 2 * i; p <= n ; p += i)
          {
            a[p] = 0;
          }
    }
  }
  getchar();
  return 0;
}
