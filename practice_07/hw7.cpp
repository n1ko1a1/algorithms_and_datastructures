#include <iostream>
#include <list>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
    double angle;
};

Point add_point(double x_coord, double y_coord) {
    const double pi = 3.1415926535;

    Point point{};
    point.x = x_coord;
    point.y = y_coord;
    point.angle = atan(point.y / point.x) * 180 / pi;

    if (point.x < 0)
        point.angle += 180;
    else if (point.x >= 0 && point.y < 0)
        point.angle += 360;
    return point;
}

int main() {
    list<Point> points;

    int x, y;
    for (int i = 0; i < 8; ++i) {
        cout << "X=";
        cin >> x;
        cout << "Y=";
        cin >> y;
        cout << endl;
        points.push_back(add_point(x, y));
    }

    points.sort([](const Point &a, const Point &b) { return a.angle < b.angle; });

    for (Point &item: points) {
        std::cout << "X: " << item.x << "; Y: " << item.y << "; angle: " << item.angle << std::endl;
    }

    return 0;
}