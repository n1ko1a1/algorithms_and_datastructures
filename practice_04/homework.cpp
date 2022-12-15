#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

bool IsAllowedChar(char c)
{
    if ((c >= 65 && c <= 90) ||  /*A-Z*/
        (c >= 97 && c <= 122))   /*a-z*/
        return true;
    return false;
}

std::string GetMode()
{
    std::string mode;
    
    while(std::getline(std::cin, mode) && mode != "d" && mode != "e")
        std::cout << "Error: need to enter 'd' or 'e'! Try again..." << std::endl;

    return mode;
}

void CodingStr(std::string & str, std::string mode, int step)
{
    char firstLetter;
    step *= (mode == "e") ? 1 : -1;

    for (int i = 0; i < str.length(); i++)
        if (IsAllowedChar(str[i]))
        {
            firstLetter = std::isupper(str[i]) ? 'A' : 'a';
            if (mode == "e")
                str[i] = (str[i] + step - firstLetter) % 26 + firstLetter;
            else
                str[i] = (str[i] - firstLetter + step + 26) % 26 + firstLetter;
        }
}

int main()
{
    std::string mode, str;

    mode = GetMode();

    while(std::getline(std::cin, str) && !str.length())
        std::cout << "Error: need to enter something! Try again..." << std::endl;

    CodingStr(str, mode, 3);

    std::cout << str << std::endl;

    return 0;
}
