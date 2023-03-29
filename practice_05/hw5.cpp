#include <iostream>
#include <map>


int main() {
    char c;
    bool in_word = false;
    std::string word;
    std::pair<std::string, int> freq;
    std::map<std::string, int> counts_words;

    while (true) {
        c = getchar();

        if (c == EOF)
            break;

        if ((isspace(c) || ispunct(c)) && in_word) {
            ++counts_words[word];
            in_word = false;
            word.clear();
        } else {
            in_word = true;
            word.push_back(c);
        }
    }
    if (in_word)
        ++counts_words[word];

    for (auto cw: counts_words)
        if (cw.second > freq.second)
            freq = cw;

    if (freq.second)
        std::cout << std::endl << freq.first << " " << freq.second << std::endl;
    else
        std::cout << std::endl << "String is empty." << std::endl;
}