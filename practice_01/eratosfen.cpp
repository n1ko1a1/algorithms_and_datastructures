#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian"); //подключение русского языка
    cout << "\nВведите целочисленное количоство чисел N : ";
    int n;
    std::cin >> n;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Вы ввели не число!" << endl;
    }
    else {
        cout << "Вы ввели число " << n << endl;
    }
    int* p = new int[n]; //Освобождаем память для динамического массива
    for (int i = 0; i < n; i++) // Создаем массив размерностью N 
        p[i] = { 0 };
    for (int i = 2; i < n; i++) { // Цикл замены 0 на 1 каждого непростого числа в массиве
        for (int j = i * i; j < n + 1; j += i) {
            p[j - 1] = 1;
        }
    }

    cout << "Все простые числа до " << n << ":  \n";
    for (int i = 1; i < n + 1; i++) {  // Цикл вывода каждого (нуля) простого числа в массиве
        if (p[i - 1] == 0)
            std::cout << i << "\t";
    }

    return 0;
}
//ФТ-210007_Потапов_Даниил_Практика_1
