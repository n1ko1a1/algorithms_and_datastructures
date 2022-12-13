#include <iostream>
#include <list>

static bool check_sequence(std::string brackets, std::list<char> brackets_list)
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
	char input_value;
	std::list<char> round_brackets;
	std::list<char> square_brackets;
	std::list<char> curly_brackets;
	std::cout << "You can enter '(', ')', '[', ']', '{' or '}' until you enter 0." << std::endl
		<< "true - all brackets are closed else false" << std::endl;;
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
			std::cout << "Input Error" << std::endl;
		}
	}
	bool result = check_sequence("()", round_brackets) && check_sequence("[]", square_brackets) && check_sequence("{}", curly_brackets);
	std::cout.setf(std::ios_base::boolalpha);
	std::cout << result;
	return 0;
}
