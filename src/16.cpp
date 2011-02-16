/** @file 16.cpp Problem 16: Power digit sum
 *
 * 2**15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *
 * What is the sum of the digits of the number 2**1000?
 */

#include "cpp_int_util.hpp"                 // sum_digits

/// @cond
#include <boost/multiprecision/cpp_int.hpp> // cpp_int

#include <iostream>                         // cout
/// @endcond

using boost::multiprecision::cpp_int;

int sum(int n)
{
    cpp_int i = 1;
    for (int p = 0; p < n; ++p)
        i *= 2;
    return cpp_int_util::sum_digits(i);
}

int main()
{
    assert(sum(15) == 26);
    std::cout << sum(1000) << std::endl;
}
