// Line Drawing Algorithm in Rasterization
// Input: 2 Points in screen coordinate
// Output: Line between above points

#ifndef BRENSENHAMS_ALGORITHM
#define BRENSENHAMS_ALGORITHM

#include <iostream>

namespace brsh
{
    const int TEST_RANGE = 100;

    struct point
    {
        int x, y;

        point() {}
        point(int x, int y) : x(x), y(y) {}

        void swap(point *other)
        {
            point temp = *this;
            this->x = other->x;
            this->y = other->y;
            other->x = temp.x;
            other->y = temp.y;
        }
    };

    void run()
    {
        point end(55, 10), start(99, 17);
        if (start.x < 0 && start.x >= TEST_RANGE)
            std::cerr << "start x out of range" << std::endl;
        if (start.y < 0 && start.y >= TEST_RANGE)
            std::cerr << "start y out of range" << std::endl;
        if (end.x < 0 && end.x >= TEST_RANGE)
            std::cerr << "end x out of range" << std::endl;
        if (end.y < 0 && end.y >= TEST_RANGE)
            std::cerr << "end y out of range" << std::endl;

        bool map[TEST_RANGE][TEST_RANGE] = {
            false,
        };

        map[start.y][start.x] = true;
        map[end.y][end.x] = true;

        if (start.x > end.x)
        {
            start.swap(&end);
        }
        bool flip = false;
        int dy = end.y - start.y;
        int dx = end.x - start.x;
        if (dy > dx)
        {
            flip = true;
        }

        // Algorithm
        int decision = -3 * dy + 2 * dx;
        for (int i = start.x + 1; i < end.x; i++)
        {
            if (decision < 0)
                decision -= 2 * (dy - dx);
            else
                decision -= 2 * dy;

            start.x++;

            if (decision < 0)
                start.y++;

            map[start.y][start.x] = true;
        }

        for (int y = TEST_RANGE - 1; y >= 0; y--)
        {
            for (int x = 0; x < TEST_RANGE; x++)
            {
                char result = map[y][x] ? 'o' : 'x';
                std::cout << result;
            }
            std::cout << std::endl;
        }
    }

}

#endif