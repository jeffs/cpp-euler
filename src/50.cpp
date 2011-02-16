/** @file 50.cpp Problem 50: Consecutive prime sum
 *
 * The prime 41, can be written as the sum of six consecutive primes:
 *
 *      41 = 2 + 3 + 5 + 7 + 11 + 13
 *
 * This is the longest sum of consecutive primes that adds to a prime below
 * one-hundred.
 *
 * The longest sum of consecutive primes below one-thousand that adds to a
 * prime, contains 21 terms, and is equal to 953.
 *
 * Which prime, below one-million, can be written as the sum of the most
 * consecutive primes?
 */

#include "factoring.hpp"        // identify_primes

/// @cond
#include <cstdint>              // uint64_t
#include <iostream>             // cout
/// @encond

using std::uint64_t;

int main()
{
    uint64_t n = 1'000'000;

    std::vector<bool> prime;
    factoring::identify_primes(&prime, n - 1);

    // I tried several variations on both of the following loops, and the rest
    // were all slower than what follows.  Complicating loop tests costs time;
    // using intermediate variables costs time (for lack of registers?).  I'm
    // profiling on a 64-bit x86 chip.

    std::vector<uint64_t> sum{0, 2}; // sum of first *index* primes
    for (uint64_t i = 3; i < n; i += 2) {
        if (prime[i])
            sum.push_back(sum.back() + i);
    }

    uint64_t r = 0, d = 0;
    for (uint64_t j = sum.size(); --j;) {
        for (uint64_t i = 0; i < j; ++i) {
            uint64_t p = sum[j] - sum[i];
            if (p < n && prime[p] && (j - i) > d) {
                d = j - i;
                r = p;
            }
        }
    }
    std::cout << r << std::endl;
}
