#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    double x, y;
};

bool comparePoints(const Point& p1, const Point& p2) {
    double angle1 = atan2(p1.y, p1.x);
    double angle2 = atan2(p2.y, p2.x);
    return angle1 < angle2;
}

void sortPoints(std::vector<Point>& points) {
    std::sort(points.begin(), points.end(), comparePoints);
}

int main() {
    std::vector<Point> points = { {1, 1}, {2, 2}, {2, 0}, {3, 3}, {0, 0}, {1, 2} };
    sortPoints(points);
    for (const Point& p : points) {
        std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
    }
    return 0;
}
