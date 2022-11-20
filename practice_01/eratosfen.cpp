#include <iostream>
void PrintBoolArray(bool* arr, int len)
{
    std::cout << "Простые числа, меньшие или равные " << len << ":\n";
    for (size_t k = 2; k <= len; k++)
    {
        if (arr[k] == 1)
        {
            for (size_t j = k + 1; j <= len; j++)
            {
                if (j % k == 0)
                {
                    arr[j] = false;
                }
            }
        }
        else
        {
            continue;
        }
        std::cout << k << " ";
    }
    std::cout << "\nРабота программы завершена" << std::endl;
}

void FillBoolArray(bool* arr, int len, bool value)
{
    for (int i = 0; i <= len; i++)
    {
        arr[i] = value;
    }
}
int main() {
    setlocale(LC_ALL, "Russian");

    int n = 0;
    bool good = true;

    do {
        std::cout << "Введите целое число, которое не будут превосходить простые числа: ";
        std::cin >> n;
        if (!(good = std::cin.good())) {
            std::cout << "Ошибка ввода. Попробуйте еще раз\n" << std::endl;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!good);

    bool* numbers = new bool[n];

    FillBoolArray(numbers, n, true);
    PrintBoolArray(numbers, n);

    return 0;
}
