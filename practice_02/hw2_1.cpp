#include <iostream>
#include <vector>

using namespace std;

void fill(vector<int> &v) {
    for (int i=0; i<v.size(); i++)
    {
v[i] = i; }
}
//Нахождение наибольшего элемента и его вывод
void srt(const vector<int> &v) {
    int max1;
    max1 = v[0];
    for (int i=1; i<v.size(); i++)
    {
        if (v[i] > max1) {
            max1 = v[i];
        }
    }
    cout<<max1<<endl;
}
int main() {
int n;
cin>>n; vector<int> a(n); fill(a); srt(a);
return 0;
}