#include<iostream>

int main()
{
    int a = 5;
    int& k = a;

    std::cout << &a << " " << &k << std::endl;
    return 0;
}