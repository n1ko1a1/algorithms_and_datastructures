#include <iostream>
#include <string>

using namespace std;

// Функция шифрования текста с использованием шифра Цезаря
string encrypt(string text, int key) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                result += char((int(text[i] + key - 65) % 26) + 65);
            }
            else {
                result += char((int(text[i] + key - 97) % 26) + 97);
            }
        }
        else {
            result += text[i];
        }
    }

    return result;
}

// Функция дешифрования текста с использованием шифра Цезаря
string decrypt(string text, int key) {
    return encrypt(text, 26 - key);
}

int main() {
    string text;
    int key;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter key: ";
    cin >> key;

    cout << "Original text: " << text << endl;
    cout << "Encrypted text: " << encrypt(text, key) << endl;
    cout << "Decrypted text: " << decrypt(text, key) << endl;

    return 0;
}