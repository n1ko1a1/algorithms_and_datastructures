#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <string>

template<typename T>
void PrintLenCapacityVal(std::vector<T> & vec)
{
    std::cout << "len: " << vec.size() << "; capacity: " << vec.capacity() << std::endl;
}
template<typename T>
void FillVec(std::vector<T> & vec, int n)
{
    for(int i = 0; i < n; i++)
    {
        vec.push_back(i);
    }
}
template<typename T>
void PrintVec(std::vector<T> & vec)
{
    int len = vec.size();
    for(int i = 0; i < len; i++)  //3  0 1 2
    {
        std::cout << "value: " << vec[i] << std::endl;
    }
}
template<typename T>
int FindMax(std::vector<T> & vec)
{
    int max = INT_MIN;
    int len = vec.size();
    for(int i = 0; i < len; i++)
    {
        if (vec[i] > max)
            max = vec[i];
    }
    return max;
}

template<typename T>
void PrintLenCapacityValTemplate(T & vec)
{
    std::cout << "len: " << vec.size() << "; capacity: " << vec.capacity() << std::endl;
}

int main()
{
    int i;
    std::string s;
    bool b;
    char c;

    std::cout << "sizeof int: " << sizeof(i) << std::endl;
    std::cout << "sizeof string: " << sizeof(s) << std::endl;
    std::cout << "sizeof bool: " << sizeof(b) << std::endl;
    std::cout << "sizeof bool: " << sizeof(bool) << std::endl;
    std::cout << "sizeof char: " << sizeof(c) << std::endl;
    std::cout << "CHAR_BIT: " << CHAR_BIT << std::endl;

    std::vector<bool> vec_b(1024);
    std::cout << "sizeof vec_b: " << sizeof(vec_b) << std::endl;
    std::cout << "size of 1024 bool: " << 1024*sizeof(bool) << std::endl;






    return 0;
}
