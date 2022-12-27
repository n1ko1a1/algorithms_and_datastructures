#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int N;
  cin >> N;

  bool prime[N + 1];
  fill(prime, prime + N + 1, true);
  prime[0] = prime[1] = false;

  for (int i = 2; i <= N; i++) {
    if (prime[i]) {
      cout << i << " ";
      for (int j = i * i; j <= N; j += i) {
        prime[j] = false;
      }
    }
  }

  return 0;
}
