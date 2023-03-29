#include <iostream>
#include <string>

using namespace std;

int check(const string &str, int pos = 0) {
    int len = str.length();
    string open = "([{";
    string close = ")]}";
    while (pos < len) {
        const size_t symbol = open.find_first_of(str[pos]);
        if (symbol != string::npos) {
            pos = check(str, pos + 1);
            if (pos < 0 || pos >= len || str[pos] != close[symbol])
                return -1;
        } else if (close.find_first_of(str[pos]) != string::npos)
            return pos;
        ++pos;
    }
    return pos;
}

int main() {
    cout << "Enter a text: ";
    string text;
    cin >> text;
    if (check(text) == text.length()) {
        cout << "True";
    } else {
        cout << "False";
    }
    return 0;
}