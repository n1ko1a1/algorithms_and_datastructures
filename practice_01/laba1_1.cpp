#include <iostream>
using namespace std;

void Eratos(bool massiv[], int N)                          //*создание функции, получающей на вход массив и число n, до которого нужно найти простые числа*//
{
	int x, y;
	for (y = 2; y <= N; y++) massiv[y] = true;
	y = 2;
	while (y * y <= N)
	{
		x = y * y;
		if (massiv[y])
			while (x <= N)
			{
				massiv[x] = false;
				x = x + y;
			}
		y = y + 1;
	}
	cout << "Список простых чисел: ";
	for (y = 2; y <= N; y++)
	{
		if (massiv[y] == true) cout << " " << y;               //вывод простыъ чисел
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");                                    //*надписи на русском*//
	int N;
	cout << "введите размер массива" << endl;
	cin >> N;
	bool* massiv = new bool[N];
	Eratos(massiv, N);                                              // применение функции
	cout << endl;
	return 0;
}


