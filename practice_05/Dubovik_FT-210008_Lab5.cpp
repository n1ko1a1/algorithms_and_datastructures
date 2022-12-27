#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  map<string, int> word_count;

  string text;
  getline(cin, text);

  string word = "";
  for (char c : text) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (!word.empty()) {
        word_count[word]++;
      }
      word = "";
    } else {
      word += c;
    }
  }

  if (!word.empty()) {
    word_count[word]++;
  }

  string most_common_word = "";
  int most_common_word_count = 0;
  for (const auto& pair : word_count) {
    if (pair.second > most_common_word_count) {
      most_common_word = pair.first;
      most_common_word_count = pair.second;
    }
  }

  cout << most_common_word << " " << most_common_word_count << endl;

  return 0;
}