#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

struct Point {
  double x;
  double y;
  
  Point(double x, double y) : x(x), y(y) {}
  
  double distance(const Point& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return sqrt(dx * dx + dy * dy);
  }
  
  bool operator<(const Point& other) const {
    if (x == 0 && y == 0) return false;
    if (other.x == 0 && other.y == 0) return true;
    
    double angle1 = std::atan2(y, x);
    double angle2 = std::atan2(other.y, other.x);
    return angle1 < angle2;
  }
};

std::vector<Point> sortPoints(const std::vector<Point>& points) {
  std::vector<Point> sortedPoints = points;
  std::sort(sortedPoints.begin(), sortedPoints.end());
  return sortedPoints;
}

int main() {
  std::vector<Point> points = { Point(1, 2), Point(3, 4), Point(5, 6) };
  std::vector<Point> sortedPoints = sortPoints(points);
  
  for (const Point& p : sortedPoints) {
    std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
  }
  
  return 0;
}
