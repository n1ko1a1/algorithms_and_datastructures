#include <iostream>
#include <list>

bool check_valid(std::list<char> & lst)
{
    char first_c;
    std::list<char> stack;

    for (char e : lst)
    {
        if (e == '[' || e == '{' || e == '(')
            stack.push_front(e);
        else
        {
            first_c = stack.front();
            if (!(first_c == '[' && e == ']') &&
                !(first_c == '{' && e == '}') &&
                !(first_c == '(' && e == ')')) 
                    break;
            stack.pop_front();
        }
    }

    return stack.empty();
}

int main()
{
    std::list<char> brackets;

    char input_val;
    while (true)
    {
        std::cin >> input_val;
        if (input_val == '0')
            break;
        brackets.push_back(input_val);
    }
    
    (check_valid(brackets)) ? std::cout << "true" : std::cout << "false";

    return 0;
}