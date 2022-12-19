#include <iostream>
#include <typeinfo>
#include <list>
#include <algorithm>

using namespace std;


int main()
{
	char alfavit[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	setlocale(LC_ALL, "Rus");
	char s;
	int n;
	string slovo;
	cout << "Введите d если нужно раскодировать, e - закодировать";
	cin >> s;
	cout << "Введите шаг сдвига";
	cin >> n;

	if (n > 26)
	{
		n = n % 26;
	}

	cout << "Введите слово для шифровки/дешифровки";
	cin >> slovo;
	while (true)
	{
		if ((s != 'e') && (s != 'd'))
		{
			cout << "Ошибка ввода Введите d если нужно раскодировать, e - закодировать";
		}
		if (n == 0)
		{
			cout << "Вводите шаг сдвига числом";
		}
		else
		{
			break;
		}
	}
	if (s == 'e')
	{
		list<char> sh;
		for (char d : slovo)
		{
			int index = 0;
			for (char f : alfavit)
			{
				
				if (d == f)
				{
					int nn = index + n;
					if (nn > 25)
					{
						nn = nn % 26;
					}
					char ne_w = alfavit[nn];
					sh.push_back(ne_w);
				}
				else
					index += 1;
			}
		}
		for (char f : sh)
		{
			cout << f;
		}
	}
	if (s == 'd')
	{
		list<char> sh;
		for (char d : slovo)
		{
			int index = 0;
			for (char f : alfavit)
			{

				if (d == f)
				{
					int nn = index - n;
					if (nn < 0)
					{
						nn = 26 + nn;
					}
					char ne_w = alfavit[nn];
					sh.push_back(ne_w);
				}
				else
					index += 1;
			}
		}
		for (char f : sh)
		{
			cout << f;
		}
	}
	return 0;
}

































