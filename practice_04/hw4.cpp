#include <iostream>
#include <string>

bool CheckString(std::string words)	// Поиск хотя бы одного англ. символа
{
	for (char c : words)
	{
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
			return true;
	}
	return false;
}

std::string EncryptWords(std::string words)
{
	int step = 3;
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

std::string DecryptWords(std::string words)
{
	int step = 3;
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
	std::string words;
	char solution;
	std::string resultlt;

	while (true)
	{
		std::cout << "Enter the words for encryption/decription (step = 3): ";
		std::getline(std::cin, words);
		if (CheckString(words))
			break;
		else
			std::cout << "You didn't enter any English char. Try again\n" << std::endl;
	}

	while (true)
	{
		std::cout << "What action you need to perform on the words (d-decrypt, e-encrypt): ";
		std::cin >> solution;
		if (solution == 'd')
		{
			std::cout << DecryptWords(words) << std::endl;
			break;
		}
		else if (solution == 'e')
		{
			std::cout << EncryptWords(words) << std::endl;
			break;
		}
		else
		{
			std::cout << "InputError. Try again\n" << std::endl;
		}
	}
	return 0;
}