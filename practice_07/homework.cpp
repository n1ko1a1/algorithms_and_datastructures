#include <iostream>
#include <list>
#include <math.h>

struct point
{
    double x;
    double y;
};

double get_angle(point& p)
{   
    double angle = std::atan(p.y / p.x) * 180 / M_PI;

	if (p.x < 0)
		angle += 180;
	else if (p.x >= 0 && p.y < 0)
		angle += 360;
    
    return angle;
}

int main(int argc, char** argcv)
{
    std::list<point> points;

    points.push_back({10, 12});
    points.push_back({-8, 4});
    points.push_back({-3, -12});
    points.push_back({6, -3});
    points.push_back({3, 3});
    points.push_back({4, -9});
    
    std::cout << "Unsorted points:" << std::endl;
    for (auto p : points)
        std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;

    points.sort([](point& p1, point& p2) { return get_angle(p1) < get_angle(p2); });

    std::cout << std::endl << "Sorted points:" << std::endl;
    for (auto p : points)
        std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;

    return 0;
}