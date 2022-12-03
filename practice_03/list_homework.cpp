#include <iostream>
#include <list>

int is_start_bracket(char c)
{
    return c == '[' || c == '{' || c == '(';
}

int is_combination(char c_start, char c_end)
{
    return c_start == '[' && c_end == ']' ||
        c_start == '{' && c_end == '}' ||
        c_start == '(' && c_end == ')';
}

int is_valid(std::list<char>& lst)
{
    std::list<char> stack;

    for (char e : lst) 
    {
        if (is_start_bracket(e))
            stack.push_front(e);
        else if (is_combination(stack.front(), e))
            stack.pop_front();
        else
            return 0;
    }

    return 1;
}

std::list<char> input_list() 
{
    std::list<char> lst;

    char input_val;
    while (true)
    {
        std::cin >> input_val;
        if (input_val == '0')
            break;
        lst.push_back(input_val);
    }

    return lst;
}

int main()
{
    std::list<char> lst;
    
    lst = input_list();

    if (is_valid(lst))
        std::cout << "true";
    else
        std::cout << "false";

    return 0;
}