#include <iostream>

int main(int argc, char ** argcv)
{
    int s = 5;
    std::string m;

    while (1)
    {
        std::getline(std::cin, m);
        
        if (m == "e" || m == "d")
        {
            if (m == "d")
                s = -s;
            break;
        }

        std::cout << "You need to enter e or d! Try again..." << std::endl;
    }

    std::string text;

    while (1)
    {
        std::getline(std::cin, text);

        if (!text.empty())
            break;

        std::cout << "String must not be empty! Try again..." << std::endl;
    }

    char start_c;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z' || text[i] >= 'A' && text[i] <= 'Z')
        {
            if (text[i] <= 'Z')
                start_c = 'A';
            else
                start_c = 'a';

            if (s > 0)
                text[i] = (text[i] + s - start_c) % 26 + start_c;
            else
                text[i] = (text[i] - start_c + s + 26) % 26 + start_c;
        }
    }

    std::cout << text << std::endl;
}