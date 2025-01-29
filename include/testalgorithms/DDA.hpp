#ifndef DDA
#define DDA

#include <iostream>
#include "point.hpp"

namespace dda
{

    const int TEST_RANGE = 100;

    void run()
    {
        point<int> start(55, 10), end(99, 17);

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
        float m = dy / (float)dx;
        float y = start.y;
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