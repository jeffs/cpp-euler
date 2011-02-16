/** @file 5.cpp Problem 5: Smallest multiple
 *
 * 2520 is the smallest number that can be divided by each of the numbers from
 * 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of the
 * numbers from 1 to 20?
 */

#include "factoring.hpp"    // prime_factor, pair_vector

/// @cond
#include <cassert>          // assert
#include <cstdint>          // uint64_t
#include <iostream>         // cout
#include <unordered_map>    // unordered_map
/// @endcond

using std::uint64_t;

uint64_t lcm(uint64_t n)
{
    // Prime factor each number i from 2 through n.  Track the maximum exponent
    // to which each factor must be raised to produce any number in the
    // sequence.  Finally, return the product of all factors raised to their
    // maximum exponents.

    std::unordered_map<uint64_t, uint64_t> powers;
    factoring::pair_vector                 current;

    for (uint64_t i = 2; i <= n; ++i) {

        current.clear();
        factoring::prime_factor(&current, i);

        for (auto const& item : current) {
            auto d = item.first;
            auto p = powers.find(d);
            if (p == powers.end())
                powers.emplace(d, item.second);
            else if (p->second < item.second)
                p->second = item.second;
        }
    }

    uint64_t r = 1;
    for (auto const& item : powers) {
        for (auto i = item.second; i--;)
            r *= item.first;
    }
    return r;
}

int main()
{
    assert(lcm(10) == 2520);
    std::cout << lcm(20) << std::endl;
}
