#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Point {
    double x;
    double y;
};

double getAngle(const Point& p) {
    return atan2(p.y, p.x);
}

bool comparePoints(const Point& p1, const Point& p2) {
    return getAngle(p1) < getAngle(p2);
}

void sortPointsHourly(std::vector<Point>& points) {
    std::sort(points.begin(), points.end(), comparePoints);
}

int main() {
    std::vector<Point> points = { {-6, 5}, {0, 0}, {1, -5}, {3, 1}, {8, 2} };

    std::cout << "Unsorted points:" << std::endl;
    for (auto p : points)
        std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;

    sortPointsHourly(points);

    std::cout << std::endl << "Sorted points:" << std::endl;
    for (const Point& p : points) {
        std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
    }
    return 0;
}