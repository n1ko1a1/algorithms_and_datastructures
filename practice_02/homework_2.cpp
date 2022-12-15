#include <iostream>
#include <vector>

using namespace std;

template<typename T>
vector<T> BubbleSort(vector<T> vector, bool increase)
{
    for(int i = 0; i < vector.size(); i++)
    {
        for(int j = i; j < vector.size(); j++)
        {
            if(!increase && vector[i]>vector[j]) swap(vector[i],vector[j]);
            if(increase && vector[i]<vector[j]) swap(vector[i],vector[j]);
        }
    }
    return vector;
}

template<typename T>
void PrintVector(vector<T>& vector)
{
    cout << endl;
    for (int i = 0; i < vector.size(); i++)
    {
        cout << vector[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Input size of vector \n";
    int size;
    cin >> size;
    cout << "Input vector \n";
    vector<int> vect1(size);
    for (int i = 0; i < size; i++) {
        cin >> vect1[i];
    }
    bool inc_dec;
    cout << "Increase or decrease? (true or false)\n";
    cin >> inc_dec;
    vector<int> vect2 = BubbleSort<int>(vect1, inc_dec);

    cout << "Original vector\n";
    PrintVector(vect1);
    cout << "Sorted vector\n";
    PrintVector(vect2);
    return 0;
}