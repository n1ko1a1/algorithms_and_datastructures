#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  // Создаем unordered_map для хранения слов и их частот
  unordered_map<string, int> wordCount;

  string word;
  // Читаем слова из стандартного ввода, пока не достигнем конца файла
  while (cin >> word) {
    // Увеличиваем счетчик частоты слова на 1
    ++wordCount[word];
  }

  // Ищем самое часто встречающееся слово
  string mostFrequentWord;
  int maxCount = 0;
 for (auto it = wordCount.begin(); it != wordCount.end(); ++it) {
    string word = it->first;
    int count = it->second;
    if (count > maxCount) {
        mostFrequentWord = word;
        maxCount = count;
    }
}

  // Выводим результат на стандартный вывод
  cout << mostFrequentWord << " " << maxCount << endl;

  return 0;
}
