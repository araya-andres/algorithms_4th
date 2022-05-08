#pragma once

#include <ostream>

namespace math
{
template <typename T>
struct Point2D
{
    Point2D(T x = 0, T y = 0): x{x}, y{y} {}
    const T x;
    const T y;
};

template <typename T>
double squared_distance(const Point2D<T>& p, const Point2D<T>& q)
{
    auto dx = p.x - q.x;
    auto dy = p.y - q.y;
    return dx * dx + dy * dy;
}
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const math::Point2D<T>& p)
{
    return os << '(' << p.x << ',' << p.y << ')';
}