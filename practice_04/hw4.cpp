﻿#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int i = 0, j = 0, k;
    char ABC[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                   'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                   's', 't','u', 'v', 'w', 'x', 'y', 'z' };
    char msg[80];
    cout << "Введите сообщение, которое будет закодировано: " << endl;
    cin >> msg;
    cout << "\nВведите сдвиг:" << endl;
    cin >> k;
    cout << endl;
    for (i = 0; i < strlen(msg); i++)
    {
        if (i == ' ') msg[i] = ' ';
        else {
            for (j = 0; j < 26; j++)
            {
                if (msg[i] == ABC[j])
                {
                    if (j >= 45)
                        msg[i] = ABC[i - 26];
                    else
                        msg[i] = ABC[j + k];
                    break;
                }
            }
        }

    }
    cout << "Полученное закодированное сообщение: " << endl;
    cout << msg << endl;
    return 0;
}
