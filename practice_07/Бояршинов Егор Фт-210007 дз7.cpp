#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Point {
  double x;
  double y;
};

bool comparePoints(const Point& p1, const Point& p2) {
  return (atan2(p1.y, p1.x) > atan2(p2.y, p2.x));
}

void sortPoints(std::vector<Point>& points) {
  std::sort(points.begin(), points.end(), comparePoints);
}

int main() {
  // Создаем точки
  std::vector<Point> points = {
    {1, 1},
    {2, 2},
    {2, 0},
    {3, 1},
    {0, 2},
    {0, 0},
    {1, 0},
    {1, 2}
  };

  // Сортируем точки
  sortPoints(points);

  // Выводим точки
  for (const Point& p : points) {
    std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
  }

  return 0;
}
