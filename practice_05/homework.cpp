#include <iostream>
#include <map>


int main(int argv, char ** arcgv)
{
    bool in;
    char c;
    std::string w;
    std::map<std::string, int> counts;

    in = false;
    while ((c = getchar()) != EOF)
    {   
        if (isspace(c) || ispunct(c))
        {
            if (in == true)
            {
                if (counts.count(w) == 0)
                    counts[w] = 1;
                else
                    ++counts[w];
                w.clear();
            }
            in = false;
        }
        else
        {
            in = true;
            w.push_back(c);
        }
    }

    auto freq_w = std::make_pair(std::string(""), 0);
    for (auto w : counts)
        if (w.second > freq_w.second)
            freq_w = w;

    std::cout << std::endl;
    if (freq_w.second)
        std::cout << freq_w.first << " " << freq_w.second;
    else
        std::cout << "Line is empty.";
    std::cout << std::endl;
}