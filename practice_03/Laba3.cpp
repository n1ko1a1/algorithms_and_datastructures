#include <iostream>
#include <list>

using namespace std;

void print_cool(list<char>& a)
{
	for (list<char>::iterator it = a.begin(); it != a.end(); ++it)
	{
		cout << (*it);
	}
}

bool Check_sk(list<char>& lis)
{
	list<char>stek;

	for (char v : lis)
	{
		if (v == '[' || v == '{' || v == '(')
		{
			stek.push_back(v);
		}
		else
		{
			if (stek.size() != 0)
			{
				char x = stek.back();
				if ((x == '(' && v == ')') || (x == '{' && v == '}') || (x == '[' && v == ']'))
				{
					stek.pop_back();
				}
			}
			else
			{
				stek.push_back(v);
			}
		}
	}
	return stek.empty();

}

int main()
{
	setlocale(LC_ALL, "Rus");
	list<char> mylist;
	while (true)
	{
		char N;
		cout << "Введите скобку/ чтобы показать результат введите 0 ";
		cin >> N;
		if (N == '0')
		{
			break;
		}
		else
		{
			mylist.push_back(N);
		}

	}

	print_cool(mylist);
	bool c = Check_sk(mylist);
	if (c == 1)
	{
		cout << "True";
	}
	else
	{
		cout << "False";
	}
	return 0;
}




