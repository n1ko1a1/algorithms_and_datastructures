#include <iostream>
#include <string>

using namespace std;

int main() {
    char action;
    string text;
    int key;
    cout << "enter e for encoding or d for decoding" << endl;
    cin >> action;
    cout << "enter the line" << endl;
    cin.ignore();
    getline(cin, text);
    cout << "Enter the shift" << endl;
    cin >> key;

    if (action == 'e') {
        for (char& c : text) {
            if (isalpha(c)) {
                c = 'a' + (c - 'a' + key) % 26;
            }
        }
    }
    else if (action == 'd') {
        for (char& c : text) {
            if (isalpha(c)) {
                c = 'a' + (c - 'a' - key + 26) % 26;
            }
        }
    }
    else {
        cout << "Invalid action" << endl;
        return 1;
    }

    cout << text << endl;

    return 0;
}
