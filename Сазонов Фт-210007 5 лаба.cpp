#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  // Создаем пустой словарь
  map<string, int> word_count;
  
  // Читаем текст
  string text;
  getline(cin, text);
  
  // Разбиваем текст на слова
  string word = "";
  for (char c : text) {
    if (c == ' ' || c == '\n' || c == '\t') {
      // Если наткнулись на разделитель, добавляем слово в словарь
      if (!word.empty()) {
        word_count[word]++;
      }
      word = "";
    } else {
      // Иначе добавляем символ к слову
      word += c;
    }
  }
  
  // Если в тексте осталось недобавленное слово, добавляем его в словарь
  if (!word.empty()) {
    word_count[word]++;
  }
  
  // Поиск самого часто встречающегося слова
  string most_common_word = "";
  int most_common_word_count = 0;
  for (const auto& pair : word_count) {
    if (pair.second > most_common_word_count) {
      most_common_word = pair.first;
      most_common_word_count = pair.second;
    }
  }
  
  // Вывод результата
  cout << most_common_word << " " << most_common_word_count << endl;
  
  return 0;
}