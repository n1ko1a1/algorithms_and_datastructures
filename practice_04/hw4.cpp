#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string text;
    int k;
    cout << "enter string for encode: " << endl;
    cin >> text;
    cout << "enter shift: " << endl;
    cin >> k;

    for (char &chr: text) {
        if (chr >= 'a' && chr <= 'z')
            chr = ((chr - 'a' + k) % 26) + 'a';
    }

    cout << text << endl;

    cout << "enter string for decode: " << endl;
    cin >> text;
    cout << "enter shift:" << endl;
    cin >> k;

    for (char &chr: text) {
        if (chr >= 'a' && chr <= 'z')
            chr = ((chr - 'a' - k) % 26) + 'a';
    }
    cout << text << endl;
}