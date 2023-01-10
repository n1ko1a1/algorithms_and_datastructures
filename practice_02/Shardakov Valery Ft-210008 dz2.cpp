#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void sortVector(vector<T>& v) {
    sort(v.begin(), v.end());
}

int main() {
    vector<int> v = { 5, 3, 4, 1, 2 };
    sortVector(v);

    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
