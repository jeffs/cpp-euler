/** @file 32.cpp Problem 32: Pandigital products
 *
 * We shall say that an n-digit number is pandigital if it makes use of all the
 * digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1
 * through 5 pandigital.
 *
 * The product 7254 is unusual, as the identity, 39 x 186 = 7254, containing
 * multiplicand, multiplier, and product is 1 through 9 pandigital.
 *
 * Find the sum of all products whose multiplicand/multiplier/product identity
 * can be written as a 1 through 9 pandigital.
 *
 * HINT: Some products can be obtained in more than one way so be sure to only
 * include it once in your sum.
 */

// The number of digits in the product is either the sum of the digit counts
// of the multiplied values, or one less than this number.  Moreover, since
// multiplication is commutative, there is a left/right symmetry between
// the lengths of the multiplicand and multiplier.  We may therefore focus
// our attention on a subset of value lengths.

//      1    1   7   // no, 7 > 1 + 1
//      1    2   6   // no, 6 > 1 + 2
//      1    3   5   // no, 5 > 1 + 3
//      1    4   4   // ok, 4 = 1 + 4 - 1
//      1    5   3   // no, 3 < 1 + 5 - 1
//      ...

//      2    2   5   // no, 5 > 2 + 2
//      2    3   4   // ok, 4 = 2 + 3 - 1
//      2    4   3   // no, 3 < 2 + 4 - 1
//      ...

//      3    3   3   // no, 3 < 3 + 3 - 1
//      3    4   3   // no, 3 < 2 + 4 - 1
//      ...

//      4    4   1   // no, 1 < 4 + 4 - 1
//      ...

// The lengths of interest are:
//
//      1   4   4
//      2   3   4

#include "int_util.hpp"     // pandigital, pow

/// @cond
#include <algorithm>        // all_of
#include <numeric>          // accumulate
#include <iostream>         // cout
#include <unordered_set>    // unordered_set
/// @endcond

using int_util::pandigital;
using std::to_string;

/** Inserts in `r` all products of `m`-digit multiplicands and `n-digit`
 * multipliers having the property that the concatenation of the base-10
 * representations of the multiplicand, multiplier, and product is 1-to-9
 * pan-digital.
 */
void insert(std::unordered_set<uint64_t>* r, int m, int n)
{
    using int_util::pow; // disambiguate from ::pow defined in math.h
    for (uint64_t i = pow(10, m - 1), ie = pow(10, m); i < ie; ++i) {
        for (uint64_t j = pow(10, n - 1), je = pow(10, n); j < je; ++j) {
            uint64_t k = i * j;
            if (pandigital(i, j, k))
                r->insert(k);
        }
    }
}

int main()
{
    std::unordered_set<uint64_t> products;
    insert(&products, 1, 4);
    insert(&products, 2, 3);
    int r = std::accumulate(products.begin(), products.end(), 0);
    std::cout << r << std::endl;
}
