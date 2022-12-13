#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <string>

template<typename T>
void PrintVec(std::vector<T> & vec)
{
    int len = vec.size();
    for(int i = 0; i < len; i++)  //3  0 1 2
    {
        std::cout << vec[i] << " ";
    }

    std::cout << std::endl;
}

template<typename T>
void Sort(std::vector<T> & vec)
{
    int len = vec.size();

    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main()
{
    std::vector<short> vec_short = {2, 1, 3, 4, 10, 5, 6};
    std::vector<int> vec_int = {2, 1, 3, 4, 10, 5, 6};
    std::vector<char> vec_char = {'g', 'a', 'j', 'i', 'e', 'y', 'c'};

    std::cout << "Vector with type short:" << std::endl;
    PrintVec<short>(vec_short);
    Sort<short>(vec_short);
    PrintVec<short>(vec_short);

    std::cout << "\nVector with type int:" << std::endl;
    PrintVec<int>(vec_int);
    Sort<int>(vec_int);
    PrintVec<int>(vec_int);

    std::cout << "\nVector with type char:" << std::endl;
    PrintVec<char>(vec_char);
    Sort<char>(vec_char);
    PrintVec<char>(vec_char);

    return 0;
}
