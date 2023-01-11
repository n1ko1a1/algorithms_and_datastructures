#include <iostream>
#include <vector>
#include <stdlib.h>
#include <random>

using namespace std;


//Вывод массивa
template<typename T>
void print(const vector<T>& v)
{

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

}


// coртировка вектора чисел
template<typename T>
void Sort_n(vector<T> &v)
{

	for (int i = 0; i < v.size(); i++)
	{

		for (int k = 0; k < v.size() - i -1; k++)
		{

			if (v[k] < v[k+1])
			{

				swap(v[k], v[k+1]);

			}

		}

	}

}


int main()
{

  setlocale(LC_ALL, "Rus");

	vector<int> a(22, 0);                 
	generate(a.begin(), a.end(), rand);

	Sort_n(a);
	print(a);
	return 0;

}
