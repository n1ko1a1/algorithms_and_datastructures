#include <iostream>
#include <stack>



int main()
{
    std::string s = "";
    char c;
    while (std::cin >> c) {
        if (c == '0')
            break;
        s += c;
    }
    std::stack<char> list;

    for (auto itr = s.begin(); itr != s.end(); ++itr) {

        if (*itr == '(' || *itr == '{' || *itr == '[')
            list.push(*itr);

        else if (list.empty() || list.top() == '{' && *itr != '}' || list.top() == '(' && *itr != ')' || list.top() == '[' && *itr != ']') {

            return false;
        }

        else list.pop();

    }

    if (list.empty())
        std::cout << "true";
    else
        std::cout << "false";
}
