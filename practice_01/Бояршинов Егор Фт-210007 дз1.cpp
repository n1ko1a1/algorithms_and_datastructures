#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 1000000;

int n;
bool is_prime[MAXN + 5];

int main() {
    cin >> n;

    // Инициализируем массив is_prime значениями true
    for (int i = 2; i <= n; i++) {
        is_prime[i] = true;
    }

    // Реализуем алгоритм Эратосфена
    for (int i = 2; i <= sqrt(n); i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // Выводим все простые числа меньше или равные N
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            cout << i << " ";
        }
    }

    return 0;
}