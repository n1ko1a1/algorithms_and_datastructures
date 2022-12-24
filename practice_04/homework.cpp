#include <iostream>

int main(int argc, char ** argcv)
{
    int step = 3;
    std::string f, line;

    while (std::getline(std::cin, f) && !(f == "e" || f == "d"))
        std::cout << "You need to enter e or d! Try again..." << std::endl;

    step *= (f == "e") ? 1 : -1;

    while (std::getline(std::cin, line) && line.empty())
        std::cout << "String must not be empty! Try again..." << std::endl;

    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] >= 'a' && line[i] <= 'z')
        {
            if (step > 0)
                line[i] = (line[i] + step - 'a') % 26 + 'a';
            else
                line[i] = (line[i] - 'a' + step + 26) % 26 + 'a';
        }
        else if (line[i] >= 'A' && line[i] <= 'Z')
        {
            if (step > 0)
                line[i] = (line[i] + step - 'A') % 26 + 'A';
            else
                line[i] = (line[i] - 'A' + step + 26) % 26 + 'A';
        }
    }

    std::cout << line << std::endl;
}