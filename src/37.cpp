/** @file 37.cpp Problem 37: Truncatable primes
 *
 * The number 3797 has an interesting property. Being prime itself, it is
 * possible to continuously remove digits from left to right, and remain prime
 * at each stage: 3797, 797, 97, and 7. Similarly we can work from right to
 * left: 3797, 379, 37, and 3.
 *
 * Find the sum of the only eleven primes that are both truncatable from left
 * to right and right to left.
 *
 * NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 */

#include "factoring.hpp"    // prime_predicate
#include "int_util.hpp"     // length, pow

/// @cond
#include <cstdint>          // uint64_t
#include <iostream>         // cout
/// @endcond

using int_util::length;
using int_util::pow;
using std::uint64_t;

factoring::prime_predicate prime;

bool truncatable_left(uint64_t n)
{
    assert(n);
    uint64_t d = pow(10, length(n) - 1);
    do {
        if (!prime(n))
            return false;
        n %= d;
        d /= 10;
    } while (n);
    return true;
}

bool truncatable_right(uint64_t n)
{
    assert(n);
    do {
        if (!prime(n))
            return false;
        n /= 10;
    } while (n);
    return true;
}

bool truncatable(uint64_t n)
{
    return truncatable_right(n) && truncatable_left(n);
}

int main()
{
    uint64_t const count = 11;    // given in problem description
    uint64_t const start = 11;    // since 2, 3, 5, and 7 don't count

    uint64_t r = 0;
    for (uint64_t i = start, c = 0; c < count; ++i, ++c) {
        while (!truncatable(i))
            ++i;
        r += i;
    }
    std::cout << r << std::endl;
}
