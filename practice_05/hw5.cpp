//Input example: WHERE ARE YOU? How are you? I hope you are okay...

#include <iostream>
#include <string>
#include <map>
#include <sstream> // для поочередного чтения слов
#include <algorithm> // для преобразования слова в один регистр
#include <vector> // для записи нескольких слов, встречающихся одинакого часто

int main()
{
    std::cout << "Input correct text:" << std::endl;
    std::map <std::string, int> words_count_map;
    std::string text;
    std::getline(std::cin, text);
    std::istringstream iss(text); // разделение строк по пробелам
    
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
            word_back = word.back(); // удаление символов, если есть, стоящих сразу после слова (... или , или !)
        }

        std::transform(word.begin(), word.end(), word.begin(),
            [](unsigned char c) { return std::tolower(c); }); // все слова становятся нижнего регистра
        std::transform(word.begin(), word.begin() + 1, word.begin(),
            [](unsigned char c) { return std::toupper(c); }); // все слова с большой буквы (для конечного вывода)

        auto iter = words_count_map.find(word);
        if (iter == words_count_map.end()) // итератор words_count_map.end() возвращается при обращении к несуществующему элементу
            words_count_map.emplace(word, 1); // добавление нового слова и его счетчика
        else
            iter->second += 1; // увеличение счетчика
    }

    int max_count = 1;
    std::string max_count_word = "";
    std::vector <std::string> frequent_words;
    
    for (std::map<std::string, int> ::const_iterator it = words_count_map.begin(); it != words_count_map.end(); ++it)
    {
        if (it->second > max_count)
        {
            max_count = it->second;
            max_count_word = it->first;
            frequent_words.clear(); // очищаем предыдущие слова, т.к. уже нашлось более частое слово
            frequent_words.push_back(max_count_word);
        }
        else if (it->second == max_count)
        {
        	frequent_words.push_back(it->first);
        }
    }
    
    std::cout << "The most used words:" << std::endl;
	for (auto frequent_word : frequent_words) // вывод очередного слова с наибольшим счетчиком
    	std::cout << "Word- " << frequent_word << "; " << "Count- " << words_count_map[frequent_word] << std::endl;
    return 0;
}
