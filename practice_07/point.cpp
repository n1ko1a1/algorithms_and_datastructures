#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Point {
    double x;
    double y;
};

double Angles(const Point& p) {
    return atan2(p.y, p.x);
}

bool contrastPoints(const Point& p1, const Point& p2) {
    return Angles(p1) < Angles(p2);
}

void sortedPoints(std::vector<Point>& points) {
    std::sort(points.begin(), points.end(), contrastPoints);
}

int main() {
    std::vector<Point> points = { {0, 0}, {0, 6}, {1, 1}, {3, 2}, {11, 3}, {4, 4}, {4, 0} };
    sortedPoints(points);
    for (const Point& p : points) {
        std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
    }
    return 0;
}
