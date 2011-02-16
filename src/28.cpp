/** @file 28.cpp Problem 28: Number spiral diagonals
 *
 * Starting with the number 1 and moving to the right in a clockwise direction
 * a 5 by 5 spiral is formed as follows:
 *
 *      21 22 23 24 25
 *      20  7  8  9 10
 *      19  6  1  2 11
 *      18  5  4  3 12
 *      17 16 15 14 13
 *
 * It can be verified that the sum of the numbers on the diagonals is 101.
 *
 * What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral
 * formed in the same way?
 */

/// @cond
#include <cassert>  // assert
#include <iostream> // cout
/// @endcond

/** Returns the sum of the numbers on the diagonals of an n by n spiral. */
int sum(int n)
{
    int r = 1;                          // The center 1 is counted only once.
    for (int d = 1; d <= n / 2; ++d) {  // For each radius except 0:
        int s = d * 2;                  //   Find the side length.
        int m = (s - 1) * (s - 1);      //   Start just after the inner square.
        for (int i = 1; i <= 4; ++i)    //   For each of the four sides:
            r += m + i * s;             //     Add its corner value.
    }
    return r;
}


int main()
{
    assert(sum(5) == 101);
    std::cout << sum(1001) << std::endl;
}
