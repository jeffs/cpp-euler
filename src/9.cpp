/** @file 9.cpp Problem 9: Special Pythagorean triplet
 *
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 *
 *      a**2 + b**2 = c**2
 *
 * For example, 3**2 + 4**2 = 9 + 16 = 25 = 5**2.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

/// @cond
#include <iostream> // cout
/// @endcond

int product(int n)
{
    for (int a = 1; a < n; ++a) {
        for (int b = 1; b < n; ++b) {
            for (int c = 1; c < n; ++c) {
                if (a * a + b * b == c * c && a + b + c == n)
                    return a * b * c;
            }
        }
    }
    return -1;
}

int main()
{
    std::cout << product(1000) << std::endl;
}
