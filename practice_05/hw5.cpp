#include <iostream>
#include <map>
#include <string>
#include <vector>

std::vector<std::string> Split(std::string str) {
	std::string word = "";
	std::vector<std::string> res;
	int i = 0;
	while (i <= str.length()) {
		if (str[i] <= ' ') {
			res.push_back(word);
			word = "";
		}
		else {
			word += str[i];
		}
		i++;
	}
	return res;
}

std::map<std::string, int> MappedWords(std::vector<std::string> words) {
	std::map<std::string, int> mp;
	auto iter = words.begin();
	while (iter != words.end())
	{
		std::map<std::string, int>::iterator it = mp.find(*iter);
		if (it == mp.end()) {
			mp.emplace(*iter, 0);
		}
		else {
			it->second++;
		}
		++iter;
	}
	return mp;
}
std::string MostMet(std::map<std::string, int> mp) {
	std::map<std::string, int>::iterator iter = mp.begin();
	auto max = mp.begin();
	while (iter != mp.end()) {
		if (iter->second > max->second) {
			max = iter;
		}
		++iter;
	}
	std::string res = max->first;
	return res;
}
int main()
{
	std::cout << "Enter the text to find the most frequent word" << std::endl;
	std::string text;
	std::cin >> text;
	std::cout << MostMet(MappedWords(Split(text)));
}
