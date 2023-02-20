#include <string>
#include <vector>
#include <iostream>

template<typename T>
T Sort(T& vec)
{
    int len = vec.size();

    for (int i = 0; i < len - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < len; j++)
        {
            if (vec[j] < vec[min_index])
            {
                min_index = j;
            }
        }
        std::swap(vec[i], vec[min_index]);
    }
    return vec;

}

int main()
{
    std::vector<int> vec = { 3, 2, 3, 8, 4, 1, 5, 8, 9, 0 };
    std::vector<int> sorted_vec = Sort(vec);

    for (int i = 0; i < sorted_vec.size(); i++)
    {
        std::cout << sorted_vec[i] << " ";
    }
    return 0;
}
