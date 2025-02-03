#ifndef LINEDRAWING_COMPARATOR
#define LINEDRAWING_COMPARATOR

#include <iostream>

#include "point.hpp"
#include "brensenham.hpp"
#include "DDA.hpp"

using namespace std;

namespace linedrawing_comp
{

    void run(const point<int> &start, const point<int> &end)
    {
        // point<int> start(4, 3), end(90, 49); // case 1(1 quad, not steep) pass
        // point<int> start(4, 3), end(49, 90); // case 2(1 quad, steep) pass
        // point<int> start(4, 90), end(49, 3); // case 3(2 quad, steep) pass
        // point<int> start(4, 30), end(90, 9); // case 4(2 quad, not steep) pass
        // point<int> end(4, 3), start(90, 49); // case 5(3 quad, not steep) pass
        // point<int> end(4, 3), start(49, 90); // case 6(3 quad, steep) pass
        // point<int> start(4, 90), end(49, 3); // case 7(4 quad, steep) pass
        // point<int> start(4, 90), end(49, 70); // case 8(4 quad, not steep) pass

        brsh::run(start, end);
        dda::run(start, end);

        bool flag = false;
        for (int y = 0; y < brsh::TEST_RANGE; y++)
        {
            for (int x = 0; x < brsh::TEST_RANGE; x++)
            {
                if (brsh::map[y][x] != dda::map[y][x])
                {
                    cout << "Not Correct on x = " << x << ", y = " << y << endl;
                    flag = true;
                }
            }
        }
        if (flag == false)
            cout << "Same" << endl;
    }

}

#endif