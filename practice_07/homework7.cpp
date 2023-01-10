#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct point {
    int x;
    int y;
    double angle;
} ;

bool comparator (point a, point b) {
    return a.angle > b.angle;
}

int main() {
    int amount_of_points;
    vector <point> point_storage;

    point simple_point {};
    int target_point_counter;
    double target_point_angle;

    cout << "Please enter the number of points: ";
    cin >> amount_of_points;

    for (int i = 0; i < amount_of_points; i++){
        cout << "Point #" << i << endl;
        cout << "Enter an X coordinate: ";
        cin >> simple_point.x;
        cout << "Enter an Y coordinate: ";
        cin >> simple_point.y;

        simple_point.angle = atan2(simple_point.y, simple_point.x);

        if (i == 0){
            target_point_angle = simple_point.angle;
        }

        point_storage.push_back(simple_point);
    }

    sort(point_storage.begin(), point_storage.end(), comparator);

    for (int i = 0; i < point_storage.size(); ++i){
        if (point_storage[i].angle == target_point_angle) target_point_counter = i;
    }

    if (target_point_counter != 0) {
        for (int i = 0; i < target_point_counter; ++i) {
            point_storage.push_back(point_storage[i]);
        }
    }

    for (int i = target_point_counter, counter = 0; i < point_storage.size(); ++i, ++counter){
        cout << "Point #" << counter << ": (" << point_storage[i].x << "; " << point_storage[i].y << ")" << endl;
    }

    return 0;
}

