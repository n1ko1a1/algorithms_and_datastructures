#include <iostream>
#include <list>

int IsStart(char c)
{
    return c == '[' || c == '{' || c == '(';
}

int IsOpenClose(char start, char end)
{
    return start == '[' && end == ']' ||
            start == '{' && end == '}' ||
            start == '(' && end == ')';
}

bool CheckSyntax(std::list<char> & lst)
{
    std::list<char> stack;
    
    for (std::list<char>::iterator it = lst.begin(); it != lst.end(); ++it)
    {
        if (IsStart(*it))
            stack.push_back(*it);
        else if (IsOpenClose(stack.back(), *it))
            stack.pop_back();
        else
            return false;
    }

    return true;
}

int main()
{
    std::list<char> lst;
    char input_chr;

    while(true)
    {
        std::cin >> input_chr;
        if (input_chr == '0')
            break;
        lst.push_back(input_chr);
    }

    if (CheckSyntax(lst))
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }


    return 0;
}
