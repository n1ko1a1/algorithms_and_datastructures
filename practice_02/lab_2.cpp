#include <iostream>
#include <vector>

template <typename T>
T Sorting(T& vec)
{
    int len = vec.size();
    for (int i = 0; i < len - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (vec[j] < vec[min]){
                min = j;
            }
        }
        std::swap(vec[i], vec[min]);
    }

    return vec;
}


template <typename T>
void Pvect(T& vec)
{
    int len = vec.size();
    for (int i = 0; i < len; i++){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    std::vector<int> nums = { 1, 100, 150, 5, 10, 2, 500 };
    std::vector<int> sorted_nums = Sorting(nums);

    Pvect(sorted_nums);

    return 0;
}