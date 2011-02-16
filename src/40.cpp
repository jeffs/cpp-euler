/* @file 40.cpp Problem 40: Champernowne's constant
 *
 * An irrational decimal fraction is created by concatenating the positive
 * integers:
 *
 *      0.123456789101112131415161718192021...
 *
 * It can be seen that the 12th digit of the fractional part is 1.
 *
 * If dn represents the nth digit of the fractional part, find the value of the
 * following expression.
 *
 *      d1 x d10 x d100 x d1000 x d10000 x d100000 x d1000000
 */

#include "int_util.hpp" // for_digits_le

/// @cond
#include <iostream>     // cout
#include <vector>       // vector
/// @endcond

using int_util::for_digits_le;

class digit_seq {
    int              m_count;
    std::vector<int> m_buffer;

    int next() {
        if (m_buffer.empty())
            for_digits_le(m_count++, [this](int d) { m_buffer.push_back(d); });
        int r = m_buffer.back();
        m_buffer.pop_back();
        return r;
    }

  public:

    digit_seq()
      : m_count(0) { }

    int skip(int n) {
        while (n--)
            next();
        return next();
    }

};

int main()
{
    digit_seq digits;
    int r = digits.skip(1);
    for (int s = 9, p = 6; p--; s *= 10)
        r *= digits.skip(s - 1);
    std::cout << r << std::endl;
}
