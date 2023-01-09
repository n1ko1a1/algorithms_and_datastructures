#include <iostream>
#include <list>
#include <math.h>

struct point
{
    float x;
    float y;
};

void PrintPoints(std::list<point> points, std::string header)
{
    std::cout << header << std::endl;
    for (auto p : points)
        std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
}

float GetAngle(point& p)
{   
    float angle = std::atan(p.y / p.x) * 180 / M_PI;

	if (p.x < 0)
		angle += 180;
	else if (p.x >= 0 && p.y < 0)
		angle += 360;
    
    return angle;
}

int main(int argc, char** argcv)
{
    float x, y;
    std::list<point> points;

    for (int i = 0; i < 20; i++)
    {
        x = rand() % 1000 * 0.1 + (-50);
        y = rand() % 1000 * 0.1 + (-50);
        points.push_back({x, y});
    }
    
    PrintPoints(points, "<<< Unsorting list of points >>>");

    points.sort
    ([] (point& p1, point& p2) 
        { 
            return GetAngle(p1) < GetAngle(p2); 
        }
    );

    std::cout << std::endl;
    PrintPoints(points, "<<< Sorted list of points >>>");

    return 0;
}