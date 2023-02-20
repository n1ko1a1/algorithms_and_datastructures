#include <iostream>
#include <list>

static bool CheckBracketsSequence(std::string brackets, std::list<char> brackets_list)
{
	int count_left = 0;
	int count_right = 0;
	std::list<char>::iterator iter = brackets_list.begin();

	while (iter != brackets_list.end())
	{
		if (*iter == brackets[0])
		{
			count_left += 1;
		}
		else if (*iter == brackets[1])
		{
			if (count_left > count_right)
			{
				count_right += 1;
			}
			else
			{
				return false;
			}
		}
		++iter;
	}
	return count_left == count_right;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	char input_value;
	std::list<char> round_brackets;
	std::list<char> square_brackets;
	std::list<char> curly_brackets;
	std::cout << "Введите последовательность из скобок (закончить ввод - 0):" << std::endl;
	while (true)
	{
		std::cin >> input_value;
		if (input_value == '0')
		{
			break;
		}
		else if (input_value == '(' || input_value == ')')
		{
			round_brackets.push_back(input_value);
		}
		else if (input_value == '[' || input_value == ']')
		{
			square_brackets.push_back(input_value);
		}
		else if (input_value == '{' || input_value == '}')
		{
			curly_brackets.push_back(input_value);
		}
		else
		{
			std::cout << "Ошибка, входная последовательность содержит недопустимые символы" << std::endl;
		}
	}
	bool result = CheckBracketsSequence("()", round_brackets) && CheckBracketsSequence("[]", square_brackets) && CheckBracketsSequence("{}", curly_brackets);
	std::cout.setf(std::ios_base::boolalpha);
	std::cout << result;

	return 0;
}
