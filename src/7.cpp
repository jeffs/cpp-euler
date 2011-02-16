/** @file 7.cpp Problem 7: 10001st prime
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
 * that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 */

#include "factoring.hpp"    // identify_primes

/// @cond
#include <cassert>          // assert
#include <cstdlib>          // size_t
#include <iostream>         // cout
/// @endcond

using std::size_t;

size_t nth_prime(size_t n)
{
    size_t m = n * 10;   // Start by guessing the nth prime's value.
    std::vector<bool> p;
    factoring::identify_primes(&p, m);
    size_t c = std::count(p.begin(), p.end(), true);
    while (c < n) {                             // Not enough?
        factoring::identify_primes(&p, m *= 2);    // Try twice as high.
        c = std::count(p.begin(), p.end(), true);
    }
    size_t r = 0, t = 0;
    while (t != n)
        t += p[++r];
    return r;
}

int main()
{
    assert(nth_prime(6) == 13);
    std::cout << nth_prime(10'001) << std::endl;
}
