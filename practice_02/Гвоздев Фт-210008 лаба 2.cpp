#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void sortVector(vector<T>& v) {
  sort(v.begin(), v.end());
}

int main() {
  
  vector<int> v = {9,6,2,6,1,13,5};
  sortVector(v);
  
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}