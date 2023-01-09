#include <iostream>
#include <sstream>
#include <map>
#include <cstdlib>

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    const int N = 256;
    map <int, string> mp;



    string S;
    cout << "Введите строчку на английском: ";
    getline(cin, S);


    char word[N] = {};
    stringstream x;
    x << S; 
    int i = 1;           
    while (x >> word)
    {

        mp[i] = word;
        i += 1;
    }

    map <int, string> ::iterator res = mp.begin();
    map <int, string> ::iterator res_2 = mp.begin();

    int result_1[256] = {};
    string result_2[256] = {};

    for (int i = 0; res != mp.end(); res++, i++)
    {
        result_2[i] = res->first;
        for (int x = 0; res_2 != mp.end(); res_2++, x++)
        {

            if (res->second == res_2->second)
            {
                result_2[i] = res_2->second;
                result_1[i] += 1;
            }
        }
        res_2 = mp.begin();
    }

    int max = 0;
    for (int i = 0; i < 256; i++)
    {
        if (result_1[i] > max)
        {
            max = result_1[i];
        }
    }

    int ii = 0;
    int index = 0;

    for (int b : result_1)
    {
        if (b == max)
        {
            index = ii;
            break;
        }
        ii += 1;
    }

    cout << "Слово  " << result_2[index] << " встречается " << max <<" раз(a)";
    cin.get();
    return 0;
} 