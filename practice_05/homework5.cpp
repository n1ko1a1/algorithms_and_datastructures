#include <iostream>
#include <unordered_map>

#define IN  1
#define OUT 0

int main()
{
    char c;
    int flag;
    std::string word;
    std::unordered_map<std::string, int> counts;

    flag = OUT;
    while ((c = getchar()) != EOF)
    {
        if (ispunct(c) || isspace(c))
        {
            if (flag)
            {
                ++counts[word];
                word.clear();
            }
            flag = OUT;
        }
        else
        {
            word.push_back(c);
            flag = IN;
        }
    }
    if (flag) ++counts[word];

    std::pair<std::string, int> often;
    for (auto c : counts)
        if (c.second > often.second)
            often = c;

    if (often.second)
        std::cout << std::endl << often.first << " " << often.second << std::endl;
    else
        std::cout << "There are no letters in the line." << std::endl;
}  