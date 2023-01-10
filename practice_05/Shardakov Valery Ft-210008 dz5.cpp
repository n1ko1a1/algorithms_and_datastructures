#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

int main() {
    unordered_map<string, int> word_count;

    cout << "enter the text:" << endl;
    string text;
    getline(cin, text);

    string word;
    stringstream ss(text);
    while (ss >> word) {
        word_count[word]++;
    }
    string most_frequent_word;
    int max_count = 0;
    for (const auto& kv : word_count) {
        if (kv.second > max_count) {
            most_frequent_word = kv.first;
            max_count = kv.second;
        }
    }

    cout << "The most common word: " << most_frequent_word << endl;
    cout << "Frequency: " << max_count << endl;
    return 0;
}
