#include <iostream>
#include <map>
#include <string>

using namespace std;

template <typename A, typename B>
multimap<B, A> flip_map(map<A,B> & src) {

    multimap<B,A> dst;

    for(typename map<A, B>::const_iterator it = src.begin(); it != src.end(); ++it)
        dst.insert(pair<B, A>(it -> second, it -> first));

    return dst;
}

void remove_char (string word, char removed_char){
    word.erase(remove(word.begin(), word.end(), removed_char), word.end());
}

int main () {
    string word;
    map <string, int> words_count;
    
    while (cin >> word){
        if (word == "EOT"){ //EOT - end of text
            break;
        }
        remove_char(word, ',');
        remove_char(word, '.');
        remove_char(word, '!');
        remove_char(word, '?');
        remove_char(word, ':');
        remove_char(word, ';');

        transform(word.begin(), word.end(), word.begin(), ::tolower); //lowercase работает только с Английским языком

        if (words_count.contains(word)){
            words_count[word]++;
        } else {
            words_count[word] = 1;
        }
    }

    multimap <int, string> count_words = flip_map(words_count);

    cout << count_words.rbegin()->second << " встретилось в тексте самое большое количество раз: " <<
        count_words.rbegin()->first;

    return 0;
}