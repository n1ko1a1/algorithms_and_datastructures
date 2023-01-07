#include <iostream>
#include <string>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int Open1 = 0, Close1 = 0, Open2 = 0, Close2 = 0, Open3 = 0, Close3 = 0, i; //переменные для подсчёта количества тех или иных скобок
    string text, j="3";
    cout << "Введите строку, состоящую из различных скобок, для завершения ввода введите 0: " << endl;
    while (j!="0") // цикл ввода, записывающий в строку, до ввода 0
    {
        cin >> j;
        text = text + j;
    }
    int len = text.size() - 1;
    for (i = 0; i < len; ++i) // перебираем нашу строку иподсчитываем количество тех или иных скобок
    {
        if (text[i] == '{')
            Open1++;
        else if (text[i] == '}')
            Close1++;
        else if (text[i] == '[')
            Open2++;
        else if (text[i] == ']')
            Close2++;
        else if (text[i] == '(')
            Open3++;
        else Close3++;
    }
    if ((Open1 == Close2) & (Open2 == Close2) & (Open3 == Close3)) { // сравниваем количество разных скобок
        cout << "true";
    }
    else {
        cout << "false";
    }
    return 0;
}
