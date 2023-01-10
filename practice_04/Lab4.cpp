#include <iostream>
#include <string>

std::string cipher()
{
    std::string text;
    std::string dec;
    int decision; //коэффициент шифровки, расшифровки
    int k; //шаг смещения
    std::string h_alphabet = "";
    std::string l_alphabet = "";
    for (char c = 'A'; c <= 'Z'; c++)
    {
    h_alphabet += c;
    l_alphabet += tolower(c);
    }
    std::cout << h_alphabet << l_alphabet << std::endl;
    while (true)
    {
        std::cout << "enter d to decode the text e to encode the text   " << std::endl;
        std::cin >> dec;
        if (dec == "d")
        {
            decision = -1;
            break;
        }
        else if (dec == "e")
        {
            decision = 1;
            break;
        }
        else
        {
            std::cout << "input error. please try again" << std::endl;
        }

    }
    std::cout << "enter step(integer)" << std::endl;
    std::cin >> k;
    std::cout << "input text" << std::endl;
    getline(std::cin >> std::ws, text);
    for (int i = 0; i <= text.size(); i++)
    {
        for (int j = 0; j <= h_alphabet.size(); j++)
        {
            if (h_alphabet[j] == text[i])
            {
                text[i] = h_alphabet[(j+k*decision)%26];
                break;
            }
            if (l_alphabet[j] == text[i])
            {
                text[i] = l_alphabet[(j+k*decision)%26];
                break;
            }
        }

    }
    std::cout << text;
    return text;
}

int main()
{
    cipher();
    return 0;
}