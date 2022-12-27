#include <iostream>
#include <vector>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector; using std::pair;

template<typename T>
void printVector(vector<T> &vec)
{
    for (const auto &item : vec) {
        cout << "{" << item.first << ","
                << item.second << "}" << "; ";
    }
    cout << endl;
}

bool sortPairs(const pair<int, string> &x, const pair<int, string> &y)
{
    return x.first > y.first;
}

int main() {
    vector<pair<int, string>> vec1 = {{12, "eleven"},
                                      {32, "thirty-two"},
                                      {6, "six"},
                                      {43, "forty-three"}};

    cout << "vec1: ";
    printVector(vec1);

    std::sort(vec1.begin(), vec1.end(), sortPairs);

    cout << "vec1: ";
    printVector(vec1);
    cout << endl;

    return EXIT_SUCCESS;
}
