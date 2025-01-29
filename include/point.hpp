#ifndef POINT
#define POINT

template <typename T>
struct point
{
    T x, y;

    point() {}
    point(T x, T y) : x(x), y(y) {}

    void swap(point *other)
    {
        point<T> temp = *this;
        this->x = other->x;
        this->y = other->y;
        other->x = temp.x;
        other->y = temp.y;
    }
};

#endif