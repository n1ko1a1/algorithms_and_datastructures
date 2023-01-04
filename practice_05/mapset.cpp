#include <iostream>
#include <set>
#include <map>
#include <string>

//n - комманд
//1 - добавить элемент в мн-во
//2 - проверить есть ли элемент в мн-ве
//3 - удалить эл-т

template< typename T>
class MySet
{
public:
    void AddElement(T el){}
private:
    std::set<T> data_;
};
/*
int main( int argc, char ** arcgv )
{
    std::set<int> s;
    int type, n, value;
    std::cin >> n;
    std::cout << "argc: " << argc << std::endl;
    for(int i =0; i < argc; i++)
    {
        std::cout<< arcgv[i] << std::endl;
    }


    for(int i = 0; i < n; i++)
    {
        std::cin >>type;
        std::cin >> value;

        if (type == 1)
        {
            s.insert(value);
        }
        else if (type==2)
        {
            auto found = s.find(value);
            if (found != s.end() )
                std::cout << value << " found in the set\n";
            else
                std::cout << value << " is not found in the set\n";
        }
        else
        {}
    }

    return 0;
}
*/
/*
int main( int argc, char ** arcgv )
{
    std::set<int> s{1,2,3, 4, 5}; // 1 2 3 < 4 5 6
    for ( auto current = s.begin(); current != s.end(); current++)
    {
        std::cout << *current << std::endl;
    }
    auto bound = s.upper_bound(4);
    std::cout << "bound " << *bound << std::endl;

}*/

std::ostream& operator<<(std::ostream& os, std::pair<std::string, int> p)
{
    os << "key: " << p.first << "; value: " << p.second << std::endl;
    return os;
}

int main( int argc, char ** arcgv )
{
    std::map<std::string, int> my_map;//pair<>
    my_map.insert({"Kozume", 8355});
    my_map.insert({"Ab", 8235});

    std::map<std::string, std::vector<int>> my_map_2;//pair<>
    my_map.insert({"Kozume", 8355});

    for ( auto current = my_map.begin(); current != my_map.end(); current++)
    {
        std::cout << *current << std::endl;
    }

    for ( auto pa : my_map)
    {
        std::cout << pa.first << " " << pa.second << std::endl;
    }

}
//asdjkfh sjdfhalk sjkahfl

