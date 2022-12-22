#include <iostream>
#include <algorithm>
#include <map>

#define IN  1
#define OUT 0

void AddWord(std::map<std::string, int> & words, std::string & word)
{
    (words.count(word) == 0) ? words[word] = 1 : ++words[word];
}

int main(int argv, char ** arcgv)
{
    int state;
    char c;
    std::string word;
    std::map<std::string, int> countWords;

    state = OUT;
    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (state == IN)
            {
                AddWord(countWords, word);
                word.clear();
            }
            state = OUT;
        }
        else
        {
            state = IN;
            word.push_back(c);
        }

    auto freqWord = std::make_pair(std::string(""), 0);
    for (auto w : countWords)
        if (w.second > freqWord.second)
            freqWord = w; 

    std::cout << std::endl 
              << freqWord.first 
              << " " << freqWord.second 
              << std::endl;
}