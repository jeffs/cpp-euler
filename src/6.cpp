/** @file 6.cpp Problem 6: Sum square difference
 *
 * The sum of the squares of the first ten natural numbers is,
 *
 * 12 + 22 + ... + 102 = 385 The square of the sum of the first ten natural
 * numbers is,
 *
 * (1 + 2 + ... + 10)2 = 552 = 3025 Hence the difference between the sum of the
 * squares of the first ten natural numbers and the square of the sum is 3025 -
 * 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred
 * natural numbers and the square of the sum.
 */

/// @cond
#include <cassert>  // assert
#include <cstdint>  // uint64_t
#include <iostream> // cout
/// @endcond

using std::uint64_t;

uint64_t diff(uint64_t n)
{
    uint64_t a = 0, b = n * (n + 1) / 2;
    for (uint64_t i = 1; i <= n; ++i)
        a += i * i;
    return b * b - a;
}

int main()
{
    assert(diff(10) == 2640);
    std::cout << diff(100) << std::endl;
}
