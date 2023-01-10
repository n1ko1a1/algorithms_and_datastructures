/*написать структуру, или уласс точки на двумерной плоскости. 
И метод к этой структуре который сортирует список точек согласно часовому порядку относитльно начала оси координат.
На вход методу передается список(вектор) с точками в произволном порядке, 
на выход нговый список с отсортированными точками относительно часового порядка. первая торчка в выходном и входном массивах одинакова.*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Point {
    double x;
    double y;
};

bool Comparer(const Point& p1, const Point& p2) {
    return (atan2(p1.y, p1.x) > atan2(p2.y, p2.x));
}

void PointsSorter(std::vector<Point>& points) {
    std::sort(points.begin(), points.end(), Comparer);
}

int main() {
    std::vector<Point> points = {
      {1, 2},
      {2, 2},
      {3, 4},
      {3, 1},
      {0, 0},
      {5, 6},
      {1, 0},
      {8, 4}
    };

    PointsSorter(points);

    for (const Point& p : points) {
        std::cout << p.x << ", " << p.y << std::endl;
    }

}
