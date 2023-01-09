#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  map<string, int> W_C;

  string text;
  getline(cin, text);

  string word = "";
  for (char c : text) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (!word.empty()) {
        W_C[word]++;
      }
      word = "";
    } else {
      word += c;
    }
  }

  if (!word.empty()) {
    W_C[word]++;
  }


  string Most = "";
  int MCWC = 0;
  for (const auto& pair : W_C) {
    if (pair.second > MCWC) {
      Most = pair.first;
      MCWC = pair.second;
    }
  }


  std::cout << "Самое часто встречающееся слово: "<< Most <<" \nВстречается в тексте: " << MCWC <<" раз"<< endl;

  return 0;
}