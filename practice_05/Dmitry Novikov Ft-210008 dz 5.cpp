#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream> 

using namespace std;

int main() {
  // Создаем словарь для хранения слов и их частоты
  unordered_map<string, int> word_count;

  // Читаем текст из стандартного ввода
  cout << "Введите текст:" << endl;
  string text;
  getline(cin, text);

  // Разбиваем текст на слова
  string word;
  stringstream ss(text);
  while (ss >> word) {
    // Увеличиваем частоту слова на 1
    word_count[word]++;
  }

  // Ищем самое часто встречающееся слово
  string most_frequent_word;
  int max_count = 0;
  for (const auto& kv : word_count) {
    if (kv.second > max_count) {
      most_frequent_word = kv.first;
      max_count = kv.second;
    }
  }

  // Выводим самое часто встречающееся слово и его частоту
  cout << "Самое часто встречающееся слово: " << most_frequent_word << endl;
  cout << "Частота: " << max_count << endl;

  return 0;
}
