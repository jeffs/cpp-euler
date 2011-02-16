/** @file int_util.hpp Declares utilities for working with integers. */

#ifndef INCLUDED_INT_UTIL
#define INCLUDED_INT_UTIL

/// @cond
#include <cassert>          // assert
#include <algorithm>        // all_of
#include <climits>          // CHAR_MAX
#include <string>           // string
/// @endcond

namespace int_util {

/** Passes each digit of the base-`b` representation of `n` to `f`, in order of
 * increasing significance.  The behavior is undefined if `n` is negative.
 */
template<typename T, typename F>
void for_digits_le(T n, F f, int b =10);

/** Returns the number of digits in the base-`b` representation of `n`.  The
 * behavior is undefined if `n` is negative.
 */
template<typename T>
int length(T n, int b =10);

/** Returns true if the base-`b` representation of `n` equals itself reversed.
 * The behavior is undefined if `n` is negative.
 */
template<typename T>
bool palindrome(T const& n, int b =10);

/** Returns true if the concatenation of the base-10 representations of `x` and
 * all `xs` contains each digit in `[M, N]` exactly once.  The behavior is
 * undefined if `x` or any of `xs` is negative. Note that the order of digits
 * does not matter.
 */
template<int M =1, int N =9, typename T, typename... Ts>
bool pandigital(T x, Ts... xs);

/** Returns the result of raising `b` to exponent `p`.  The behavior is
 * undefined if either `b` or `p` is negative.
 */
template<typename B, typename P>
B pow(B b, P p);

}

template<typename T, typename F>
void int_util::for_digits_le(T n, F f, int b)
{
    assert(b > 1);
    if (!n) {
        f(T()); // zero
    } else {
        for (; n; n /= b)
            f(n % b);
    }
}

template<typename T>
int int_util::length(T n, int b)
{
    int r = 0;
    for_digits_le(n, [&](auto) { ++r; }, b);
    return r;
}

template<typename T>
bool int_util::palindrome(T const& n, int b)
{
    // Profiling suggests that string is 4x faster than vector for T = int.
    // So, we use a string.
    assert(b > 1);
    assert(b < CHAR_MAX);
    std::string ds;
    for_digits_le(n, [&ds](auto d) { ds.push_back(d); }, b);
    for (auto p = begin(ds), e = end(ds); p < e; ++p) {
        if (*p != *--e)
            return false;
    }
    return true;
}

template<int M, int N, typename T, typename... Ts>
bool int_util::pandigital(T x, Ts... xs)
{
    static_assert(N > 0, "numbers cannot be pandigital without digits");
    int q[N + 1] = { 0 };        // frequency of each digit
    for (T i : {x, xs...})
        for_digits_le(i, [&](T d) { ++q[static_cast<int>(d)]; });
    return std::all_of(q, q + M, [](int c) { return c == 0; })
        && std::all_of(q + M, q + N + 1, [](int c) { return c == 1; });
}

template<typename B, typename P>
B int_util::pow(B b, P p)
{
    if (!p)
        return 1;
    auto a = pow(b, P(p / 2));
    return p % 2 ? B(a * a * b) : B(a * a);
}

#endif
