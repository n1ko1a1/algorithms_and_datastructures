#include<iostream> 
#include<string>
#include<cmath>
int main()
{
    int n, root;
    std::cin >> n;
    root = std::sqrt( n );
    for( int i=2;i<=root;i++ ){
        if(n%i == 0){
            std::cout << i << std::endl;
            return 0;
        }
    }
    std::cout << n << " is prime" << std::endl;
    return 0;
}