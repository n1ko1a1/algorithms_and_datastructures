#include <iostream>
#include <math.h>
#include <list>

struct point
{
    float x;
    float y;
};

float GetAngle(point p)
{
    float a = std::atan(p.y / p.x) * 180 / M_PI;

    if (p.x < 0)
        a += 180;
    else if (p.x >= 0 && p.y < 0)
        a += 360;

    return a;
}

void Sort(std::list<point>& pnts)
{
    pnts.sort([](const point& p1, const point& p2) { return GetAngle(p1) < GetAngle(p2); }); 
}

void Print(std::list<point>& pnts, std::string h = "")
{
    std::cout << h << std::endl;
    for (auto p : pnts)
        std::cout << "|x = " << p.x << ", y = " << p.y << "|" << std::endl;
}

int main()
{
    std::list<point> pnts;

    pnts.push_back({12, 5});
    pnts.push_back({-10, -3});
    pnts.push_back({2, -7});
    pnts.push_back({-22, 10});
    pnts.push_back({-2, 13});
    pnts.push_back({16, -1});
    pnts.push_back({-2, -23});
    pnts.push_back({13, -5});
    pnts.push_back({1, 1});
    pnts.push_back({18, 5});

    Print(pnts, "Points");
    Sort(pnts);
    Print(pnts, "\nPoints after sorting");

    return 0;
}