#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

int main() {

    int N;
    cout << "Enter a number: ";
    cin >> N;

    bitset<1000000> prime;

    prime.set();
    prime[0] = prime[1] = 0;

    for (int i = 2; i <= sqrt(N); i++) {

        if (prime[i]) {

            for (int j = i * i; j <= N; j += i) {

                prime[j] = 0;

            }
        }
    }

    cout << "Here's prime numbers to " << N << ": " << endl;

    for (int i = 2; i <= N; i++) {

        if (prime[i]) {

            cout << i << " ";

        }
    }
    return 0;
}