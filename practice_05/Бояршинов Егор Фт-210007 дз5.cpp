#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string text;
    unordered_map<string, int> wordCount;

    cout << "Enter text: ";
    getline(cin, text);

    string word = "";
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ' ') {
            wordCount[word]++;
            word = "";
        }
        else {
            word += text[i];
        }
    }
    wordCount[word]++;

    string mostFrequentWord = "";
    int maxCount = 0;
    for (auto& kv : wordCount) {
        if (kv.second > maxCount) {
            mostFrequentWord = kv.first;
            maxCount = kv.second;
        }
    }

    cout << mostFrequentWord << " " << maxCount << endl;

    return 0;
}