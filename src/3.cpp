/** @file 3.cpp Problem 3: Largest prime factor
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 */

#include "factoring.hpp"

/// @cond
#include <algorithm>    // max_element
#include <cstdint>      // uint64_t
#include <iostream>     // cout
/// @endcond

using std::uint64_t;

int main()
{
    std::vector<uint64_t> ds;   // divisors
    factoring::prime_factor_unique(&ds, 600851475143ULL);
    std::cout << *std::max_element(ds.begin(), ds.end()) << std::endl;
}
