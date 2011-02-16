/** @file 1.cpp Problem 1: Multiples of 3 and 5
 *
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we
 * get 3, 5, 6 and 9. The sum of these multiples is 23.
 *
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

/// @cond
#include <cassert>  // assert
#include <iostream> // cout
/// @endcond

int sum(int n)
{
    int r = 0;
    for (auto i = 0; i < n; ++i) {
        if (i % 3 == 0 || i % 5 == 0)
            r += i;
    }
    return r;
}

int main()
{
    assert(sum(10) == 23);
    std::cout << sum(1000) << '\n';
}
