#include <iostream>
#include <list>
#include <cmath>
#include <iomanip>

struct Point {
	double x;
	double y;
	double angle;
};

Point add_point(double x_coor, double y_coor) {
	const double pi = 3.1415926535;

	Point point{};
	point.x = x_coor;
	point.y = y_coor;
	point.angle = atan(point.y / point.x) * 180 / pi;

	if (point.x < 0)
		point.angle += 180;
	else if (point.x >= 0 && point.y < 0)
		point.angle += 360;
	return point;
}

int main() {
	std::list<Point> points;

	points.push_back(add_point(1, -1));
	points.push_back(add_point(0, -1));
	points.push_back(add_point(1, 1));
	points.push_back(add_point(0, 1));
	points.push_back(add_point(-1, 1));
	points.push_back(add_point(-1, -1));
	points.push_back(add_point(-1, 0));
	points.push_back(add_point(1, 0));

	points.sort([](const Point& a, const Point& b) { return a.angle < b.angle; });

	for (Point& item : points)
	{
		std::cout << "X: " << item.x << "; Y: " << item.y << "; angle: " << item.angle << std::endl;
	}

	return 0;
}
