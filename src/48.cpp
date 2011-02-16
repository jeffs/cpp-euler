/** @file 48.cpp Problem 48; Self powers
 *
 * The series, 1**1 + 2**2 + 3**3 + ... + 10**10 = 10405071317.
 *
 * Find the last ten digits of the series, 1**1 + 2**2 + 3**3 + ... + 1000**1000.
 */

#include "int_util.hpp"                         // pow

/// @cond
#include <boost/multiprecision/cpp_int.hpp>     // cpp_int
#include <iostream>                             // cout
/// @endcond

using boost::multiprecision::cpp_int;
using int_util::pow;

int main()
{
    cpp_int r = 0;
    for (cpp_int i = 1, e = 1000; i <= e; ++i)
        r += pow(i, i);
    auto s = r.str();
    std::cout << s.substr(s.size() - 10) << std::endl;;
}
