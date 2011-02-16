/** @file cpp_int_util.cpp Implements the corresponding header interface. */

#include "cpp_int_util.hpp"

int cpp_int_util::sum_digits(cpp_int const& n)
{
    int r = 0;
    for (char c : n.str())
        r += c - '0';
    return r;
}
