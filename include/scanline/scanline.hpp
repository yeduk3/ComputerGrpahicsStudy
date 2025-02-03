#ifndef SCANLINE
#define SCANLINE

#include "point.hpp"
#include "edge.hpp"

#include <iostream>

namespace scanline
{

    void run()
    {
        // Input
        std::vector<point<int>> polygon = {{0, 0}, {50, 99}, {99, 0}, {0, 50}, {99, 50}}; // star
        // std::vector<point<int>> polygon = {{25, 25}, {25, 75}, {50, 50}, {75, 75}, {75, 25}}; // M-shape
        // std::vector<point<int>> polygon = {{25, 25}, {25, 75}, {75, 75}, {75, 25}}; // just rectagle
        std::vector<edge<int>> edges;

        for (int i = 0; i < polygon.size(); i++)
        {
            auto e = edge<int>(polygon[i], polygon[(i + 1) % polygon.size()]);
            if (!e.horz)
            {
                edges.push_back(e);
                std::cout << e << std::endl;
            }
        }

        std::vector<edge<int>> activated;

        for (int scan = 99; scan >= 0; scan--)
        {
            printf("y = %2d: ", scan);

            int inout = 0;
            // activated에서 사라져야될 것 확인
            for (auto it = activated.begin(); it != activated.end();)
            {
                if (it->ymin >= scan)
                {
                    activated.erase(it);
                }
                else
                    it++;
            }

            // activated 되어야할 것 확인.
            for (auto it = edges.begin(); it != edges.end();)
            {
                if (it->ymax > scan)
                {
                    activated.push_back(*it);
                    edges.erase(it);
                }
                else
                    it++;
            }

            // in / out test
            std::vector<edge<int>> active = activated;
            for (int x = 0; x < 100; x++)
            {
                for (auto it = active.begin(); it != active.end(); it++)
                {
                    if (it->mInv * (scan - it->from.y) < x - it->from.x)
                    {
                        inout++;
                        active.erase(it);
                        break;
                    }
                }
                if (inout % 2 == 0)
                    std::cout << "o";
                else
                    std::cout << "i";
            }
            std::cout << std::endl;
        }
    }

}

#endif