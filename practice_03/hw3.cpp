#include <iostream>
#include <list>

int main()
{
    std::list <std::string> bracket_list;
    std::string lb [] = {"(", "{", "["};
    std::string rb [] = {")", "}", "]"};
    std::string bracket;
    while(true)
    {
        std::cin >> bracket;
        if (bracket == "0")
        {
            break;
        }
        
        if (bracket == lb[0]||bracket == lb[1]||bracket == lb[2])
        {
            bracket_list.push_back(bracket);
        }
        
        else
        {
            if (!bracket_list.empty())
            {
                if( lb[0] == bracket_list.back() && rb[0] == bracket||
                    lb[1] == bracket_list.back() && rb[1] == bracket||
                    lb[2] == bracket_list.back() && rb[2] == bracket)
                {
                    bracket_list.pop_back();
                }
                else
                {
                    bracket_list.push_back("0");
                }
            }
        }
    }
    if(bracket_list.empty())
    {std::cout << "correct" << std::endl;}
    else
    {std::cout << "wrong" << std::endl;}
    return 0;
}
