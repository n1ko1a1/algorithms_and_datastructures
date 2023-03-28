#include <iostream>
#include <vector>

using namespace std;

//Заполнение массива
void fill(vector<int> &v) {
    for (int i=0; i<v.size(); i++)
    {
        cin>>v[i];
    }
}

//Подсчитывание всех элементов массива
void srt(const vector<int> &v) {
    int max1;
    vector<int> z(19);
    for (int i=0; i<v.size(); i++)
    {
        z[v[i]-1] = z[v[i]-1] + 1;
    }
    for (int i=0; i<z.size(); i++)
    {
        if (z[i] != 0){z
            cout<<i+1<<": "<<z[i]<<endl;
        }
    }
}

int main() {
int n;
cin>>n; vector<int> a(n); fill(a); srt(a);
return 0;
}