/** @file 4.cpp Problem 4: Largest palindrome product
 *
 * A palindromic number reads the same both ways.  The largest palindrome made
 * from the product of two 2-digit numbers is 9009 = 91 * 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include "int_util.hpp" // palindrome

/// @cond
#include <cassert>      // assert
#include <iostream>     // cout
#include <iterator>     // back_inserter
#include <string>       // string
/// @endcond

using int_util::palindrome;

int find(int n)
{
    int r = 0;
    for (int i = n; i--;) {
        for (int j = n; j--;) {
            int p = i * j;
            if (palindrome(p) && p > r)
                r = p;
        }
    }
    return r;
}

int main()
{
    assert(find(100) == 9009);
    std::cout << find(1000) << std::endl;
}
