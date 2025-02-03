#ifndef EDGE
#define EDGE

#include "point.hpp"

#include <iostream>

template <typename T>
struct edge
{
    point<T> from, to;
    int ymax, ymin;
    float m, mInv;
    bool vert, horz;

    edge() {}
    edge(const point<T> &from, const point<T> &to) : from(from), to(to)
    {
        vert = to.x - from.x == 0;
        horz = to.y - from.y == 0;
        int dy = to.y - from.y;
        int dx = to.x - from.x;
        if (!vert)
            m = dy / (float)dx;
        if (!horz)
            mInv = dx / dy;
        ymax = from.y > to.y ? from.y : to.y;
        ymin = from.y > to.y ? to.y : from.y;
    }

    friend std::ostream &operator<<(std::ostream &os, const edge<T> &e)
    {
        os << "Edge from " << e.from << " to " << e.to;
        return os;
    }
};

#endif