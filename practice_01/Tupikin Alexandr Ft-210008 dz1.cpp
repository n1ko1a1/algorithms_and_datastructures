#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<bool> is_prime(N + 1, true);

    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * 2; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 0; i <= N; i++) {
        if (is_prime[i]) {
            cout << i << " ";
        }
    }
    return 0;
}
