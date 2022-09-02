#include<iostream> //headers
#include<string>
//g++ -Wall -Werror -g --std=c++20 complex_1.cpp
//g++ - compiler; -Wall - show all the errors; 
//-Werror - treat warnings as errors
int main()//entry point
{
    std::string input;//variable with type string
    std::cin >> input;//standard input
    int n = input.size();
    int sum = 0;
    for( int i = 0; i < n; i++ )//n
        for( int j = 0; j < 2 * i; j++ )
        //01 0123 012345 0123456 012..2i-1
            sum++;//0 + 2 + 4 + 6 + ... 2(n-1)
    std::cout << sum << std::endl;
    return 0;//code of return
}