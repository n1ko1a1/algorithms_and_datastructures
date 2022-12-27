#include <iostream>
#include <vector>
using namespace std;

// Вывод вектора
template<typename T>
void VectorOut(vector<T>& v) 
{
    int vector_len = v.size();
    for (int i = 0; i < vector_len; i++)
    {
        cout << v[i] << " ";
    }
    
    cout << endl;
}

// Сортировка вектора
template<typename T>
void VectorSort(vector<T>& v) 
{
    int end = v.size();
    for (int i = 0; i < end; i++) 
    {
        for (int j = 0; j < end-i-1; j++)
        {
            if (v[j] > v[j+1]) 
            {
                swap(v[j], v[j+1]);
            }
        }
    }
    cout << endl;
}


int main()
{
    vector<int> vector_int = {2, 1, 3};
    vector<char> vector_char = {'b', 'c', 'a', 'd'};
    
    cout << "Вектор: ";
    VectorOut<int>(vector_int);
    VectorSort<int>(vector_int);
    cout << "Отсортированный вектор: ";
    VectorOut<int>(vector_int);
    
    cout << endl;
    
    cout << "Вектор: ";
    VectorOut<char>(vector_char);
    VectorSort<char>(vector_char);
    cout << "Отсортированный вектор: ";
    VectorOut<char>(vector_char);
    setlocale(LC_ALL, "ru");
    
    return 0;
}