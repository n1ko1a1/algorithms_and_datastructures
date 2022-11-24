#include <iostream>
using namespace std;
int main()
{
  int i;
  cout << "i=";
  cin >> i;
  int *a = new int[i + 1];
  for (int i = 0; i < i + 1; i++)
    a[i] = i;
  for (int p = 2; p < i + 1; p++)
  {
    if (a[p] != 0)
    {
      cout << a[p] << endl;
      for (int j = p*p; j < i + 1; j += p)
        a[j] = 0;
    }
  }
  cin.get(); cin.get();
}
