#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct point_t
{
    double x_, y_;
};

double distance_(const point_t& point)
{
    return sqrtf(point.x_ * point.x_ + point.y_ * point.y_);
}


int main()
{
    vector<point_t>  source_;
    int N = 0;
    double x_ = 0, y_ = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> x_ >> y_;
        source_.push_back(point_t{ x_, y_ });
    }
    sort(source_.begin(), source_.end(), [](point_t lhs, point_t rhs) {return distance_(lhs) < distance_(rhs); });
    for (point_t& point_ : source_)
    {
        cout << "point with x =" << point_.x_ << " y = " << point_.y_ << endl;
    }
    return 0;
}
