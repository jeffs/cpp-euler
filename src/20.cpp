/** @file 20.cpp Problem 20: Factorial digit sum
 *
 * n! means n x (n - 1) x ... x 3 x 2 x 1
 *
 * For example, 10! = 10 x 9 x ... x 3 x 2 x 1 = 3628800, and the sum of the
 * digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 *
 * Find the sum of the digits in the number 100!
 */

#include "cpp_int_util.hpp"                 // sum_digits

/// @cond
#include <boost/multiprecision/cpp_int.hpp> // cpp_int

#include <cassert>  // assert
#include <iostream> // cout
/// @endcond

using boost::multiprecision::cpp_int;

int sum(int n)
{
    cpp_int p = 1;
    for (int i = 2; i <= n; ++i)
        p *= i;
    return cpp_int_util::sum_digits(p);
}

int main()
{
    assert(sum(10) == 27);
    std::cout << sum(100) << std::endl;
}
