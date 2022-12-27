#include <iostream>
#include <vector>

std::vector<int> sieve_of_eratosthenes(int n) {
    std::vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (sieve[i]) {
            for (int k = i * i; k <= n; k += i) {
                sieve[k] = false;
            }
        }
    }
    std::vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> primes = sieve_of_eratosthenes(n);
    for (int p : primes) {
        std::cout << p << " ";
    }
    std::cout << std::endl;
    return 0;
}
