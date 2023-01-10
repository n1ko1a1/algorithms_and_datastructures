#include <iostream>
#include <sstream>
#include <cstdlib>
#include <map>
using namespace std;

int main() {
    const int Len = 256;
    map <int, string> mp;

    string text;
    cout << "line - ";
    getline(cin, text);

    char word[Len] = {};
    stringstream x;
    x << text;

    int i = 1;
    while (x >> word) {
        mp[i] = word;
        i += 1;
    }

    map <int, string> ::iterator it = mp.begin();
    map <int, string> ::iterator it2 = mp.begin();

    int res1[256] = {};
    string res2[256] = {};

    for (int i = 0; it != mp.end(); it++, i++)
    {
        res2[i] = it->first;
        for (int x = 0; it2 != mp.end(); it2++, x++)
        {

            if (it->second == it2->second) {
                res2[i] = it2->second;
                res1[i] += 1;
            }
        }
        it2 = mp.begin();
    }

    int max = 0;
    for (int i = 0; i < 256; i++)
    {
        if (res1[i] > max) {
            max = res1[i];
        }
    }

    int q = 0;
    int index = 0;

    for (int b : res1)
    {
        if (b == max) {
            index = q;
            break;
        }
        q += 1;
    }

    cout << res2[index] << " " << max;
    cin.get();

    return 0;
}