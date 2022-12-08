#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

bool IsAllowedChar(char c)
{
    if( ( c >= 65 && c <= 90 ) ||/*a-z*/
        ( c >= 97 && c <= 122) ||/*A-Z*/
        ( c >= 48 && c <= 57 ) ) /*0-9*/
        return true;
    return false;
}

/*
bool IsLatinWord(std::string word)
{
    for (char c : word )
    {
        if( !IsLatinChar(c) )
            return false;
    }
    return true;
}*/


int main()
{
    /*std::string word_1;
    std::string word_2;
    std::cin >> word_1 >> word_2;

    std::cout << word_1 + word_2 << std::endl;

    std::cout << word_1 << " " << &word_1 << " " << word_1.length() << std::endl;
    word_1 += "a";
    std::cout << word_1 << " " << &word_1 << " " << word_1.length() << std::endl;

    for (char & c : word_1)
    {
        char z = 'z';
        c = z;
        std::cout << c << std::endl;
    }
    std::cout << word_1 << " " << &word_1 << " " << word_1.length() << std::endl;*/

    /*
    char a = 'a';
    std::cout << static_cast<int>(a) << std::endl;*/
    /*
    std::string word;
    //std::cin >> word;
    getline(std::cin, word);
    std::cout << IsLatinWord(word) << std::endl;*/

    int len;
    std::cin >> len;
    std::string allowed_char = "a-Z,0-9";
    char c = 97;
    //std::cout << ('b' < 'z') << std::endl;
    //48 - 122
    std::srand(time(0));
    std::string password;
    int cnt = 0;
    while (cnt < len)
    {
        char candidate = 48 + rand()%74;
        if (IsAllowedChar(candidate))
        {
            password +=candidate;
            cnt++;
        }
    }
    std::cout << password << std::endl;


    return 0;
}
