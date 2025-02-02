#include <iostream>

#include "point.hpp"
// #include "linedrawing/linedrawing_comparator.hpp" // linedrawing_comp::

using namespace std;

int main()
{
    point<int> start(0, 0), end(10, 7);

    int scan = 4;
    float m = (end.x - start.x) / (float)(end.y - start.y);
    float intersection = m * scan;
    cout << intersection << endl;
    for (int i = 0; i < 10; i++)
    {
        if (i < intersection)
            cout << i << " is left\n";
        else
            cout << i << " is right\n";
    }
    return 0;
}