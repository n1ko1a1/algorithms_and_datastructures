#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>

struct Point {
    double x;
    double y;
};

double getAngle(const Point& p) 
{
    return atan2(p.y, p.x);
}

bool comparePoints(const Point& p1, const Point& p2) 
{
    return getAngle(p1) < getAngle(p2);
}

void sortPointsHourly(std::vector<Point>& points) 
{
    std::sort(points.begin(), points.end(), comparePoints);
}

int main() 
{
    std::vector<Point> points = { {7, 2}, {3, 4}, {1, 6}, {5, 2} };
    sortPointsHourly(points);
    std::cout<<"Отсортированные точки"<<std::endl;
    for (const Point& p : points) 
    {
        std::cout << "{" << p.x << "; " << p.y << "}" << std::endl;
    }
    return 0;
}
