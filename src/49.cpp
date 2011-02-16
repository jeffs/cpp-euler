/** @file 49.cpp Problem 49: Prime permutations
 *
 * The arithmetic sequence, 1487, 4817, 8147, in which each of the terms
 * increases by 3330, is unusual in two ways: (i) each of the three terms are
 * prime, and, (ii) each of the 4-digit numbers are permutations of one
 * another.
 *
 * There are no arithmetic sequences made up of three 1-, 2-, or 3-digit
 * primes, exhibiting this property, but there is one other 4-digit increasing
 * sequence.
 *
 * What 12-digit number do you form by concatenating the three terms in this
 * sequence?
 */

#include "factoring.hpp"        // identify_primes

/// @cond
#include <iostream>             // cout
/// @encond

int digits(int n)
{
    return 1 << n / 1000 % 10
        |  1 << n /  100 % 10
        |  1 << n /   10 % 10
        |  1 << n        % 10;
}

int main()
{
    int m = 1001, n = 9999;     // first and last four-digit values
                                // (skip 1000 because it's obviously not prime)

    std::vector<bool> prime;
    factoring::identify_primes(&prime, n);

    for (int i = m; i <= n; ++i) {
        if (i == 1487) continue;            // skip the one we already know
        int t = (n - i) / 2;                // maximum stride size
        for (int s = 2; s <= t; s += 2) {   // step by 2; evens won't be prime
            int j = i + s, k = j + s;
            if (prime[i] && prime[j] && prime[k]) {
                int d = digits(i);
                if (digits(j) == d && digits(k) == d && i != 1487) {
                    std::cout << i << j << k << std::endl;
                    return 0;
                }
            }
        }
    }
}
