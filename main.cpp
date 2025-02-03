#include <iostream>
#include <vector>

#include "point.hpp"
#include "edge.hpp"
#include "linedrawing/linedrawing_comparator.hpp" // linedrawing_comp::
#include "scanline/scanline.hpp"                  // linedrawing_comp::

using namespace std;

int main()
{
    // linedrawing_comp::run({0, 50}, {99, 50});
    scanline::run();
}
