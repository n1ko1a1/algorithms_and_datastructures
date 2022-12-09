#include <iostream>
#include <cstdlib>
#include<cmath>

using namespace std;
int D1SOE(int n_m) 
{

  int n = 0, m = 0, ArrayLim = 0;
  cout << "\n2 ";
  ArrayLim = n_m + 1;
  bool* array = new bool[ArrayLim];
  for (int i = 0; i < ArrayLim; i++)
  array[i] = false;
  for (n = 1; n <= int((sqrt(((2 * n_m) + 1) / 4.0)) - 0.5); n++)
   {
   
    if (array[n] != 0)
    continue;
    for (m = (2 * ((n * n) + n)); m <= n_m; m += ((2 * n) + 1))
     {
     
       array[m] = true;}}
       for (int n = 1; n < ArrayLim; n++)
       if (!array[n])
       cout << (2 * n) + 1 << " ";
       return 0;
      }
      
      int main() 
      {
      
        int n_m, N = 0;
        cout << "\n Введите N : ";
        cin >> N;
        cout << "\n Все простые числа : ";
        n_m = ((N - 1) / 2);
        D1SOE(n_m);
        return 0;
  }

//Терентьева Екатерина фт-210008
