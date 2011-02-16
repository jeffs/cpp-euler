/** @file 26.cpp Problem 26: Reciprocal cycles
 *
 * A unit fraction contains 1 in the numerator. The decimal representation of
 * the unit fractions with denominators 2 to 10 are given:
 *
 *      1/2     =       0.5
 *      1/3     =       0.(3)
 *      1/4     =       0.25
 *      1/5     =       0.2
 *      1/6     =       0.1(6)
 *      1/7     =       0.(142857)
 *      1/8     =       0.125
 *      1/9     =       0.(1)
 *      1/10    =       0.1
 *
 * Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be
 * seen that 1/7 has a 6-digit recurring cycle.
 *
 * Find the value of d < 1000 for which 1/d contains the longest recurring
 * cycle in its decimal fraction part.
 */

/// @cond
#include <cassert>          // assert
#include <cstdint>          // uint64_t
#include <iostream>         // cout
#include <unordered_map>    // unordered_map
/// @endcond

using std::uint64_t;

/** Returns the cycle length for denominator `d`. */
uint64_t length(uint64_t d)
{
    // Do long division, mapping each numerator (`n`) to the number of digits
    // computed so far (`i`), until a cycle is detected.

    uint64_t n = 1, i = 0;
    std::unordered_map<uint64_t, uint64_t> seen;
    for (auto p = seen.end(); p == seen.end(); p = seen.find(n)) {
        seen.emplace(n, i++);
        n = (n - (n / d) * d) * 10;     // `n / d` is the next digit
    }
    return i - seen[n];
}

int main()
{
    assert(length(2) == 1); // ends in 0
    assert(length(6) == 1); // has non-repeating prefix
    assert(length(7) == 6); // has cycle length > 1

    uint64_t r = 0, m = 0;
    for (uint64_t d = 2; d < 1000; ++d) {
        auto n = length(d);
        if (n > m) {
            m = n;
            r = d;
        }
    }
    std::cout << r << std::endl;
}
