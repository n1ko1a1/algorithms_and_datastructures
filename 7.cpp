#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct dot {
    double x;
    double y;
};

double getAngle(const dot& d) {
    return atan2(d.y, d.x);
}

bool comparedots(const dot& d1, const dot& d2) {
    return getAngle(d1) < getAngle(d2);
}

void sortdots(std::vector<dot>& dots) {
    std::sort(dots.begin(), dots.end(), comparedots);
}

int main() {
    std::vector<dot> dots = { {0, 1}, {1, 1}, {5, 88}, {2.1, 0} };
    sortdots(dots);
    for (const dot& d : dots) {
        std::cout << "(" << d.x << ", " << d.y << ")" << std::endl;
    }
    return 0;
}
