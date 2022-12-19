#include <iostream>
#include <vector>
using namespace std;

void print_vector_bool(const vector<bool> &A)
{
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << '\t';
    }
    cout << '\n';
}

int main()
{
    int N;
    cout<<"Введите N: ";
    cin>> N;

    vector<bool> is_simple(N+1);
    for (int i = 0; i < N; i++) {
        is_simple[i] = true;
    }

    for (int x = 2; x*x <= N; x++) {
        if (is_simple[x])
            for (int y = x*x; y <= N; y += x)
            {
                is_simple[y] = false;
            }
    }

    for (int x = 2; x <= N; x++) {
        if (is_simple[x]) {
            cout << x << '\t';
        }
    }
    cout << '\n';
    return 0;
}