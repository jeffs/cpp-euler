/** @file 46.cpp Problem 46: Goldbach's other conjecture
 *
 * It was proposed by Christian Goldbach that every odd composite number can be
 * written as the sum of a prime and twice a square.
 *
 *      9 = 7 + 2 x 1**2
 *      15 = 7 + 2 x 2**2
 *      21 = 3 + 2 x 3**2
 *      25 = 7 + 2 x 3**2
 *      27 = 19 + 2 x 2**2
 *      33 = 31 + 2 x 1**2
 *
 * It turns out that the conjecture was false.
 *
 * What is the smallest odd composite that cannot be written as the sum of a
 * prime and twice a square?
 */

#include "factoring.hpp"    // prime_predicate

/// @cond
#include <cmath>            // sqrt
#include <cassert>          // assert
#include <cstdint>          // uint64_t
#include <iostream>         // cout
/// @endcond

using factoring::prime_predicate;

using std::uint64_t;

factoring::prime_predicate prime;   // set

class prime_seq {
    std::vector<uint64_t> mutable m_known;
  public:

    /** Returns the nth prime.  `n` is 1-based; i.e., returns 2 if n == 1. */
    uint64_t operator[](uint64_t n) const;
};

uint64_t prime_seq::operator[](uint64_t n) const {

    // Until we t know the nth prime,
    //      find the next prime.
    // Return the nth prime.

    if (m_known.empty())        // Seqs are 1-based.
        m_known.push_back(1);   // Start looking after 1.

    for (uint64_t i = m_known.size(); i <= n; ++i) {
        uint64_t j = m_known.back();
        while (!prime(++j))
            ;
        m_known.push_back(j);
    }

    return m_known[n];
}

prime_seq primes;   // seq

class prime_src {
    uint64_t m_n = 0;
  public:
    uint64_t next() { return primes[++m_n]; }
};

bool even(uint64_t n)
{
    return n % 2 == 0;
}

bool square(uint64_t n)
{
    uint64_t q = std::sqrt(n);
    return q * q == n;
}

bool contra(uint64_t n)
{
    prime_src src;
    if (prime(n))
        return false;
    for (uint64_t p = src.next(); p < n; p = src.next()) {
        uint64_t d = n - p;
        if (even(d) && square(d / 2))
            return false;
    }
    return true;
}

int main()
{
    uint64_t n = 3;
    while (!contra(n))
        n += 2;
    std::cout << n << std::endl;
}
