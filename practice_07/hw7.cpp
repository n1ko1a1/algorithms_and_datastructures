#include <iostream>
#include <list>
#include <cmath>
#include<valarray>

struct point
{
    float x;
    float y;
};

float get_angle(point& point)
{
    float angle = std::atan2(point.y, point.x)*180/M_PI;
    if (angle < 0)
        angle += 360;
    return angle;
}
void clock_sort(std::list <point>&point_list)
{
    struct point first_point;
    first_point = point_list.front();
    point_list.sort([](point& point_1, point& point_2){return get_angle(point_1) > get_angle(point_2); });
    int a = 0;
    for (auto el : point_list)
    {
        if (el.x == first_point.x && el.y == first_point.y)
            break;
        a+=1;
        point_list.push_back(el);
        
    }
    for (int i = 0; i < a; i++)
        point_list.pop_front();
}

void Print(std::list <point>&point_list)
{
    for (point p : point_list)
        std::cout << "[" << p.x << ", " << p.y << "] " << get_angle(p) << std::endl;
}

int main()
{
    std::list<point> point_list;
    
    point_list.push_back({1, 2});
    point_list.push_back({-5, 3});
    point_list.push_back({-3, -3});
    point_list.push_back({5, -1});
    point_list.push_back({2, 3});
    point_list.push_back({4, -8});
    std::cout << "list:" << std::endl;
    Print(point_list);
    clock_sort(point_list);
    std::cout << "sorted_list:" << std::endl;
    Print(point_list);
    return 0;
}
