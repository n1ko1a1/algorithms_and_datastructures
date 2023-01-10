#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;


struct Coord {
    double x;
    double y;
};

double getAngle(const Coord& c) {
    return atan2(c.y, c.x);
}


bool compareAngles(const Coord& first_coord, const Coord& second_coord) {
    return getAngle(first_coord) < getAngle(second_coord);
}


void sortCoordsHourly(vector<Coord>& coords) {
    sort(coords.begin(), coords.end(), compareCoords);
}


int main() {
    vector<Coord> coords = { {-1, 1}, {2, 5}, {2, 6}, {1, 13}, {6, 7} };

    cout << "Координаты в неотсортированном виде: " << endl;
    for (auto coord : coords) {
        cout << "(" << coord.x << ", " << coord.y << ")" << endl;
    }

    sortCoordsHourly(coords);

    cout << endl << "Координаты в отсортированном виде: " << endl;
    for (const Coord& coord : coords) {
        cout << "(" << coord.x << ", " << coord.y << ")" << endl;
    }

    return 0;
}