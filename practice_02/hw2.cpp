#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> vec = {0, 4, 10, 18, 5, 1, 9, 6, 2,};
    vector<int>::iterator index;

    cout << "before: ";
    for (index = vec.begin(); index != vec.end(); index++) {
        cout << *index << " ";
    }
    sort(vec.begin(), vec.end());

    cout << "\nafter: ";
    for (index = vec.begin(); index != vec.end(); index++) {
        cout << *index << " ";
    }

    return 0;
}