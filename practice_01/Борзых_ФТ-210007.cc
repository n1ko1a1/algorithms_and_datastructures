Напишите прогамму реализующую алгоритм эратосфена. На вход программе передается число N. На выход нужно выписать все простые числа меньшие или равные чем N.
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main ()
{
    int n, p;
    int *mass;
    bool flag; //"зачеркивали" ли число для данного p
    printf("Input n: ");
    scanf_s("%d", &n);
    if (n >= 2)
    {
        n = n - 1; //теперь n - это количесвтво чисел в массиве
        mass = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            mass[i] = i + 2;
        for (int i = 0; i < n; i++)
        {
            p = mass[i];
            flag = false;
            for (int j = i + 1; j < n; j++)
            {
                if (!(mass[j] % p))
                {
                    for (int k = j; k < n - 1; k++)
                        mass[k] = mass[k+1];
                    flag = true;
                    n--; //уменьшаем, потому что чисел на одно стало меньше
                    j--; //уменьшаем, для того чтобы снова проверить на кратность j-е число. Оно же теперь стало другим
                }
            }
            if (flag == false) break;
        }
        for (int i = 0; i < n; i++)
            printf("%d ", mass[i]);
        free(mass);
    }
    else
        printf("Error. n must be >= 2\n");

    _getch();
    return 0;
}
