/** @file 41.cpp Problem 41: Pandigital prime
 *
 * We shall say that an n-digit number is pandigital if it makes use of all the
 * digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is
 * also prime.
 *
 * What is the largest n-digit pandigital prime that exists?
 */

// The result must have at most 9 digits (since we're using base 10).  The
// following code checks each permutation of the 9 unique digits, then the
// lower 8, etc. -- thus iterating through all pandigital numbers -- filtering
// out non-primes.  Once the number of digits of the highest prime pandigital
// is determined, the maximum of all primes of that length is the result.

/// @cond
#include <cassert>          // assert
#include <algorithm>        // max_element
#include <iostream>         // cout
#include <string>           // string
#include <vector>           // vector
/// @endcond

bool prime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

/** Appends to `r` all `n`-digit prime, 1-to-`n` pandigital numbers. */
bool find(std::vector<int>* v, int n)
{
    assert(n < 10);
    bool r = false;
    std::string orig;
    while (n)
        orig.push_back('0' + n--);
    std::string s = orig;
    int i = stoi(s);
    do {
        if (prime(i)) {
            v->push_back(i);
            r = true;
        }
        std::next_permutation(begin(s), end(s));
        i = stoi(s);
    } while (s != orig);
    return r;
}

int main()
{
    std::vector<int> v;
    for (int i = 9; !find(&v, --i);) { }
    int r = *std::max_element(begin(v), end(v));
    std::cout << r << std::endl;
}
