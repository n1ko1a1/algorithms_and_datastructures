#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Point {
    double x;
    double y;
};

double getAngle(const Point& p) {
    // Vychislyaet ugol tochki otnositel'no nachala koordinat
    return atan2(p.y, p.x);
}

bool comparePoints(const Point& p1, const Point& p2) {
    // Sravnivaet ugly tochek otnositel'no nachala koordinat
    return getAngle(p1) < getAngle(p2);
}

void sortPointsHourly(std::vector<Point>& points) {
    // Sortirovka tochek v sootvetstvii s chasovym poryadkom
    std::sort(points.begin(), points.end(), comparePoints);
}

int main() {
    std::vector<Point> points = { {0, 0}, {2, 3}, {1, 1}, {3, 2} };
    sortPointsHourly(points);
    for (const Point& p : points) {
        std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
    }
    return 0;
}
