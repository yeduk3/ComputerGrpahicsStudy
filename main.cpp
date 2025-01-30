#include <iostream>

#include "testalgorithms/brensenham.hpp"
#include "testalgorithms/DDA.hpp"

using namespace std;

int main()
{
    brsh::run();
    dda::run();

    bool flag = false;
    for (int y = 0; y < brsh::TEST_RANGE; y++)
    {
        for (int x = 0; x < brsh::TEST_RANGE; x++)
        {
            if (brsh::map[y][x] != dda::map[y][x])
            {
                cout << "Not Correct on " << x << " " << y << endl;
                flag = true;
            }
        }
    }
    if (flag == false)
        cout << "Same" << endl;
    return 0;
}