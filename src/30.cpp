/** @file 30.cpp Problem 30: Digit fifth powers
 *
 * Surprisingly there are only three numbers that can be written as the sum of
 * fourth powers of their digits:
 *
 *      1634 = 14 + 64 + 34 + 44
 *      8208 = 84 + 24 + 04 + 84
 *      9474 = 94 + 44 + 74 + 44
 *
 * As 1 = 14 is not a sum it is not included.
 *
 * The sum of these numbers is 1634 + 8208 + 9474 = 19316.
 *
 * Find the sum of all the numbers that can be written as the sum of fifth
 * powers of their digits.
 */

#include "int_util.hpp" // pow

/// @cond
#include <iostream>     // cout
/// @endcond

using int_util::pow;

/** Returns true if `n` equals the sum of the `p`th powers of its digits. */
bool pred(int n, int p)
{
    int sum = 0;
    for (int m = n; m; m /= 10)
        sum += pow(m % 10, p);
    return sum == n;
}

int main()
{
    // Consider seven-digit numbers.  The maximum sum of 5th powers of seven
    // digits is 7 * 9**5 == 413343, which is only six digits.  Thus, there
    // cannot be any seven-digit number fitting the problem description.  Nor
    // can there be any longer number, since the minimum value grows
    // exponentially with length, whereas the maximum sum of fifth powers grows
    // only linearly.  We may therefore confine our consideration to numbers
    // having six digits or fewer.

    int r = 0;
    for (int i = 2; i < 1'000'000; ++i) {  // skip 1, as in the example
        if (pred(i, 5))
            r += i;
    }
    std::cout << r << std::endl;
}
