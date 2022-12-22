#include <iostream>
#include <cmath>

using namespace std;

int main() {
  // Читаем число N
  int N;
  cin >> N;

  // Создаем массив флагов, где i-й элемент равен true,
  // если i - простое, и false иначе
  bool prime[N + 1];
  fill(prime, prime + N + 1, true);
  prime[0] = prime[1] = false;

  // Запускаем алгоритм Эратосфена
  for (int i = 2; i <= N; i++) {
    if (prime[i]) {
      // Выводим i, так как оно является простым числом
      cout << i << " ";

      // Отмечаем числа, кратные i, как составные
      for (int j = i * i; j <= N; j += i) {
        prime[j] = false;
      }
    }
  }

  return 0;
}