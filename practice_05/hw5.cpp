#include <iostream>
#include <string>
#include <unordered_map>


int main()
{
    std::string text;
    std::unordered_map<std::string, int> words;
    std::string word = "";
    
    std::cout << "Enter text:   ";
    getline(std::cin, text);

    for(int i = 0; i < text.length(); i++)
    {
        if(text[i] == ' ')
        {
            words[word]++;
            word = "";
        }
        else
        {
            word += text[i];
        }
    }
    words[word]++;
    int count = 0;
    for(auto& my_pair : words)//key, value
    {
        if (my_pair.second > count)
        {
            word = my_pair.first;
            count = my_pair.second;
        }
    }
    std::cout << word << " " << count << " times" << std::endl;
    return 0;
}
