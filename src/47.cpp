/** @file 47.cpp Problem 47: Distinct primes factors
 *
 * The first two consecutive numbers to have two distinct prime factors are:
 *
 *      14 = 2 × 7
 *      15 = 3 × 5
 *
 * The first three consecutive numbers to have three distinct prime factors
 * are:
 *
 *      644 = 2² × 7 × 23
 *      645 = 3 × 5 × 43
 *      646 = 2 × 17 × 19.
 *
 * Find the first four consecutive integers to have four distinct prime
 * factors. What is the first of these numbers?
 */

#include "factoring.hpp"    // prime_factor_unique

/// @cond
#include <iostream>         // cout
#include <vector>           // vector
/// @endcond

int main()
{
    uint64_t d = 5;
    std::vector<uint64_t> av, bv, cv, dv;
    factoring::prime_factor_unique(&av, d - 3);
    factoring::prime_factor_unique(&bv, d - 2);
    factoring::prime_factor_unique(&cv, d - 1);
    factoring::prime_factor_unique(&dv, d);

    while (    av.size() != 4
            || bv.size() != 4
            || cv.size() != 4
            || dv.size() != 4) {
        av = std::move(bv);
        bv = std::move(cv);
        cv = std::move(dv);

        dv.clear();
        factoring::prime_factor_unique(&dv, ++d);
    }

    std::cout << (d - 3) << std::endl;
}
