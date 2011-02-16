/** @file 35.cpp Problem 35: Circular primes
 *
 * The number, 197, is called a circular prime because all rotations of the
 * digits: 197, 971, and 719, are themselves prime.
 *
 * There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37,
 * 71, 73, 79, and 97.
 *
 * How many circular primes are there below one million?
 */

#include "factoring.hpp"    // identify_primes

/// @cond
#include <cassert>          // assert
#include <deque>            // deque
#include <iostream>         // cout
/// @endcond

/** Counts circular primes less than a specified `end` value. */
class counter {
    std::deque<int>     m_ds; // digits
    std::vector<bool>   m_p;  // prime

    /** Returns true if `n` is a circular prime. */
    bool circular(int n);

    /** Loads the base-10 digits of `n` into `m_ds`, most significant first. */
    void to_digits(int n);

    /** Moves the first digit of `m_ds` to the back; `d:ds -> ds ++ [d]`. */
    int rotate();

    /** Returns the number represented by `m_ds`. */
    int from_digits() const;

  public:

    /** Constructs a counter of primes up to `end`, exclusive. */
    counter(int end);

    /** Returns the number of circular primes less than `n`. */
    int operator()(int n);
};

bool counter::circular(int n)
{
    if (!m_p[n])
        return false;
    to_digits(n);
    for (auto i = m_ds.size(); --i;) {
        if (!m_p[rotate()])
            return false;
    }
    return true;
}

void counter::to_digits(int n)
{
    m_ds.clear();
    for (; n; n /= 10)
        m_ds.push_front(n % 10);
}

int counter::rotate()
{
    m_ds.push_back(m_ds.front());
    m_ds.pop_front();
    return from_digits();
}

int counter::from_digits() const
{
    int r = 0;
    for (int d : m_ds)
        r = r * 10 + d;
    return r;
}

counter::counter(int end)
{
    assert(end > 0);
    factoring::identify_primes(&m_p, end - 1);
}

int counter::operator()(int n)
{
    int r = 0;
    for (int i = 2; i < n; ++i) {
        if (circular(i))
            ++r;
    }
    return r;
}

int main()
{
    int n = 1'000'000;
    counter c(n);
    assert(c(100) == 13);
    std::cout << c(n) << std::endl;
}
