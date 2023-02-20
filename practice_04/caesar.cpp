#include <iostream>
#include <string>

bool CheckString(std::string words)
{
	for (char c : words)
	{
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
			return true;
	}
	return false;
}

std::string EncryptWords(std::string words, int step)
{
	std::string enc_words = "";
	for (char c : words)
	{
		if ((c >= 65 && c <= 90 - step) || (c >= 97 && c <= 122 - step))
			enc_words += c + step;
		else if ((c > 90 - step && c <= 90) || (c > 122 - step && c <= 122))
			enc_words += 65 - 1 + c % (90 - step);
		else
			enc_words += c;
	}
	return enc_words;
}

std::string DecryptWords(std::string words, int step)
{
	std::string enc_words = "";
	for (char c : words)
	{
		if ((c >= 65 + step && c <= 90) || (c >= 97 + step && c <= 122))
			enc_words += c - step;
		else if (c >= 65 && c < 65 + step)
			enc_words += 90 + 1 - step + c % 65;
		else if (c >= 97 && c < 97 + step)
			enc_words += 122 + 1 - step + c % 97;
		else
			enc_words += c;
	}
	return enc_words;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	std::string words;
	char solution;

	while (true)
	{
		std::cout << "Введите последовательность слов: ";
		std::getline(std::cin, words);
		if (CheckString(words))
			break;
		else
			std::cout << "Введенная последовательность слов содержит не только латинские символы, попробуйте снова!" << std::endl;
	}

	int step = 0;
	std::cout << "Введите шаг (целое число) для закодирования / декодирования последовательности: ";
	std::cin >> step;

	while (true)
	{
		std::cout << "Выберите режим работы шифратора (e - закодировать, d - декодировать): ";
		std::cin >> solution;
		if (solution == 'e')
		{
			std::cout << EncryptWords(words, step) << std::endl;
			break;
		}
		else if (solution == 'd')
		{
			std::cout << DecryptWords(words, step) << std::endl;
			break;
		}
		else
		{
			std::cout << "Ошибка выбора режима, введите значение снова!" << std::endl;
		}
	}

	return 0;
}
