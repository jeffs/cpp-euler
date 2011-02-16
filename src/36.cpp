/** @file 36.cpp Problem 36: Double-base palindromes
 *
 * The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.
 *
 * Find the sum of all numbers, less than one million, which are palindromic in
 * base 10 and base 2.
 *
 * (Please note that the palindromic number, in either base, may not include
 * leading zeros.)
 */

#include "int_util.hpp" // palindrome

/// @cond
#include <iostream>     // cout
/// @endcond

using int_util::palindrome;

int main()
{
    uint64_t r = 0;
    for (uint64_t i = 1; i < 1'000'000; ++i) {
        if (palindrome(i) && palindrome(i, 2))
            r += i;
    }
    std::cout << r << std::endl;
}
