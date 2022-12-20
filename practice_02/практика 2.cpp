#include <iostream>
#include <vector>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<int> nums = {10,4,3,1,9,12,36,8,15};//исходный вектор
    int min, temp;
    for (int i = 0; i < nums.size(); i++)//начинаем перебирать вектор
    {
        min =nums[i];
        for (int j = i; j <nums.size(); j++)
        {
            if (min>nums[j])//вся магия: устанавливаем минимальное значение и ставим его на место предыдущего минимального, а предыдущее соответственно на место нового
            {
                min = nums[j];
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            
        }
        nums[i] = min;
    }
    for (int i = 0; i < nums.size(); i++)//выводим отсортированный вектор
    {
        cout << nums[i] << " ";
    }
    return 0;
}