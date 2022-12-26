#include <iostream>
#include <string>
#include <regex>
#include <iterator> 
#include <map> 

int main() {
    std::map<std::string, int> word_counter;
    std::cout << "Text: ";
    std::string text;
    std::getline(std::cin, text);
    std::regex reg("\\w+");
    for (auto it = std::sregex_iterator(text.begin(), text.end(), reg); it != std::sregex_iterator(); ++it) {
        std::string word = (*it)[0];
        transform(word.begin(), word.end(), word.begin(), ::toupper);
        word_counter[word]++;
    }
    std::pair<std::string, int> max("", 0);
    for (auto& pair : word_counter) {
        if (max.second <= pair.second) {
            max = pair;
        }
    }
    std::cout << max.first << " " << max.second << " times" << '\n';
}