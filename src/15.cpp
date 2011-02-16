/** @file 15.cpp Problem 15: Lattice paths
 *
 * Starting in the top left corner of a 2X2 grid, and only being able to move
 * to the right and down, there are exactly 6 routes to the bottom right
 * corner.
 *
 * How many such routes are there through a 20X20 grid?
 */

//                                     M x N
//                                     -----
//
// . .     1                           1 x 2
//
// . .
// . .     2 = 1 + 1                   2 x 2
//
// . .
// . .     3 = 2 + 1                   3 x 2
// . .
//
// . .
// . .
// . .     4 = 3 + 1                   4 x 2
// . .
//
// . . .   1
//
// . . .
// . . .   3
//
// . . .
// . . .   6 = 3 + 3                   3 x 3
// . . .
//
// . . .
// . . .
// . . .   10 = 6 + 4                  4 x 3
// . . .
//
// . . . . 1
//
// . . . .
// . . . . 4 = 3 + 1
//
// . . . .
// . . . . 10 = 6 + 4
// . . . .
//
// . . . .
// . . . .
// . . . . 20 = 10 + 10                4 x 4
// . . . .

/// @cond
#include <cassert>          // assert
#include <cstdint>          // uint64_t
#include <iostream>         // cout
#include <unordered_map>    // unordered_map
/// @endcond

using std::uint64_t;

std::unordered_map<uint64_t, std::unordered_map<uint64_t, uint64_t>> memo;

uint64_t imp(uint64_t m, uint64_t n)
{
    // The base case is just a line.  There's only one way to walk a line.
    auto& r = memo[m][n];
    if (r == 0)
        r = m < 2 || n < 2 ? 1 : imp(m - 1, n) + imp(m, n - 1);
    return r;
}

uint64_t count(uint64_t n)
{
    return imp(n + 1, n + 1);
}

int main()
{
    assert(count(2) == 6);
    std::cout << count(20) << std::endl;
}
