#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

int main() {
    // Sozdajte neuporyadochennuyu kartu dlya hraneniya chastoty slov
    std::unordered_map<std::string, int> word_count;

    // Schityvaet vvodimyj tekst
    cout << "Vvedite tekst na latinice:" << endl;
    std::string text;
    std::getline(std::cin, text);

    // Razdelyaet tekst na slova
    std::string word;
    std::istringstream iss(text);
    while (iss >> word) {
        // Uvelichivaet schetchik chastoyty dlya tekushchego slova
        ++word_count[word];
    }

    // Nahodit slovo s naibol'shej chastotoj
    std::string most_frequent_word;
    int highest_frequency = 0;
    for (const auto& kv : word_count) {
        if (kv.second > highest_frequency) {
            highest_frequency = kv.second;
            most_frequent_word = kv.first;
        }
    }

    // Vyvodit naibolee chasto vstrechayushcheesya slovo i ego chastotu
    std::cout << most_frequent_word << " " << highest_frequency << std::endl;

    return 0;
}
