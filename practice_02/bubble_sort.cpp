#include <vector>
#include <iostream>

template<typename T>
void PrintVec(std::vector<T>& vec)
{   
    int len = vec.size();
    for (int i = 0; i < len; i++)  //3  0 1 2
    {
        std::cout << vec[i] << " ";
    }
	std::cout << std::endl;
}
template<typename T>
void BubbleSort(std::vector<T>& vec)
{
    bool swap = true;
    while (swap)
    {
        swap = false;
        for (int i = 0; i < vec.size() - 1; i++)
        {
            if (vec[i] > vec[i + 1])
            {
                std::swap(vec[i], vec[i + 1]);
                swap = true;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    std::vector<int> numsVec = { 12, 55, 28, 50, 57, 41, 37, 45, 14, 21 };
	std::cout << "Изначальный вектор: ";
	PrintVec<int>(numsVec);
    BubbleSort<int>(numsVec);
	std::cout << "Отсортированный вектор: ";
	PrintVec<int>(numsVec);

	std::cout << std::endl;

	std::vector<char> charsVec = { 'x', 'n', 'm', 'l', 'g', 'q', 'u', 'i', 's'};
	std::cout << "Изначальный вектор: ";
	PrintVec<char>(charsVec);
    BubbleSort<char>(charsVec);
	std::cout << "Отсортированный вектор: ";
	PrintVec<char>(charsVec);

    return 0;
}
