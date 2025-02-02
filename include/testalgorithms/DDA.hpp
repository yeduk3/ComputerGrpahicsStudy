// DDA for line drawing
// Input: 2 Points in screen coordinate
// Output: Line between above points
// Assume that the line starts from the center point of start pixel and ends into the center point of end pixel

#ifndef DDA
#define DDA

#include <iostream>
#include "point.hpp"

namespace dda
{

    const int TEST_RANGE = 100;

    bool map[TEST_RANGE][TEST_RANGE] = {
        false,
    };

    void run(point<int> start, point<int> end)
    {
        // Out of range test
        if (start.x < 0 && start.x >= TEST_RANGE)
            std::cerr << "start x out of range" << std::endl;
        if (start.y < 0 && start.y >= TEST_RANGE)
            std::cerr << "start y out of range" << std::endl;
        if (end.x < 0 && end.x >= TEST_RANGE)
            std::cerr << "end x out of range" << std::endl;
        if (end.y < 0 && end.y >= TEST_RANGE)
            std::cerr << "end y out of range" << std::endl;

        // setup
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
        map[start.y][start.x] = true;
        map[end.y][end.x] = true;
        float m = dy / (float)dx;
        float y = start.y + 0.5f;
        for (int i = start.x + 1; i < end.x; i++)
        {
            y += m;
            map[(int)y][i] = true;
        }

        // Output
        std::cout << "DDA algorithm:" << std::endl;
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