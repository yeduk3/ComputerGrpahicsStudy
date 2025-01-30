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
        point<int> start(4, 3), end(90, 49); // case 1(1 quad, not steep) pass
        // point<int> start(4, 3), end(49, 90); // case 2(1 quad, steep) pass
        // point<int> start(4, 90), end(49, 3); // case 3(2 quad, steep) pass
        // point<int> start(4, 30), end(90, 9); // case 4(2 quad, not steep) pass
        // point<int> end(4, 3), start(90, 49); // case 5(3 quad, not steep) pass
        // point<int> end(4, 3), start(49, 90); // case 6(3 quad, steep) pass
        // point<int> start(4, 90), end(49, 3); // case 7(4 quad, steep) pass
        // point<int> start(4, 90), end(49, 70); // case 8(4 quad, not steep) pass

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

        int moveX = 1, moveY = 1;
        int dx = end.x - start.x;
        if (dx < 0)
        {
            moveX = -1;
            dx = -dx;
        }
        int dy = end.y - start.y;
        if (dy < 0)
        {
            moveY = -1;
            dy = -dy;
        }
        bool flip = dy > dx;
        if (flip)
        {
            int temp = start.x;
            start.x = start.y;
            start.y = temp;

            temp = end.x;
            end.x = end.y;
            end.y = temp;

            temp = dy;
            dy = dx;
            dx = temp;

            temp = moveX;
            moveX = moveY;
            moveY = temp;
        }

        // Algorithm
        int decision = -4 * dy + 3 * dx;
        int y = start.y;
        for (int x = start.x + moveX; x != end.x; x += moveX)
        {
            if (decision < 0)
                decision -= 2 * (dy - dx);
            else
                decision -= 2 * dy;

            if (decision < 0)
                y += moveY;

            if (flip)
                map[x][y] = true;
            else
                map[y][x] = true;
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