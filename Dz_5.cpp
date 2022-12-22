#include <iostream>
#include <string>
#include <map>
#include <vector> 
#include <sstream> 
int main()
{
    std::cout << "Введите строку" << std::endl;
    std::map <std::string, int> words_count_map;
    std::string stroka;
    std::getline(std::cin, stroka);
    std::istringstream iss(stroka); 
    while (iss)
    {
        std::string word;
        iss >> word;
        if (word.empty()) 
        {
            break;
        }
        auto iter = words_count_map.find(word);
        if (iter == words_count_map.end()) 
            words_count_map.emplace(word, 1); 
        else
            iter->second += 1; 
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
            frequent_words.clear(); 
            frequent_words.push_back(max_count_word);
        }
        else if (it->second == max_count)
        {
        	frequent_words.push_back(it->first);
        }
    }
    
	for (auto frequent_word : frequent_words) 
	{
	    if (words_count_map[frequent_word]==1)
	    {
	        std::cout << "Слово " << frequent_word << " " << "встретилось " << words_count_map[frequent_word]<<" раз" << std::endl;
	    }
	    
	    else if ((words_count_map[frequent_word])>=5)
    	{
    	    std::cout << "Слово " << frequent_word << " " << "встретилось " << words_count_map[frequent_word]<<" раз" << std::endl;
    	}

    	else if (2<=(words_count_map[frequent_word])<=4)
    	{
    	        std::cout << "Слово " << frequent_word << " " << "встретилось " << words_count_map[frequent_word]<<" раза" << std::endl;
    	}
	}
    return 0;
}
