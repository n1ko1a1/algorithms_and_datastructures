#include <iostream>
#include <vector>

template<typename A>
void PrintVector(std::vector<A>& vector)
{
    int len = vector.size();
    for (int i = 0; i < len; i++)
    {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}
template<typename A>
void BubbleSort(std::vector<A>& vector)
{
    bool swap = true;
    while (swap)
    {
        swap = false;
        for (int i = 0; i < vector.size() - 1; i++)
        {
            if (vector[i] > vector[i + 1])
            {
                std::swap(vector[i], vector[i + 1]);
                swap = true;
            }
        }
    }
}
int main()
{
    std::vector<char> number = { 'a', 'e', 'b', 'd', 'c', 'g', 'f' };
    std::cout << "vector before sorting: ";
    PrintVector<char>(number);
    BubbleSort<char>(number);
    std::cout << "vector after sorting: ";
    PrintVector<char>(number);

    std::cout << std::endl;

    std::vector<int> numsVec = { 64, 2, 12, 47, 21, 113, 84 };
    std::cout << "vector before sorting: ";
    PrintVector<int>(numsVec);
    BubbleSort<int>(numsVec);
    std::cout << "vector after sorting: ";
    PrintVector<int>(numsVec);

    return 0;
}