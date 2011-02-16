/** @file 38.cpp Problem 38: Pandigital multiples
 *
 * Take the number 192 and multiply it by each of 1, 2, and 3:
 *
 *      192 x 1 = 192
 *      192 x 2 = 384
 *      192 x 3 = 576
 *
 * By concatenating each product we get the 1 to 9 pandigital, 192384576. We
 * will call 192384576 the concatenated product of 192 and (1,2,3)
 *
 * The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4,
 * and 5, giving the pandigital, 918273645, which is the concatenated product
 * of 9 and (1,2,3,4,5).
 *
 * What is the largest 1 to 9 pandigital 9-digit number that can be formed as
 * the concatenated product of an integer with (1,2, ... , n) where n > 1?
 */

// At most eight values of n, 2 through 9, are worth considering; n < 2 is
// explicitly prohibited by the problem description, and n > 9 will produce a
// number that exceeds the specified (9-digit) length.
//
// Similarly, we can limit the values of the multiplicand `m` to those that
// produce 9-digit concatenated products.

#include "int_util.hpp"                         // pandigital

/// @cond
#include <boost/iterator/counting_iterator.hpp> // counting_iterator
#include <boost/multiprecision/cpp_int.hpp>     // cpp_int

#include <algorithm>                            // all_of
#include <iostream>                             // cout
#include <vector>
/// @endcond

using boost::make_counting_iterator;
using boost::multiprecision::cpp_int;
using int_util::length;
using int_util::pandigital;

cpp_int cat_prod(cpp_int const& m, std::vector<int> const& v)
{
    std::string s;
    for (auto const& x : v)
        s += cpp_int(m * x).str();
    return cpp_int(s);
}

int main()
{
    cpp_int r = 0;
    for (int n = 2; n <= 9; ++n) {
        std::vector<int> v(
                make_counting_iterator(1),
                make_counting_iterator(n + 1));
        cpp_int m = 1;
        auto p = cat_prod(m, v);
        while (p.str().size() < 9) {  // Skip products that are too short.
            ++m;
            p = cat_prod(m, v);
        }
        while (p.str().size() == 9) {
            if (p > r && pandigital(p))
                r = p;
            p = cat_prod(++m, v);
        }
    }
    std::cout << r << std::endl;
}
