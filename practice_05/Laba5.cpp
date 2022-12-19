#include <iostream>
#include <sstream>
#include <map>
#include <cstdlib>

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    const int N = 256;                                             //Максимальная длина строки
    map <int, string> mp;

                                                           

    string S;
    cout << "Введите строку   ";
    getline(cin, S);


    char word[N] = {};                                             //Буфер для считывания строки
    stringstream x;                                                //Создание потоковой переменной
    x << S; 
    int i = 1;                                                                //Перенос строки в поток
    while (x >> word)
    {
        //cout << i << word << '\n';
        mp[i] = word;
        i += 1;
    }


    map <int, string> ::iterator it = mp.begin();
    map <int, string> ::iterator it2 = mp.begin();

    int itog1[256] = {};
    string itog2[256] = {};

    //cout << "Отсортированный список" << endl;
    for (int i = 0; it != mp.end(); it++, i++)
    {
        //cout << i << "  Ключ " << it->first << " Значение " << it->second << endl;
        itog2[i] = it->first;
        for (int x = 0; it2 != mp.end(); it2++, x++)
        {
           
            if (it->second == it2->second)
            {
                //cout << it2->second;
                itog2[i] = it2->second;
                itog1[i] += 1;
            }
            //cout << x << "  Ключ " << it2->first << "   Значение " << it2->second << endl;
        }
        it2 = mp.begin();
    }

    int max = 0;
    for (int i = 0; i < 256; i++)
    {
        if (itog1[i] > max)
        {
            max = itog1[i];
        }
    }

    int ii = 0;
    int index = 0;

    for (int b : itog1)
    {
        if (b == max)
        {
            index = ii;
            break;
        }
        ii += 1;
    }
    //cout << ii;

    cout << "Слово  " << itog2[index] << " " << max;
    cin.get();
    return 0;
} 




























































































