#ifndef POINT
#define POINT

#include <iostream>

template <typename T>
struct point
{
    T x, y;

    point() {}
    point(T x, T y) : x(x), y(y) {}
    point(const point<T> &p) : x(p.x), y(p.y) {}
    point(const std::pair<int, int> &p) : x(p.first), y(p.second) {}

    void swap(point *other)
    {
        point<T> temp = *this;
        this->x = other->x;
        this->y = other->y;
        other->x = temp.x;
        other->y = temp.y;
    }

    friend std::ostream &operator<<(std::ostream &os, const point<T> &p)
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

#endif