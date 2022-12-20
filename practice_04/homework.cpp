#include <iostream>
#include <string>
#include <ctype.h>

bool IsLatinChar(char c)
{
    return c >= 65 && c <= 90 || c >= 97 && c <= 122;
}

bool IsFlag(std::string flag)
{
    return flag == "d" || flag == "D" || flag == "e" || flag == "E";  
}

void EncryptLine(std::string & line, int step)
{
    char a; 
    int amount = 'z' - 'a' + 1;

    for (int i = 0; i < line.length(); i++)
        if (IsLatinChar(line[i]) && step != 0)
        {
            a = islower(line[i]) ? 'a' : 'A';
            if (step > 0)
                line[i] = (line[i] + step - a) % amount + a;
            else
                line[i] = (line[i] - a + step + amount) % amount + a;
        }
}

int main()
{
    int step;
    std::string words, flag;

    while(std::getline(std::cin, flag) && !IsFlag(flag))
        std::cout 
            << "Error: need to enter 'e' (encryption) or 'd' (decryption)!" 
            << std::endl;

    while(std::getline(std::cin, words) && words.empty())
        std::cout << "Error: line must not be empty!" << std::endl;

    step = 3;
    step *= flag == "e" ? 1 : -1;

    EncryptLine(words, step);

    std::cout << words << std::endl;

    return 0;
}
