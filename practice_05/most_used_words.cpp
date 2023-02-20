#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <vector>

int main()
{
	std::setlocale(LC_ALL, "Russian");

	std::cout << "Введите текст (на англ.):" << std::endl;
	std::map <std::string, int> words_count_map;
	std::string text;
	std::getline(std::cin, text);
	std::istringstream iss(text);

	while (iss)
	{
		std::string word;
		iss >> word;
		if (word.empty()) {
			break;
		}

		char word_back = word.back();
		while (!((word_back >= 'A' && word_back <= 'Z') || (word_back >= 'a' && word_back <= 'z'))) {
			word.pop_back();
			word_back = word.back();
		}

		std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) { return std::tolower(c); });
		std::transform(word.begin(), word.begin() + 1, word.begin(), [](unsigned char c) { return std::toupper(c); });

		auto iter = words_count_map.find(word);
		if (iter == words_count_map.end()) {
			words_count_map.emplace(word, 1);
		}
		else {
			iter->second += 1;
		}

	}

	int max_count = 1;
	std::string max_count_word = "";
	std::vector <std::string> frequent_words;

	for (std::map<std::string, int>::const_iterator it = words_count_map.begin(); it != words_count_map.end(); ++it)
	{
		if (it->second > max_count) {
			max_count = it->second;
			max_count_word = it->first;
			frequent_words.clear();
			frequent_words.push_back(max_count_word);
		}
		else if (it->second == max_count) {
			frequent_words.push_back(it->first);
		}
	}

	std::cout << "Часто используемые слова в тексте:" << std::endl;
	for (auto frequent_word : frequent_words) {
		std::cout  << frequent_word << "; " << "кол-во раз - " << words_count_map[frequent_word] << std::endl;
	}

	return 0;
}
