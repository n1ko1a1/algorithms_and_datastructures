#include <iostream>
#include <list>
#include <math.h>

class Point
{
public:
    double x;
    double y;

    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
};

void SortPoints(std::list<Point*>& points)
{   
    points.sort(
        [](Point* p1, Point* p2) { 
            double angle1 = std::atan(p1->y / p1->x) * 180 / M_PI;
            
            if (p1->x < 0)
		        angle1 += 180;
	        else if (p1->x >= 0 && p1->y < 0)
		        angle1 += 360;

            double angle2 = std::atan(p2->y / p2->x) * 180 / M_PI;
            
            if (p2->x < 0)
		        angle2 += 180;
	        else if (p2->x >= 0 && p2->y < 0)
		        angle2 += 360;

            return angle1 < angle2;
        }
    );
}

int main()
{
    double x, y;
    std::list<Point*> points;

    for (int i = 0; i < 15; i++)
    {
        x = rand() % 20 * 0.1 * (i % 2 ? -1 : 1);
        y = rand() % 20 * 0.1 * (i % 3 ? -1 : 1);
        points.push_back(new Point(x, y));
    }

    std::cout << "Points without sorting:" << std::endl;
    for (auto p : points)
        std::cout << "x: " << p->x << ", y: " << p->y << std::endl;

    SortPoints(points);

    std::cout << std::endl << "Points with sorting:" << std::endl;
    for (auto p : points)
        std::cout << "x: " << p->x << " y: " << p->y << std::endl;

    return 0;
}