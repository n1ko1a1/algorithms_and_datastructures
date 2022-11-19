//ФТ-210007_Устинов_Алексей_Практика_1

#include <iostream>
#include <conio.h>
#include <list>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");   // Подключение русского языка
    
    int n = 0;
    bool good = true;   // Переменная для проверки корректности введенного числа
    do {    // Цикл обработки ввода
        cout << "Введите целое число, которое не будут превосходить простые числа: ";
        cin >> n;
        if (!(good = cin.good())) {
            cout << "Ошибка ввода. Попробуйте еще раз\n" << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (!good);
    
    int *ones_and_zeros = new int[n+1];   // Создание динамического списка
    for (size_t i = 0; i <= n; i++)
    {
        ones_and_zeros[i] = 1;  // Заполнение списка единицами
    }

    cout << "Простые числа, меньшие или равные " << n << ":\n";
    for (size_t k = 2; k <= n; k++)
    {
        if (ones_and_zeros[k] == 1)
        {
            for (size_t j = k + 1; j <= n; j++)  // Цикл замены 1 на 0 в списке (если число кратно k)
            {
                if (j % k == 0)
                {
                    ones_and_zeros[j] = 0;
                }
            }
        }
        else
        {
            continue;
        }
        cout << k << " ";   // Вывод очередного простого числа в консоль
    }
    delete[] ones_and_zeros;
    cout << "\nРабота программы завершена" << endl;
    _getch();
}
