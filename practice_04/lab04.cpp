#include <iostream>
#include <string>

using namespace std;

bool StringCheck(string words)	
{
	for (char c : words)
	{
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
			return true;
	}
	return false;
}

string WordsEncrypt(string words, int st)
{
    string EW = "";
	for (char c : words)
	{	
		if ((c >= 65 && c <= 90 - st) || (c >= 97 && c <= 122 - st))
			EW += c + st;
		else if ((c > 90 - st && c <= 90) || (c > 122 - st && c <= 122))
			EW += 65 - 1 + c % (90 - st);
		else
			EW += c;
	}
	return EW;
}

string WordsDecrypt(string words, int st)
{
    string EW = "";
	for (char c : words)
	{	
		if ((c >= 65 + st && c <= 90) || (c >= 97 + st && c <= 122))
			EW += c - st;
		else if (c >= 65 && c < 65 + st)
			EW += 90 + 1 - st + c % 65;
		else if (c >= 97 && c < 97 + st)
			EW += 122 + 1 - st + c % 97;
		else
			EW += c;
	}
	return EW;
}

int main()
{
	string words, solution, resultlt;
    int st = 2;

	while (true)
	{
		cout << "Выберите операцию d-расшифровать, e-шифровать: ";
		getline(cin, solution);
		
		if (solution != "d" && solution != "e")
		{
			cout << "Необходимо ввести либо d либо e." << endl;
		}
		else break;
	}

	while(true)
	{
		cout << "Введите строку текста для шифрования/расшифровки с шагом 2. Используйте только английский язык: ";
		getline(cin, words);
		if (StringCheck(words))
			break;
		else
			cout << "Вы не ввели ни одного английского символа. Попробуй снова." << endl;
	}

    if (solution == "d")
	{
		cout << WordsDecrypt(words, st) << endl;
	}
	else if (solution == "e")
	{
		cout << WordsEncrypt(words, st) << endl;
	}

	return 0;
}
