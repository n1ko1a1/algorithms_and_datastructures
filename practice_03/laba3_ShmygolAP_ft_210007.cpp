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
			char x = stek.back();
			if ((x == '(' && v == ')') || (x == '{' && v == '}') || (x == '[' && v == ']'))
			{
				stek.pop_back();
			}
		}
	}
	return stek.empty();

}

void main()
{
	setlocale(LC_ALL, "Rus");
	list<char> mylist;
	while (true)
	{
		char N;
		cout << "¬ведите скобку";
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
	cout << c;
}









