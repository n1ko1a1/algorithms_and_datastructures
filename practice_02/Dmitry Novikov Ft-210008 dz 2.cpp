#include <iostream>
#include <vector>

template <typename T>
void insertionSort(std::vector<T>& vec)
{
    for (size_t i = 1; i < vec.size(); ++i)
    {
        T key = vec[i];
        int j = i - 1;

        while (j >= 0 && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            --j;
        }

        vec[j + 1] = key;
    }
}

int main()
{
    std::vector<int> vec = { 3, 6, 1, 8, 2, 5, 4, 7 };

    insertionSort(vec);

    for (const auto& element : vec)
    {
        std::cout << element << " ";
    }

    return 0;
}
