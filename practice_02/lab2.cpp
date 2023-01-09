#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void sortVector(vector<T>& v) {
    sort(v.begin(), v.end());
}

int main() {
    // ������� ������ ����� �����
    vector<int> v = { 5, 4, 3, 2, 1 };

    // ��������� ������
    sortVector(v);

    // ������� �������� ������� �� �����
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;

    // ������� ������ �����
    vector<string> w = { "apple", "cherry", "banana" };

    // ��������� ������
    sortVector(w);

    // ������� �������� ������� �� �����
    for (auto x : w) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}