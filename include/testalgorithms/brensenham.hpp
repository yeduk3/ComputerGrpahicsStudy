// Line Drawing Algorithm in Rasterization
// Input: 2 Points in screen coordinate
// Output: Line between above points

#ifndef BRENSENHAMS
#define BRENSENHAMS

#include <iostream>

#include "point.hpp"

namespace brsh
{
    const int TEST_RANGE = 100;

    bool map[TEST_RANGE][TEST_RANGE] = {
        false,
    };

    void run()
    {
        point<int> start(4, 3), end(49, 90);
        if (start.x < 0 && start.x >= TEST_RANGE)
            std::cerr << "start x out of range" << std::endl;
        if (start.y < 0 && start.y >= TEST_RANGE)
            std::cerr << "start y out of range" << std::endl;
        if (end.x < 0 && end.x >= TEST_RANGE)
            std::cerr << "end x out of range" << std::endl;
        if (end.y < 0 && end.y >= TEST_RANGE)
            std::cerr << "end y out of range" << std::endl;

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
            int temp = start.y;
            start.y = start.x;
            start.x = temp;
            temp = end.y;
            end.y = end.x;
            end.x = temp;
        }
        dy = end.y - start.y;
        dx = end.x - start.x;

        // Algorithm
        int decision = -4 * dy + 3 * dx;
        for (int i = start.x + 1; i < end.x; i++)
        {
            if (decision < 0)
                decision -= 2 * (dy - dx);
            else
                decision -= 2 * dy;

            start.x++;

            if (decision < 0)
                start.y++;

            if (flip)
                map[start.x][start.y] = true;
            else
                map[start.y][start.x] = true;
        }

        // Output
        std::cout << "Brensenham's algorithm:" << std::endl;
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