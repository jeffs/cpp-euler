/** @file 23.cpp Problem 23: Non-abundant sums
 *
 * A perfect number is a number for which the sum of its proper divisors is
 * exactly equal to the number. For example, the sum of the proper divisors of
 * 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect
 * number.
 *
 * A number n is called deficient if the sum of its proper divisors is less
 * than n and it is called abundant if this sum exceeds n.
 *
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
 * number that can be written as the sum of two abundant numbers is 24. By
 * mathematical analysis, it can be shown that all integers greater than 28123
 * can be written as the sum of two abundant numbers. However, this upper limit
 * cannot be reduced any further by analysis even though it is known that the
 * greatest number that cannot be expressed as the sum of two abundant numbers
 * is less than this limit.
 *
 * Find the sum of all the positive integers which cannot be written as the sum
 * of two abundant numbers.
 */

#include "factoring.hpp"    // sum_proper_divisors

/// @cond
#include <cstdint>          // uint64_t
#include <iostream>         // cout
/// @endcond

using std::uint64_t;

uint64_t sum(uint64_t n)
{
    // Identify all abundant numbers less than n.               -- O(n log n)
    // Collect all pair-wise sums from abundants * abundants.   -- O(n * n)
    // Count from 1 to n, summing those not in the set.         -- O(n)

    std::vector<bool> abundant(n);
    for (uint64_t i = 0; i <= n; ++i) {
        if (factoring::sum_proper_divisors(i) > i)
            abundant[i] = true;
    }

    std::vector<bool> reachable(abundant.size() * abundant.size());
    for (uint64_t i = 0; i <= n; ++i) {
        for (uint64_t j = 0; ++j <= n;) {
            if (abundant[i] && abundant[j])
                reachable[i + j] = true;
        }
    }

    uint64_t r = 0;
    for (uint64_t i = 0; i <= n; ++i) {
        if (!reachable[i])
            r += i;
    }
    return r;
}

int main()
{
    std::cout << sum(28213) << std::endl;
}
