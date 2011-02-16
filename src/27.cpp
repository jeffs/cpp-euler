/** @file 27.cpp Problem 27: Quadratic primes
 *
 * Euler discovered the remarkable quadratic formula:
 *
 *      n**2 + n + 41
 *
 * It turns out that the formula will produce 40 primes for the consecutive
 * values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is
 * divisible by 41, and certainly when n = 41, 41**2 + 41 + 41 is clearly
 * divisible by 41.
 *
 * The incredible formula  n**2 - 79n + 1601 was discovered, which produces 80
 * primes for the consecutive values n = 0 to 79. The product of the
 * coefficients, -79 and 1601, is -126479.
 *
 * Considering quadratics of the form:
 *
 *      n**2 + an + b, where |a| < 1000 and |b| < 1000
 *
 * where |n| is the modulus/absolute value of n
 * e.g. |11| = 11 and |-4| = 4
 *
 * Find the product of the coefficients, a and b, for the quadratic expression
 * that produces the maximum number of primes for consecutive values of n,
 * starting with n = 0.
 */

#include "factoring.hpp"    // prime_predicate

/// @cond
#include <cstdint>          // uint64_t
#include <iostream>         // cout
/// @endcond

using std::uint64_t;

int f(int a, int b, int n)
{
    return n * n + a * n + b;
}

int main()
{
    factoring::prime_predicate p;
    int ra = -1, rb = -1, rn = -1;
    for (int a = -1000; ++a < 1000;) {
        for (int b = -1000; ++b < 1000;) {
            int n = 0;
            while (p(f(a, b, n)))
                ++n;
            if (n > rn) {
                ra = a;
                rb = b;
                rn = n;
            }
        }
    }
    std::cout << (ra * rb) << std::endl;
}
