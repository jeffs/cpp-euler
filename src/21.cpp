/** @file 21.cpp Problem 21: Amicable numbers
 *
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n
 * which divide evenly into n).  If d(a) = b and d(b) = a, where a != b, then a
 * and b are an amicable pair and each of a and b are called amicable numbers.
 *
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44,
 * 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4,
 * 71 and 142; so d(284) = 220.
 *
 * Evaluate the sum of all the amicable numbers under 10000.
 */

#include "factoring.hpp"

/// @cond
#include <cassert>      // assert
#include <iostream>     // cout
#include <vector>       // vector
/// @endcond

using factoring::sum_proper_divisors;

int main()
{
    assert(sum_proper_divisors(220) == 284);
    assert(sum_proper_divisors(284) == 220);

    std::vector<int> d(10000);
    for (int a = 2; a < d.size(); ++a)
        d[a] = sum_proper_divisors(a);

    int r = 0;
    for (int a = 2; a < d.size(); ++a) {
        int b = d[a];
        if (a != b && d[b] == a)
            r += a;
    }
    std::cout << r << std::endl;
}
