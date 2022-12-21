#include <iostream>
using namespace std;

void Eratosfen(bool mas[], int n)                          
{  
	int a, b;
	for (b = 2; b <= n; b++) mas[b] = true;
  b = 2;
	while (b * b <= n)
	{
		a = b * b;
		if (mas[b])
			while (a <= n)
			{
				mas[a] = false;
				a = a + b;
        }
		b = b + 1;
	}
	cout << "Простые числа = ";
	for (b = 2; b <= n; b++)
	{
		if (mas[b] == true) cout << " " << b;              
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");                                    
	int n;
	cout << "Введите размер массива = " << endl;
	cin >> n;
	bool* mas = new bool[n];
	Eratos(mas, n);                                              
	cout << endl;
	return 0;
}
