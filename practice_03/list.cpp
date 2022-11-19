#include <iostream>
#include <list>
#include <set>

bool predicat(int val)
{
    return val < 2;
}

int main()
{
    /*std::list<int> v = {1,2,3,4};
    std::list<int>::iterator iter = v.end();

    while(iter != v.begin())
    {
        --iter;
        std::cout << *iter << std::endl;

    }*/
    /*
    for (int e : v)
    {
        std::cout << e << std::endl;
    }*/
    //std::list<int> lst;
    int input_val=0;
    /*while(true)
    {
        std::cin >> input_val;
        if (input_val == 0)
            break;
        lst.push_back(input_val);
    }*/
    /*lst.sort();
    lst.unique();*/
    std::set<int> s;
    /*for (int e : lst)
    {
        if (!s.contains(e))
        {
            s.insert(e);
            std::cout << e << std::endl;
        }
    }*/

    int line = 3;
    std::list<int> lst = {1,2,3,4,5};
    std::size_t res = lst.remove_if( [line](int val){return val < line;} );
    //std::size_t res = lst.remove_if(predicat);
    std::cout << "res: " << res << std::endl;
    for (int e : lst)
    {
        std::cout << e << std::endl;
    }


    return 0;
}
