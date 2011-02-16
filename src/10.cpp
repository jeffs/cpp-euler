/** @file 10.cpp Problem 10: Summation of primes
 *
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 */

#include "factoring.hpp"

/// @cond
#include <cassert>  // assert
#include <cstdint>  // uint64_t
#include <iostream> // cout
/// @endcond

using std::uint64_t;

uint64_t sum(uint64_t n)
{
    assert(n > 0);
    uint64_t r = 0;
    std::vector<bool> p;
    factoring::identify_primes(&p, n - 1);
    for (uint64_t i = 2; i < n; ++i) {
        if (p[i])
            r += i;
    }
    return r;
}

int main()
{
    assert(sum(10) == 17);
    std::cout << sum(2'000'000) << std::endl;
}
