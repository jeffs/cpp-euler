/** @file 33.cpp Problem 33: Digit canceling fractions
 *
 * The fraction 49/98 is a curious fraction, as an inexperienced mathematician
 * in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which
 * is correct, is obtained by cancelling the 9s.

 * We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
 *
 * There are exactly four non-trivial examples of this type of fraction, less
 * than one in value, and containing two digits in the numerator and
 * denominator.
 *
 * If the product of these four fractions is given in its lowest common terms,
 * find the value of the denominator.
 */

/// @cond
#include <boost/multiprecision/cpp_int.hpp> // cpp_rational, denominator

#include <iostream> // cout
/// @endcond

using boost::multiprecision::cpp_rational;

bool equal(int n1, int d1, int n2, int d2)
{
    return d1 && d2 && cpp_rational(n1, d1) == cpp_rational(n2, d2);
}

int main()
{
    cpp_rational r = 1;
    for (int i = 10; i < 100; ++i) {
        for (int j = i + 1; j < 100; ++j) {
            if (i % 10 == 0 && j % 10 == 0)
                continue;   // Skip trivial examples.
            int a = i / 10, b = i % 10,
                c = j / 10, d = j % 10;
            if (       (b == d && equal(i, j, a, c))
                    || (b == c && equal(i, j, a, d))
                    || (a == d && equal(i, j, b, c))
                    || (a == c && equal(i, j, b, d)))
                r *= cpp_rational(i, j);
        }
    }
    std::cout << denominator(r) << std::endl;
}
