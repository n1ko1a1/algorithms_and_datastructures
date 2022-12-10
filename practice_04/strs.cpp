#include <iostream>
#include <string>
#include <iterator>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int choice;
    string stroka, answer;
    cout << "Что вы хотите сделать?" << endl << "1 - Шифровать" << endl << "2 - Дешифровать" << endl << "Введите число!" << endl;
    cin >> choice;
    cin.ignore();
   
    

    if (choice == 1)
    {
        cout << "Введите строку для  кодировки на латинице" << endl;
        getline(cin, stroka);
        

        string encryption = stroka;

        int sdvig;
        cout << "Введите ключ от 0 до 25" << endl;
        cin >> sdvig;
        cin.ignore();

        for (int i = 0; i < stroka.size(); i++)
        {
            if (stroka[i] == 32)
            {
                continue;
            }
            else
            {
                if ((stroka[i] + sdvig) > 122)
                {
                    int help = (stroka[i] + sdvig) - 122;
                    encryption[i] = 96 + help;
                }
                else if (stroka[i] + sdvig > 90 and stroka[i] <= 96)
                {
                    int help = (stroka[i] + sdvig) - 90;
                    encryption[i] = 64 + help;
                }
                else
                {
                    encryption[i] += sdvig;
                }

            }
        }
        cout << "Зашифрованный текст" << endl << encryption;
    }
    else if (choice == 2)
    {
        cout << "Введите строку для  кодировки на латинице" << endl;
        getline(cin, stroka);

        int sdvig;
        cout << "Введите ключ от 0 до 25" << endl;
        cin >> sdvig;
        cin.ignore();

        string decryption = stroka;
        for (int i = 0; i < stroka.size();i++)
        {
            if (stroka[i] == 32)
            {
                continue;
            }
            else
            {
                if ((stroka[i] - sdvig) < 97 and (stroka[i] - sdvig) > 90)
                {
                    int help = (stroka[i] - sdvig) + 26;
                    decryption[i] = help;
                }
                else if ((stroka[i] - sdvig) < 65)
                {
                    int help = (stroka[i] - sdvig) + 26;
                    decryption[i] = help;
                }
                else
                {
                    decryption[i] = stroka[i] - sdvig;
                }
            }
        }
        cout << "Дешифрованный текст" << endl << decryption;
    }
    else
    {
        cout << "Вы ввели что-то неверно!" << endl << "Введите число от 1 до 2";
    }
}
