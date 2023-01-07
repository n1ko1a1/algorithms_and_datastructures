#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;
int main()
{ 
    setlocale(LC_ALL, "Russian");
	string text;
	char n;
	int otstup;
	cout << "Введите e для кодирования или d для декодировнаия: "<<endl;
	cin >> n;
	if (n=='e')//ветвление в зависимости от введённого символа
	{ 
		cout <<"Введите строку для кодировнаия: "<<endl;
		cin >> text;
		cout << "Введите отступ: " << endl;
		cin >> otstup;
		for (int i = 0; i < text.length(); i++)//перегоняем все символы строки с преобразованием
		{
			text[i] = char(int(text[i]) + otstup);
		}
		cout << text;
	}
	else if (n=='d')
	{
		cout <<"Введите строку для декодирования: " << endl;
		cin >> text;
		cout << "Введите отступ: " << endl;
		cin >> otstup;
		for (int i = 0; i < text.length(); i++)//перегоняем все символы строки с преобразованием
		{
			text[i] = char(int(text[i]) - otstup);
		}
		cout << text;
	}
    return 0;
}
