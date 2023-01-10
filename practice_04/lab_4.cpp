#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>

using namespace std;

void encryption(char data[256], int x) {
    for (int i = 0; i < strlen(data); i++) {
        if (data[i] >= 'a' && data[i] <= 'z') {
            data[i] = ('a' + (data[i] - 'a' + x) % 26);
        }
        else if (data[i] >= 'A' && data[i] <= 'Z') {
            data[i] = ('A' + (data[i] - 'A' + x) % 26);
        }
    }
    cout << data << endl;
}

void decryption(char data[256], int x) {
    for (int i = 0; i < strlen(data); i++) {
        if (data[i] >= 'a' && data[i] <= 'z') {
            data[i] = ('z' - ('z' - data[i] + x) % 26);
        }
        else if (data[i] >= 'A' && data[i] <= 'Z') {
            data[i] = ('Z' - ('Z' - data[i] + x) % 26);
        }
    }
    cout << data << endl;
}


int main() {
    setlocale(0, "RUS");

    char data[256] = { 0 };
    cout << "Введите сообщение" << endl;
    cin.getline(data, 256);


    int step;
    cout << "Введите сдвиг" << endl;
    cin >> step;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Вы ввели не число!" << endl;
        return 0;
    }


    char answer;
    cout << "Пожалуйста введите e для шифрования, d для дешифрования \n";
    cin >> answer;

    if (answer == 'e') {
        encryption(data, step);
    }
    else if (answer == 'd') {
        decryption(data, step);
    }
    else {
        cout << "Ошибка. Вы вели не d или e" << endl;
    }

    return 0;
}