#include <iostream>
#include <vector>

template <typename T>
T Sorting(T& vec)
{
    int len = vec.size();
    
    for (int i = 0; i < len - 1; i++)
    {
        int min = i;
        for (int j = i+1; j < len; j++)
        {
            if (vec[j] < vec[min])
            {
                min = j;
            }
        }
        std::swap(vec[i], vec[min]);
    }
    
    return vec;
}

int main()
{
    std::vector<int> nums = {1, 3, 5, 4, 6, 2, 9, 7};
    std::vector<int> sorted_nums = Sorting(nums);
    
    for (int i = 0; i < sorted_nums.size(); i++)
    {
        std::cout << sorted_nums[i] << " ";
    }
    return 0;
}
