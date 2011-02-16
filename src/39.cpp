/** @file 39.cpp Problem 39: Integer right triangles
 *
 * If p is the perimeter of a right angle triangle with integral length sides,
 * {a,b,c}, there are exactly three solutions for p = 120.
 *
 *      {20,48,52}, {24,45,51}, {30,40,50}
 *
 * For which value of p <= 1000, is the number of solutions maximised?
 */

/// @cond
#include <cmath>    // sqrt
#include <cassert>  // assert
#include <iostream> // cout
/// @endcond

int count_solutions(int p)
{
    int r = 0;
    for (int a = 1; a < p; ++a) {
        for (int b = a; b < p; ++b) {
            int a2 = a * a,
                b2 = b * b,
                c  = std::sqrt(a2 + b2);
            if (a2 + b2 == c * c && a + b + c == p)
                ++r;
        }
    }
    return r;
}

int main()
{
    assert(count_solutions(120) == 3);

    int r = 0, m = 0;
    for (int p = 3; p <= 1000; ++p) {
        int n = count_solutions(p);
        if (n > m) {
            r = p;
            m = n;
        }
    }
    std::cout << r << std::endl;
}
